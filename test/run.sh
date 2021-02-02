#!/bin/sh -e

BIN_DIR="$PWD"/build/src

for f in "$BIN_DIR"/problem_*
do
    cd "$f"
    echo "================"
    basename "$f"
    echo "================"
    "$f"/"$(basename "$f")"
    echo ""
done
