#!/bin/bash

cp -r src/library/assets ../out

pushd build

cmake -GNinja ..

ninja

cp src/library/libshvrd_library.a ../out
cp src/example/shvrd_example ../out
cp test/shvrd_test ../out

popd

cp -r src/library/assets out

# doxygen Doxyfile
