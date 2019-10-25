#!/bin/bash

# fetch dependencies if not already existent
if [[ ! -d "dependencies" ]]; then
    mkdir dependencies
fi

pushd dependencies

wget https://raw.githubusercontent.com/PixarAnimationStudios/OpenSubdiv/master/cmake/FindGLFW.cmake
wget https://raw.githubusercontent.com/Groovounet/glm-deprecated/master/util/FindGLM.cmake

git clone https://github.com/Crascit/DownloadProject.git

popd


# create build directories
if [[ ! -d "build" ]]; then
    mkdir build
fi

if [[ ! -d "out" ]]; then
    mkdir out
fi
