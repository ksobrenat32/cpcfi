#!/usr/bin/env bash

set -eo pipefail

# The program to compile and run
PNAME=${1%.cpp}

# Compile the program
if [[ $2 == no ]]; then
    g++ -o3 -pipe "$1" -o "${PNAME}.o"
else 
    g++ -g3 -o3 -Wall -Werror -pipe "$1" -o "${PNAME}.o"
fi


# Run with input
if [[ $2 == time ]]; then
    time "./${PNAME}.o" < "in-${PNAME}"
else 
    "./${PNAME}.o" < "in-${PNAME}"
fi