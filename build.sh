#!/bin/bash

pushd build

cmake -GNinja ..

ninja

cp src/library/libgeneric_library.a ../out
cp src/example/library_example ../out
cp test/library_test ../out

popd

cp -r src/library/assets out

# doxygen Doxyfile
