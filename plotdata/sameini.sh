#!/bin/sh

g++ mainplot.cpp -o mainplot.out -std=c++11
echo "main.cpp has been compiled successfully."

./mainplot.out
echo "main.out has runned."

gnuplot