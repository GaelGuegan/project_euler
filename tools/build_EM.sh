#!/bin/bash -x

cd build || exit
CXX=em++ cmake ..
make -j7
make install
