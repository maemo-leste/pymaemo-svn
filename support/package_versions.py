#!/usr/bin/env python
# Print a version table for packages in a .ini file

from ConfigParser import ConfigParser
from subprocess import Popen, PIPE, call
import urllib
import sys

def version_cmp(a, b):
    if call(["dpkg", "--compare-versions", a, "eq", b]) == 0:
        return 0
    if call(["dpkg", "--compare-versions", a, "gt", b]) == 0:
        return 1
    return -1

def latest_versions(url, wanted=None):
    print >>sys.stderr, "Downloading %s..." % url
    srcf = urllib.urlopen(url)
    # bz2.BZ2File lacks fileno() method, so we can't use it directly with subprocess.Popen
    p1 = Popen(["bzip2", "-d"], stdin=srcf, stdout=PIPE)
    p2 = Popen(["awk", "/^Package:/{p=$2} /^Version:/{print p,$2}"], stdin=p1.stdout, stdout=PIPE)
    packages = {}
    for line in p2.stdout:
        line = line.strip().split(" ")
        pkg, ver = line
        if wanted and pkg not in wanted:
            continue
        if pkg not in packages:
            packages[pkg] = []
        packages[pkg].append(ver)
    srcf.close()

    # get latest version number of each package
    for p in packages.keys():
        packages[p].sort(version_cmp, reverse=True)
        packages[p] = packages[p][0]

    return packages

def longest(list):
    """Calculate the length of the longest string in a list."""
    return reduce(lambda x, y: len(y) if len(y) > x else x, list, 0)

def format_string(field_size, ncols):
    return " ".join(["%%-%ds" % field_size] * ncols)

def compare(*args):
    header = ["Package"] + [x[0] for x in args]
    names = args[0][1].keys()
    names.sort()
    field_size = longest(names)
    format = format_string(field_size, len(args) + 1)
    print format % tuple(header)
    for n in names:
        line = [n]
        for x in args:
            line.append(x[1].get(n) if x[1].get(n) else "-")
        print format % tuple(line)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print >>sys.stderr, "Usage: %s <packages.ini>" % sys.argv[0]
        sys.exit(1)
    filename = sys.argv[1]
    pkgs = ConfigParser()
    pkgs.read(filename)
    maemo_devel = latest_versions("http://repository.maemo.org/extras-devel/dists/fremantle/free/source/Sources.bz2", pkgs.sections())
    maemo_testing = latest_versions("http://repository.maemo.org/extras-testing/dists/fremantle/free/source/Sources.bz2", pkgs.sections())
    maemo = latest_versions("http://repository.maemo.org/extras/dists/fremantle/free/source/Sources.bz2", pkgs.sections())
    #debian_stable = latest_versions("http://ftp.debian.org/debian/dists/stable/main/source/Sources.bz2", pkgs.sections())
    #debian_stable.update(latest_versions("http://security.debian.org/dists/stable/updates/main/source/Sources.bz2", pkgs.sections()))
    #debian_testing = latest_versions("http://ftp.debian.org/debian/dists/testing/main/source/Sources.bz2", pkgs.sections())
    #debian_testing.update(latest_versions("http://security.debian.org/dists/testing/updates/main/source/Sources.bz2", pkgs.sections()))
    compare(("extras-devel", maemo_devel), ("extras-testing", maemo_testing), ("extras", maemo))
