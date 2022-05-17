#!/bin/bash

shopt -s extglob
cd build || exit
rm -r !(.gitignore)
