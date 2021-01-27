#!/bin/sh -e

BIN_DIR="$PWD"/build/src

for f in "$BIN_DIR"/problem_*/problem_*
do
    echo -e "\e[32m================"
    basename "$f"
    echo -e "================\e[39m"
    "$f"
    echo ""
done
