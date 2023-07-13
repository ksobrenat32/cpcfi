#!/usr/bin/env bash

set -eo pipefail

# The program to compile and run
PNAME=${1%.cpp}

# Compile the program ignoring errors
if [[ $2 == --no-error ]]; then
    g++ -std=c++17 -o3 -pipe "$1" -o "${PNAME}.o"
else 
    g++ -std=c++17 -g3 -o3 -Wall -Werror -pipe "$1" -o "${PNAME}.o"
fi

# Run input with time
if [[ $2 == time ]]; then
    time "./${PNAME}.o" < "in-${PNAME}"
else 
    "./${PNAME}.o" < "in-${PNAME}"
fi