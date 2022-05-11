#!/bin/bash -x

cd build || exit
cmake ..
make -j7
make install
