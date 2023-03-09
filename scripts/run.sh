#!/usr/bin/env bash

set -eo pipefail

# The program to compile and run
PNAME=${1%.cpp}

# Compile the program
g++ -g3 -o3 -Wall -Werror -pipe "$1" -o "${PNAME}.o"

# Run with input
"./${PNAME}.o" < "in-${PNAME}"