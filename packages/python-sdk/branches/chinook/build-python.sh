#!/bin/sh

# Keep these equal to 'create_tree.py' script
SOURCES_DIR="source_packages"
DEBS_DIR="deb_packages"
QUILTRC="../.quiltrc"
TMP_DIR="$SOURCES_DIR/tmp_dir/"

OLD_NAME="Python-2.5.2"
SRC_URL="http://www.python.org/ftp/python/2.5.2/$OLD_NAME.tgz"
SVN_URL="https://garage.maemo.org/svn/pymaemo/packages/python/branches/chinook/debian/"

ORIGFILE_NAME="python2.5_2.5.2.orig.tar.gz"
PKGNAME="python2.5-2.5.2"

echo "** Getting $PKGNAME **"
if [ -f "$ORIGFILE_NAME" ]; then
    echo "$PKGNAME already downloaded."
else
    # FIXME: Actually the '-c' option is useless in this if statement.
    wget -c $SRC_URL -O $ORIGFILE_NAME
    tar xvf $ORIGFILE_NAME
    mv $OLD_NAME $PKGNAME
fi

cd $PKGNAME

echo
echo "** Getting debian directory **"
if [ -d "debian" ]; then
    echo "debian directory already here."
else
    svn checkout $SVN_URL
fi

echo
echo "** Applying patches **"
quilt pop -a --quiltrc $QUILTRC $PKGNAME
quilt push -a --quiltrc $QUILTRC $PKGNAME

echo
echo "** Installing build dependencies **"
# Taken from python2.5 debian/control file. Not very automatic but works.
fakeroot apt-get --yes --force-yes install \
                 debhelper autoconf zlib1g-dev libssl-dev \
                 libbz2-dev libsqlite3-dev dpatch libffi4-dev \
                 libgdbm-dev libreadline4-dev libbluetooth2-dev

echo
echo "** Build Debian pagkage **"
ARCH=`dpkg-architecture -qDEB_BUILD_ARCH`
if [ "$ARCH" = "armel" ]; then
    dpkg-buildpackage -rfakeroot -sa -tc -I.pc -i.pc -us -uc
else
    dpkg-buildpackage -rfakeroot -B -sa -tc -I.pc -i.pc -us -uc
fi

echo
echo "** Installing Debian packages **"
cd ..
dpkg -i `ls *_$ARCH.deb`

echo
echo "Python 2.5 is built and installed."
echo "Run create_tree.py now to create the other packages."
echo


