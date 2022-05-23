#!/bin/bash -x

cd build || exit
CXX=g++ cmake ..
make -j7
make install
