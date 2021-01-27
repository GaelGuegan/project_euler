#!/bin/sh

TOP_DIR="$PWD"/..
BIN_DIR="$TOP_DIR"/build/src

for f in "$BIN_DIR"/problem_*/problem_*
do
    echo "================"
    basename "$f"
    echo "================"
    "$f"
    echo ""
done
