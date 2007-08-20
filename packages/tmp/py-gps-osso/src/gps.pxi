# Source code from gps.py (osso-gpsd package)

import time, calendar, socket, sys, thread
#from math import *
NaN = 1e10

ONLINE_SET      = 0x00000001
TIME_SET        = 0x00000002
TIMERR_SET      = 0x00000004
LATLON_SET      = 0x00000008
ALTITUDE_SET    = 0x00000010
SPEED_SET       = 0x00000020
TRACK_SET       = 0x00000040
CLIMB_SET       = 0x00000080
STATUS_SET      = 0x00000100
MODE_SET        = 0x00000200
HDOP_SET        = 0x00000400
VDOP_SET        = 0x00000800
PDOP_SET        = 0x00001000
TDOP_SET        = 0x00002000
GDOP_SET        = 0x00004000
HERR_SET        = 0x00008000
VERR_SET        = 0x00010000
PERR_SET        = 0x00020000
SATELLITE_SET   = 0x00040000
SPEEDERR_SET    = 0x00080000
TRACKERR_SET    = 0x00100000
CLIMBERR_SET    = 0x00200000
DEVICE_SET      = 0x00400000
DEVICELIST_SET  = 0x00800000
DEVICEID_SET    = 0x01000000
ERROR_SET       = 0x02000000
CYCLE_START_SET = 0x04000000
FIX_SET         = (TIME_SET|MODE_SET|TIMERR_SET|LATLON_SET|HERR_SET|ALTITUDE_SET|VERR_SET|TRACK_SET|TRACKERR_SET|SPEED_SET|SPEEDERR_SET|CLIMB_SET|CLIMBERR_SET)

STATUS_NO_FIX = 0
STATUS_FIX = 1
STATUS_DGPS_FIX = 2
MODE_NO_FIX = 1
MODE_2D = 2
MODE_3D = 3
MAXCHANNELS = 12
SIGNAL_STRENGTH_UNKNOWN = NaN

NMEA_MAX = 82

GPSD_PORT = 2947

def isnan(x): return x > 1e9

class gpstimings:
    def __init__(self):
        self.sentence_tag = ""
        self.sentence_length = 0
        self.sentence_time = 0.0
        self.d_xmit_time = 0.0
        self.d_recv_time = 0.0
        self.d_decode_time = 0.0
        self.emit_time = 0.0
        self.poll_time = 0.0
        self.c_recv_time = 0.0
        self.c_decode_time = 0.0
    def d_received(self):
        if self.sentence_time:
            return self.d_recv_time + self.sentence_time
        else:
            return self.d_recv_time + self.d_xmit_time
    def collect(self, tag, length, sentence_time, xmit_time, recv_time, decode_time, poll_time, emit_time):
        self.sentence_tag = tag
        self.sentence_length = int(length)
        self.sentence_time = float(sentence_time)
        self.d_xmit_time = float(xmit_time)
        self.d_recv_time = float(recv_time)
        self.d_decode_time = float(decode_time)
        self.poll_time = float(poll_time)
        self.emit_time = float(emit_time)
    def __str__(self):
        return "%s\t%2d\t%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\n" \
               % (timings.sentence_tag,
                 timings.sentence_length,
                 timings.sentence_time,
                 timings.d_xmit_time, 
                 timings.d_recv_time,
                 timings.d_decode_time,
                 timings.poll_time,
                 timings.emit_time,
                 timings.c_recv_time,
                 timings.c_decode_time)

class gpsfix:
    def __init__(self):
        self.mode = MODE_NO_FIX
        self.time = NaN
        self.ept = NaN
        self.latitude = self.longitude = 0.0
        self.eph = NaN
        self.altitude = NaN         # Meters
        self.epv = NaN
        self.track = NaN            # Degrees from true north
        self.speed = NaN            # Knots
        self.climb = NaN            # Meters per second
        self.epd = NaN
        self.eps = NaN
        self.epc = NaN

class satellite:
    def __init__(self, PRN, elevation, azimuth, ss, used=None):
        self.PRN = PRN
        self.elevation = elevation
        self.azimuth = azimuth
        self.ss = ss
        self.used = used
    def __repr__(self):
        return "PRN: %3d  E: %3d  Az: %3d  Ss: %d Used: %s" % (self.PRN,self.elevation,self.azimuth,self.ss,"ny"[self.used])

class gpsdata:
    "Position, track, velocity and status information returned by a GPS."

    def __init__(self):
    # Initialize all data members
        self.online = 0             # NZ if GPS on, zero if not

        self.valid = 0
        self.fix = gpsfix()

        self.status = STATUS_NO_FIX
        self.utc = ""

        self.satellites_used = 0    # Satellites used in last fix
        self.pdop = self.hdop = self.vdop = 0.0

        self.epe = 0.0

        self.satellites = []        # satellite objects in view
        self.await = self.parts = 0

        self.gps_id = None
        self.driver_mode = 0
        self.profiling = False
        self.timings = gpstimings()
        self.baudrate = 0
        self.stopbits = 0
        self.cycle = 0
        self.mincycle = 0
        self.device = None
        self.devices = []

    def __repr__(self):
        st = ""
        st = st + ("Lat/lon:  %f %f\n" % (self.fix.latitude, self.fix.longitude))
        if isnan(self.fix.altitude):
            st = st + ("Altitude: ?\n")
        else:
            st = st + ("Altitude: %f\n" % (self.fix.altitude))
        if isnan(self.fix.speed):
            st = st + ("Speed:    ?\n")
        else:
            st = st + ("Speed:    %f\n" % (self.fix.speed))
        if isnan(self.fix.track):
            st = st + ("Track:    ?\n")
        else:
            st = st + ("Track:    %f\n" % (self.fix.track))
        st = st + ("Status:   STATUS_%s\n" %("NO_FIX","FIX","DGPS_FIX")[self.status])
        st = st + ("Mode:     MODE_"+("ZERO", "NO_FIX", "2D","3D")[self.fix.mode]+"\n")
        st = st + ("Quality:  %d p=%2.2f h=%2.2f v=%2.2f\n" % \
              (self.satellites_used, self.pdop, self.hdop, self.vdop))
        st = st + ("Y: %s satellites in view:\n" % len(self.satellites))
        for sat in self.satellites:
          st = st+("    " + repr(sat) + "\n")
        return st

class gps(gpsdata):
    "Client interface to a running gpsd instance."
    def __init__(self, host="localhost", port="2947", verbose=0):
        gpsdata.__init__(self)
        self.sock = None        # in case we blow up in connect
        self.sockfile = None
        self.connect(host, port)
        self.verbose = verbose
        self.raw_hook = None
        self.thread_hook = None
        self.thread_id = None

    def connect(self, host, port):
        """Connect to a host on a given port.

        If the hostname ends with a colon (`:') followed by a number, and
        there is no port specified, that suffix will be stripped off and the
        number interpreted as the port number to use.
        """
        if not port and (host.find(':') == host.rfind(':')):
            i = host.rfind(':')
            if i >= 0:
                host, port = host[:i], host[i+1:]
                try: port = int(port)
                except ValueError:
                    raise socket.error, "nonnumeric port"
        if not port: port = GPSD_PORT
        msg = "getaddrinfo returns an empty list"
        self.sock = None
        self.sockfile = None
        for res in socket.getaddrinfo(host, port, 0, socket.SOCK_STREAM):
            af, socktype, proto, canonname, sa = res
            try:
                self.sock = socket.socket(af, socktype, proto)
                self.sock.connect(sa)
                self.sockfile = self.sock.makefile()
            except socket.error, msg:
                self.close()
            continue
            break
        if not self.sock:
            raise socket.error, msg

    def set_raw_hook(self, hook):
        self.raw_hook = hook

    def __thread_poll(self):
        while True:
            st = self.poll()
            if st == -1:
                break
        thread.exit()

    def set_thread_hook(self, hook):
        self.thread_hook = hook
        self.thread_id = thread.start_new_thread(self.__thread_poll, ())

    def close(self):
        if self.sockfile:
            self.sockfile.close()
        if self.sock:
            self.sock.close()
        self.sock = None
        self.sockfile = None

    def __del__(self):
        self.close()

    def default(self, fields, i):
        if fields[i] == '?':
            return NaN
        else:
            return float(fields[i])

    def __unpack(self, buf):
    # unpack a daemon response into the instance members
        self.gps_time = 0.0
        fields = buf.strip().split(",")
        if fields[0] == "GPSD":
            for field in fields[1:]:
                if not field or field[1] != '=':
                    continue
                cmd = field[0]
                data = field[2:]
                if data[0] == "?":
                    continue
                if cmd in ('A', 'a'):
                    self.fix.altitude = float(data)
                    self.valid = self.valid | ALTITUDE_SET
                elif cmd in ('B', 'b'):
                    if data == '?':
                        self.baudrate = self.stopbits = 0
                        self.device = None
                    else:
                        (f1, f2, f3, f4) = data.split()
                        self.baudrate = int(f1)
                        self.stopbits = int(f4)
                elif cmd in ('C', 'c'):
                    if data == '?':
                        self.cycle = -1
                        self.device = None
                    elif len(data.split()) == 2:
                        (self.cycle, self.mincycle) = map(float, data)
                    else:
                        self.mincycle = self.cycle = float(data)
                elif cmd in ('D', 'd'):
                    self.utc = data
                    self.gps_time = isotime(self.utc)
                    self.valid = self.valid | TIME_SET
                elif cmd in ('E', 'e'):
                    parts = data.split()
                    (self.epe, self.fix.eph, self.fix.epv) = map(float, parts)
                    self.valid = self.valid | HERR_SET | VERR_SET | PERR_SET
                elif cmd in ('F', 'f'):
                    if data == '?':
                        self.device = None
                    else:
                        self.device = data
                elif cmd in ('I', 'i'):
                  if data == '?':
                      self.cycle = -1
                      self.gps_id = None
                  else:
                      self.gps_id = data
                elif cmd in ('K', 'K'):
                    if data == '?':
                        self.devices = None
                    else:
                        self.devices = data[1:].split()
                elif cmd in ('M', 'm'):
                    self.fix.mode = int(data)
                    self.valid = self.valid | mode_set
                elif cmd in ('N', 'n'):
                    if data == '?':
                        self.driver_mode = -1
                        self.device = None
                    else:
                        self.driver_mode = int(data)
                elif cmd in ('O', 'o'):
                    fields = data.split()
                    if fields[0] == '?':
                        self.fix.mode = MODE_NO_FIX
                    else:
                        self.timings.sentence_tag = fields[0]
                        self.fix.time = self.default(fields, 1)
                        self.fix.ept = self.default(fields, 2)
                        self.fix.latitude = self.default(fields, 3)
                        self.fix.longitude = self.default(fields, 4)
                        self.fix.altitude = self.default(fields, 5)
                        if not isnan(self.fix.altitude):
                            self.fix.mode = MODE_2D
                        else:
                            self.fix.mode = MODE_3D
                        self.fix.eph = self.default(fields, 6)
                        self.fix.epv = self.default(fields, 7)
                        self.fix.track = self.default(fields, 8)
                        self.fix.speed = self.default(fields, 9)
                        self.fix.climb = self.default(fields, 10)
                        self.fix.epd = self.default(fields, 11)
                        self.fix.eps = self.default(fields, 12)
                        self.fix.epc = self.default(fields, 13)
                        self.valid = self.valid | TIME_SET|TIMERR_SET|LATLON_SET|MODE_SET
                        if self.fix.mode == MODE_3D:
                            self.valid = self.valid | ALTITUDE_SET | CLIMB_SET
                        if self.fix.eph:
                            self.valid = self.valid | HERR_SET
                        if self.fix.epv:
                            self.valid = self.valid | VERR_SET
                        if not isnan(self.fix.track):
                            self.valid = self.valid | TRACK_SET | SPEED_SET
                        if self.fix.eps:
                            self.valid = self.valid | SPEEDERR_SET
                        if self.fix.epc:
                            self.valid = self.valid | CLIMBERR_SET
                elif cmd in ('P', 'p'):
                    (self.fix.latitude, self.fix.longitude) = map(float, data.split())
                    self.valid = self.valid | LATLON_SET
                elif cmd in ('Q', 'q'):
                    parts = data.split()
                    self.satellites_used = int(parts[0])
                    (self.pdop, self.hdop, self.vdop) = map(float, parts[1:])
                    self.valid = self.valid | HDOP_SET | VDOP_SET | PDOP_SET
                elif cmd in ('S', 's'):
                    self.status = int(data)
                    self.valid = self.valid | STATUS_SET
                elif cmd in ('T', 't'):
                    self.fix.track = float(data)
                    self.valid = self.valid | TRACK_SET
                elif cmd in ('U', 'u'):
                    self.fix.climb = float(data)
                    self.valid = self.valid | CLIMB_SET
                elif cmd in ('V', 'v'):
                    self.fix.speed = float(data)
                    self.valid = self.valid | SPEED_SET
                elif cmd in ('X', 'x'):
                    if data == '?':
                        self.online = -1
                        self.device = None
                    else:
                        self.online = float(data)
                        self.valid = self.valid | ONLINE_SET
                elif cmd in ('Y', 'y'):
                    satellites = data.split(":")
                    print satellites
                    prefix = satellites.pop(0).split()
                    self.timings.sentence_tag = prefix.pop(0)
                    self.timings.sentence_time = prefix.pop(0)
                    if self.timings.sentence_time != "?":
                        self.timings.sentence_time = float(self.timings.sentence_time)
                        d1 = int(prefix.pop(0))
                        newsats = []
                        for i in range(d1):
                            newsats.append(satellite(*map(int, satellites[i].split())))
                        self.satellites = newsats
                    self.valid = self.valid | SATELLITE_SET
                elif cmd in ('Z', 'z'):
                    self.profiling = (data[0] == '1')
                elif cmd == '$':
                    self.timings.collect(*data.split())
        if self.raw_hook:
            self.raw_hook(buf)
        if self.thread_hook:
            self.thread_hook(buf)

    def poll(self):
    #"Wait for and read data being streamed from gpsd."
        self.response = self.sockfile.readline()
        if not self.response:
            return -1
        if self.verbose:
            sys.stderr.write("GPS DATA %s\n" % repr(self.response))
        self.timings.c_recv_time = time.time()
        self.__unpack(self.response)
        if self.profiling:
            if self.timings.sentence_time != '?':
                basetime = self.timings.sentence_time
            else:
                basetime = self.timings.d_xmit_time
                self.timings.c_decode_time = time.time() - basetime
                self.timings.c_recv_time = self.timings.c_recv_time - basetime
        return 0

    def query(self, commands):
    #"Send a command, get back a response."
        self.sockfile.write(commands)
        self.sockfile.flush()
        return self.poll()

    def getposition(self):
        self.query('p'+'\n')
        return (self.fix.latitude, self.fix.longitude)

    def updatefix(self):
        return self.query('o'+'\n')

def isotime(s):
    "Convert timestamps in ISO8661 format to and from Unix time."
    if type(s) == type(1):
        return time.strftime(time.gmtime(s), "%Y-%m-%dT%H:%M:%S")
    elif type(s) == type(1.0):
        date = int(s)
        msec = s - date
        date = time.strftime("%Y-%m-%dT%H:%M:%S", time.gtime(s))
        return date + "." + `msec`[2:]
    elif type(s) == type(""):
        if s[-1] == "Z":
            s = s[:-1]
        if "." in s:
            (date, msec) = s.split(".")
        else:
            date = s
            msec = "0"
        # Note: no leap-second correction!
        return calendar.timegm(time.strptime(date, "%Y-%m-%dT%H:%M:%S")) + float("0." + msec)
    else:
        raise TypeError
