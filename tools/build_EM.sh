#!/bin/bash -x

cd build
CXX=em++ cmake ..
make -j7
make install
