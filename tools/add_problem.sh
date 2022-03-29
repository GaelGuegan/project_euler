#!/bin/bash

NUM=$1

mkdir src/problem_$NUM
cp tools/template.h src/problem_$NUM.h
cp tools/template.cpp src/problem_$NUM.cpp

sed -i '"s/NUM/$NUM/' src/problem_$NUM.*

curl https://projecteuler.net/problem=$NUM
