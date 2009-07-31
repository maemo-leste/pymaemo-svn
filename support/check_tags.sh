#!/bin/bash
# vim: ts=4 sw=4 et ai sta
# Check which package releases were uploaded to Maemo extras, but do not have
# release tags.
# It must be run from a git-svn copy of the PyMaemo tree.
set -e -u

if [ ! -d packages/ -o ! -d .git/ -o ! -d .git/svn/ ]; then
    echo "ERROR: this script must be run from a PyMaemo git-svn repository" >&2
    exit 1
fi

tempdir=$(mktemp -d)
trap "echo Removing temporary directory... >&2; rm -rf $tempdir" EXIT
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
    commits=$(git log --pretty=oneline $new | awk '{print $1}')
    git log --pretty=oneline $new | awk '{print $1}' | while read c; do
        #echo "Trying commit $c..." >&2
        git archive $c $new | tar -C $tempdir -xf-
        if diff -qr $old $tempdir/$new >/dev/null; then
            echo $c
            break
        fi
    done
    rm -rf $src_dir $tempdir/packages
}

wget -P $tempdir http://repository.maemo.org/extras-devel/dists/fremantle/free/source/Sources.bz2
for d in packages/*/trunk/debian/; do
    pkg=$(basename $(readlink -f $d/../../))
    bzcat $tempdir/Sources.bz2 | grep-dctrl -XnSs Version $pkg | while read v; do
        if [ ! -d "packages/$pkg/tags/$v" ]; then
            echo "ERROR: $pkg: tag for version \"$v\" does not exist" >&2
            dsc_url=$(find_dsc_url http://repository.maemo.org/extras-devel $tempdir/Sources.bz2 $pkg $v)
            c=$(find_commit $pkg $v $dsc_url)
            if [ -z "$c" ]; then
                echo "ERROR: commit not found for $pkg ($v)" >&2
            else
                rev=$(git log -n1 $c | awk '/git-svn-id:/{print $2}' | cut -d@ -f2)
                echo "svn cp -r $rev packages/$pkg/trunk packages/$pkg/tags/$v"
                echo "svn commit -m \"$pkg: tag release $v\" packages/$pkg/tags/$v"
            fi
        fi
    done
done
