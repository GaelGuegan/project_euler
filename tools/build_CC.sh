#!/bin/bash -x

cd build
cmake ..
make -j7
make install
