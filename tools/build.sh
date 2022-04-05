#!/bin/bash 

cd build
cmake ..
make -j7
make install
