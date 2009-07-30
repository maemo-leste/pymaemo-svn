import subprocess
import sys
import ConfigParser
import os.path
import re

if len(sys.argv) != 2:
    print "Usage: %s <file.ini>" % sys.argv[0]
    sys.exit(1)

filename = sys.argv[1]
config = ConfigParser.ConfigParser()
config.read(filename)

# binary -> source package mapping
packages = {}

# build dependencies for a source package
build_deps = {}

def parse_deps(ctrl, pkg, field):
    output = subprocess.Popen(["grep-dctrl", "-enSs", field, pkg, ctrl],
                               stdout=subprocess.PIPE,
                               stderr=sys.stderr).communicate()[0]
    if not output.strip():
        return []

    deps = map(str.strip, output.split(","))
    # FIXME: ignore versions for now
    deps = map(lambda x: re.sub(" \([^\)]+\)$", "", x), deps)
    return deps

def list_packages(ctrl):
    output = subprocess.Popen(["grep-dctrl", "-enPs", "Package", ".+", ctrl],
                               stdout=subprocess.PIPE).communicate()
    return output[0].strip().split("\n")

src_packages = set([])
for s in config.sections():
    ctrl = "packages/%s/trunk/debian/control" % s
    if not os.path.exists(ctrl):
        print >>sys.stderr, "control file \"%s\" not found, skipping" % ctrl
        continue
    src_packages.add(s)

for s in src_packages:
    ctrl = "packages/%s/trunk/debian/control" % s
    for p in list_packages(ctrl):
        packages[p] = s

for s in src_packages:
    ctrl = "packages/%s/trunk/debian/control" % s
    deps = parse_deps(ctrl, s, "Build-Depends")
    deps += parse_deps(ctrl, s, "Build-Depends-Indep")
    build_deps[s] = map(packages.get, deps)
    build_deps[s] = filter(lambda x: x, build_deps[s])

pipe = subprocess.Popen(["tsort"], stdin=subprocess.PIPE,
                        stdout=subprocess.PIPE)
for (p, deps) in build_deps.iteritems():
    for d in deps:
        print >>pipe.stdin, "%s %s" % (d, p)
        src_packages.discard(d)
        src_packages.discard(p)
for p in src_packages:
    print p
print pipe.communicate()[0].strip()
