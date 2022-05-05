#!/bin/bash -x

cd build
CXX=clang++ cmake ..
make -j7
make install
