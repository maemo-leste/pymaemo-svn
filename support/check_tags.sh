#!/bin/bash
# vim: ts=4 sw=4 et ai sta
set -e -u

if [ ! -d packages/ ]; then
    echo "ERROR: this script must be run from PyMaemo repository"
    exit 1
fi

tempdir=$(mktemp -d)
trap "echo Removing temporary directory...; rm -rf $tempdir" EXIT
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

    if [ ! -f "${pkg}_${ver}.dsc" ]; then
        (cd $tempdir && dget -u $dsc_url)
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
    commits=$(git log --pretty=oneline $new | awk '{print $1}')
    commit=""
    git log --pretty=oneline $new | awk '{print $1}' | while read c; do
        git checkout $c 2>/dev/null
        if diff -qr $old $new 2>/dev/null; then
            echo "COMMIT FOUND: $c"
            break
        fi
    done
    git checkout master

    rm -rf $src_dir
}

wget -P $tempdir http://repository.maemo.org/extras-devel/dists/fremantle/free/source/Sources.bz2
#for d in packages/*/; do
for d in packages/python-hildon/; do
    pkg=$(basename $d)
    bzcat $tempdir/Sources.bz2 | grep-dctrl -XnSs Version $pkg | while read v; do
        if [ ! -d "packages/$pkg/tags/$v" ]; then
            echo "ERROR: $pkg: tag for version \"$v\" does not exist"
            dsc_url=$(find_dsc_url http://repository.maemo.org/extras-devel $tempdir/Sources.bz2 $pkg $v)
            find_commit $pkg $v $dsc_url
        fi
    done
done
