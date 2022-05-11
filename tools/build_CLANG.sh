#!/bin/bash -x

cd build || exit
CXX=clang++ cmake ..
make -j7
make install
