#!/bin/sh
rm -f plot_i=*.dat

g++ GenerateInitial_circle.cpp -o GenerateInitial_circle.out
echo "GenerateInitial_grid.cpp has been compiled successfully."

./GenerateInitial_circle.out
echo "GenerateInitial_grid.out has runnned."

g++ mainplot.cpp -o mainplot.out
echo "main.cpp has been compiled successfully."

./main.out
echo "main.out has runnsed."