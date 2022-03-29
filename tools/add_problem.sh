#!/bin/bash

NUM=$1

dir=src/problem_$NUM
tmp=$(mktemp)

mkdir $dir
cp tools/template.h $dir/problem_$NUM.h
cp tools/template.cpp $dir/problem_$NUM.cpp
cp tools/template.CMakeLists.txt $dir/CMakeLists.txt

sed -i 's/NUM/'$NUM'/' $dir/problem_$NUM.*

curl https://projecteuler.net/problem=$NUM > $tmp

#xmllint --html prob1.html --xpath "//h2" > prob1.h2
#sed -i 's/<h2>/# /' prob1.h2
#sed -i 's/<\/h2>//' prob1.h2

#xmllint --html prob1.html --xpath "//h3" > prob1.h3