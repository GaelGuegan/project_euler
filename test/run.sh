#!/bin/sh

BIN_DIR="$PWD"/build/src

for f in "$BIN_DIR"/problem_*/problem_*
do
    echo "================"
    basename "$f"
    echo "================"
    "$f"
    echo ""
done
