# Factorial

A simple command line interface for calculating factorials. Built in C++.

# Build

This program requires:

    - Any C++ compiler

    - The GMP and GMPXX libraries

To build, use your C++ compiler making sure to include the gmp and gmpxx libraries.
For example:

> g++ main.cpp -lgmp -lgmpxx -o factorial

# Usage

Use the program like this:

> factorial.exe [number] [outfile]

For example:

> factorial.exe 10 10factorial.txt

This will calculate the factorial of 10 and store it in the 10factorial.txt file.
