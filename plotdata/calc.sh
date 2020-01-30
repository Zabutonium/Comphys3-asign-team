#!/bin/sh
rm -f plot_*.dat

g++ GenerateInitial_circle.cpp -o GenerateInitial_circle.out -std=c++11
echo "GenerateInitial_grid.cpp has been compiled successfully."

./GenerateInitial_circle.out 
echo "GenerateInitial_grid.out has runnned."

g++ mainplot.cpp -o mainplot.out -std=c++11
echo "main.cpp has been compiled successfully."

./mainplot.out
echo "main.out has runned."

gnuplot