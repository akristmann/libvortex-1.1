#!/bin/sh

set -x

echo "Preparing sources"
rm -f rpm/SOURCES/*.tar.gz
rm -f rpm/BUILD/*
make dist
cp vortex-`cat VERSION`.tar.gz rpm/SOURCES/

echo "Calling to compile packages.."
LANG=C rpmbuild -ba --define '_topdir /usr/src/libvortex-1.1/rpm' rpm/SPECS/vortex.spec

echo "Output ready at rpm/RPMS"
find rpm/RPMS -type f

