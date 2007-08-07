import cheese

def report_cheese(name, userdata):
    print "Found cheese:", name
    print "User data:", userdata

cheese.find(report_cheese, 'Bla ble!')

