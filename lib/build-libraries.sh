#!/usr/bin/bash

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")

sudo apt update && sudo apt upgrade -y

sudo apt install build-essential git -y

# raylib library dependencies
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev -y

# clone raylib
git clone https://github.com/Raysan5/raylib.git --recurse-submodules


# # build raylib

cd $BASEDIR/raylib/src

make PLATFORM=PLATFORM_DESKTOP

cp ./libraylib.a $BASEDIR/

cp ./raymath.h $BASEDIR/../include/
cp ./raylib.h $BASEDIR/../include/