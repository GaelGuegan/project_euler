#!/bin/bash

NUM=$1

dir=src/problem_$NUM
tmp=$(mktemp)
readme=$dir/README.md

mkdir $dir
cp tools/template.h $dir/problem_$NUM.h
cp tools/template.cpp $dir/problem_$NUM.cpp
cp tools/template.CMakeLists.txt $dir/CMakeLists.txt

sed -i 's/NUM/'$NUM'/' $dir/problem_$NUM.*

curl https://projecteuler.net/problem=$NUM > $tmp

xmllint --html $tmp --xpath "//h2" | sed 's/<h2>/# /' | sed 's/<\/h2>/\n/'  >> $readme
xmllint --html $tmp --xpath "//h3" | sed 's/<h3>/## /' | sed 's/<\/h3>/\n/'  >> $readme
xmllint --html $tmp --xpath "//p"  | sed 's/<p>//g' | sed 's/<br>/\n/g' | sed 's/<\/p>//g'  >> $readme
echo -e "\n" >> $readme
