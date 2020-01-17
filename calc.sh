#!/bin/sh
g++ GenerateInitial_grid.cpp -o GenerateInitial_grid.out
echo "GenerateInitial_grid.cpp has been compiled successfully."

./GenerateInitial_grid.out
echo "GenerateInitial_grid.out has runnned."

g++ main.cpp -o main.out
echo "main.cpp has been compiled successfully."

./main.out
echo "main.out has runned."