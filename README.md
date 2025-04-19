**Matrix Library Project**

**Authoring:**
Anthony Sagalovsky -- Student, UMBC CMSC 341 (Fall 2024)
Date: April 2025

**Purpose of Software:**
This project implements a simple matrix library in C++ and C++ providing basic matrix operations:
Construction and destruction of matrices
Element access (with bounds checking for C++)
Matrix addition, multiplication, scalar, and transpose
Implemented output for easy testing and debugging
A test driver (driver.cpp) uses a Tester class to validate each operation and a combined equation example.

**Files:**
matrix.h — C++ Declaration of the Matrix class, including constructors, operator overloads, and I/O functions.
matrix.cpp — C++ Implementation of all Matrix member functions and friend operators.
driver.cpp — C++ Tester class with unit tests for each matrix operation and a final combined equation test; prints PASS/FAIL and sample output.
Makefile — C++ Instructions to compile matrix.cpp and driver.cpp into the driver executable.

matrixC.h — C Declaration of the Matrix operations.
matrixC.c — C Implementation of all Matrix operations.
driverC.c — C Tester class with unit tests for each matrix operation and a final combined equation test; prints PASS/FAIL and sample output.
Makefile — C Instructions to compile matrix.c and driver.c into the driver executable.

**Build Instructions:**
C++17–compatible compiler (e.g., g++).
C99 compatible compiler (e.g. gcc -std=c99 -m32 -O0 myprogram.c)

In the project directory, run: make
To clean up object files and the executable: make clean
To run the tests: make run

**Testing Methodology**
Unit tests in driver.cpp and driver.c cover:

Addition (B + C) on 2×3 matrices
Multiplication (A * A) on a 2×2 matrix
Scalar multiplication (2·A) on a 2×2 matrix
Transpose (Cᵀ) on a 2×3 matrix
Combined equation D = A + (3·B)·Cᵀ on 2×2/2×3/2×3
Each test compares the computed result against a hand‑calculated expected matrix.  The driver prints PASS or FAIL for each.
Final computed matrix D is printed for visual verification.

**Additional Information**

For C++ version:
The library uses operator() with built‑in bounds checking (throws std::out_of_range).
Error conditions in member functions throw standard C++ exceptions (invalid_argument, out_of_range).

