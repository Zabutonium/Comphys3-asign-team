#!/bin/sh
g++ GenerateInitial_grid.cpp -o GenerateInitial_grid.out -std=c++11
echo "GenerateInitial_grid.cpp has been compiled successfully."

./GenerateInitial_grid.out 
echo "GenerateInitial_grid.out has runnned."

g++ mainplot.cpp -o mainplot.out -std=c++11
echo "main.cpp has been compiled successfully."

./mainplot.out
echo "main.out has runned."

