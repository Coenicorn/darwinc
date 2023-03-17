#!/usr/bin/bash

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")

rm -rf $BASEDIR/include/*.h
rm -rf $BASEDIR/lib/*.a