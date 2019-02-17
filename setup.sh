#!/bin/bash

# fetch dependencies if not already existent
if [[ ! -d "dependencies" ]]; then
    mkdir dependencies

    pushd dependencies

    wget https://raw.githubusercontent.com/PixarAnimationStudios/OpenSubdiv/master/cmake/FindGLFW.cmake
    git clone https://github.com/Crascit/DownloadProject.git

    popd
fi

# create build directories
if [[ ! -d "build" ]]; then
    mkdir build
fi

if [[ ! -d "out" ]]; then
    mkdir out
fi

# execute first time build
sh build.sh
