#!/bin/bash

~/.local/bin/cpplint src/problem_*/*{cpp,h}
~/.local/bin/yamllint .github/workflows/*
