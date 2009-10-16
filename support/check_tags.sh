#!/bin/bash
# vim: ts=4 sw=4 et ai sta
# Check which package releases were uploaded to Maemo extras, but do not have
# release tags.
# It must be run from a git-svn copy of the PyMaemo tree.
#
# Usage:
# ./check_tags.sh > /tmp/commands.txt
#
# A lot of debugging information will be shown on screen, but /tmp/commands.txt
# will contain the SVN commands necessary to create the tags (if any). Then, to
# run the commands, you can use:
#
# bash -x -e /tmp/commands.txt
#
# Thils will print the commands as they are run, and stop execution on first
# error.
set -e -u

# These versions do not have a matching SVN commit
ignore_versions=$(cat << EOF
dbus-python_0.83.0-1maemo2
gst0.10-python_0.10.14-2maemo1
gst0.10-python_0.10.14-2maemo2
pygame_1.8.1release-0maemo2
pygobject_2.14.2-1maemo4
pygtk_2.12.1-6maemo6
pyrex_0.9.7.2-0.1maemo2
sdl-ttf2.0_2.0.9-1maemo1
EOF)

if [ ! -d packages/ -o ! -d .git/ -o ! -d .git/svn/ ]; then
    echo "ERROR: this script must be run from a PyMaemo git-svn repository" >&2
    exit 1
fi

tempdir=$(mktemp -d)
trap "echo Removing temporary directory... >&2; rm -rf $tempdir; echo -en '\e[m' >&2" EXIT
trap "exit 1" INT

function find_dsc_url()
{
    url=$1
    index=$2
    pkg=$3
    ver=$4
    dir=$(bzcat $index | grep-dctrl -XnSs Directory $pkg | head -n1)
    echo "$url/$dir/${pkg}_${ver}.dsc"
}

function find_commit()
{
    pkg=$1
    ver=$2
    dsc_url=$3

    if [ ! -f $tempdir/${pkg}_${ver}.dsc ]; then
        echo "Downloading source for $pkg ($ver)..." >&2
        (cd $tempdir && dget -q -u $dsc_url &>/dev/null)
    fi

    src_dir=$(ls -d $tempdir/*/ | head -n1) && test -n "$src_dir"
    if [ -n "$(find packages/$pkg/trunk/ -mindepth 1 -maxdepth 1 -not -name debian)" ]; then
        # native package (i.e. package entirely in the repository)
        old=$src_dir
        new=packages/$pkg/trunk
    else
        old=$src_dir/debian
        new=packages/$pkg/trunk/debian
    fi
    CON="\e[33;1m"
    COFF="\e[m"
    svn_dirs=$(find $old -name .svn -type d)
    if [ -n "$svn_dirs" ]; then
        echo -e "${CON}WARNING: .svn directories found in $pkg ($ver)${COFF}" >&2
        rm -rf $svn_dirs
    fi
    commits=$(git log --pretty=oneline $new | awk '{print $1}')
    # generate a ignore list for diff
    for f in missing ltmain.sh Makefile.in install-sh depcomp configure \
        config.sub config.h.in config.guess compile aclocal.m4; do
        echo $f >> $tempdir/ignore.txt
    done
    git log --pretty=oneline $new | awk '{print $1}' | while read c; do
        #echo "Trying commit $c..." >&2
        git archive $c $new | tar -C $tempdir -xf-
        svn_dirs=$(find $tempdir/$new -name .svn -type d)
        if [ -n "$svn_dirs" ]; then
            echo -e "${CON}WARNING: .svn directories found in git-svn commit $c: $pkg ($ver)${COFF}" >&2
            rm -rf $svn_dirs
        fi
        has_diff=0
        if ! diff -qr $old $tempdir/$new >/dev/null; then
            has_diff=1
        fi
        if diff -X$tempdir/ignore.txt -qr $old $tempdir/$new >/dev/null; then
            if [ $has_diff -eq 1 ]; then
                echo -e "${CON}WARNING: source probably not properly cleaned up for $pkg ($ver)${COFF}" >&2
            fi
            echo $c
            break
        fi
        rm -rf $tempdir/$new
    done
    rm -rf $src_dir $tempdir/packages
}

wget --no-cache -P $tempdir http://repository.maemo.org/extras-devel/dists/fremantle/free/source/Sources.bz2

if [ $# -ne 0 ]; then
    dirs=$(for p in $@; do echo packages/$p/trunk/debian/; done)
else
    dirs=$(ls -d packages/*/trunk/debian/)
fi
for d in $dirs; do
    pkg=$(basename $(readlink -f $d/../../))
    bzcat $tempdir/Sources.bz2 | grep-dctrl -XnSs Version $pkg | while read v; do
        if [ ! -d "packages/$pkg/tags/$v" ]; then
            echo "ERROR: $pkg: tag for version \"$v\" does not exist" >&2
            dsc_url=$(find_dsc_url http://repository.maemo.org/extras-devel $tempdir/Sources.bz2 $pkg $v)
            c=$(find_commit $pkg $v $dsc_url)
            if [ -z "$c" ]; then
                CON="\e[31;1m"
                COFF="\e[m"
                if ! grep -qw "${pkg}_${v}" <<< $ignore_versions; then
                    echo -e "${CON}ERROR: commit not found for $pkg ($v)${COFF}" >&2
                fi
            else
                rev=$(git log -n1 $c | awk '/git-svn-id:/{print $2}' | cut -d@ -f2)
                echo "svn cp -r $rev packages/$pkg/trunk packages/$pkg/tags/$v"
                echo "svn commit -m \"$pkg: tag release $v\" packages/$pkg/tags/$v"
            fi
        fi
    done
done
