#!/usr/bin/env bash

# The program you are working with
PNAME=${1}

# Create main program from template
cp "$(git rev-parse --show-toplevel)/template.cpp" "${PNAME}.cpp"

# Create main program input
touch "in-${PNAME}"