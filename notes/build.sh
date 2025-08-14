#!/bin/bash

# Generate PDF in mini book format (letter size, landscape, compact layout)
pandoc --pdf-engine=xelatex \
       -V geometry:paper=letterpaper \
       -V geometry:margin=0.75cm \
       -V fontsize=10pt \
       *.md -o notes.pdf
