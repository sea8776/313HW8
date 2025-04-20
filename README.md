**Matrix Library Project**

**Authoring:**
Anthony Sagalovsky -- Student, UMBC CMSC 341 (Fall 2024)
<br> Date: April 2025 <br>

**Purpose of Software:**
<br>This project implements a simple matrix library in C++ and C++ providing basic matrix operations:
<br>Construction and destruction of matrices
<br>Element access (with bounds checking for C++)
<br>Matrix addition, multiplication, scalar, and transpose
<br>Implemented output for easy testing and debugging
<br>A test driver (driver.cpp) uses a Tester class to validate each operation and a combined equation example.

**Files:**
<br> matrix.h — C++ Declaration of the Matrix class, including constructors, operator overloads, and I/O functions.
<br> matrix.cpp — C++ Implementation of all Matrix member functions and friend operators.
<br> driver.cpp — C++ Tester class with unit tests for each matrix operation and a final combined equation test; prints PASS/FAIL and sample output.
<br> Makefile — C++ Instructions to compile matrix.cpp and driver.cpp into the driver executable.
<br>
<br> matrixC.h — C Declaration of the Matrix operations.
<br> matrixC.c — C Implementation of all Matrix operations.
<br> driverC.c — C Tester class with unit tests for each matrix operation and a final combined equation test; prints PASS/FAIL and sample output.
<br> Makefile — C Instructions to compile matrix.c and driver.c into the driver executable.

**Build Instructions:**
<br>C++17–compatible compiler (e.g., g++).
<br>C99 compatible compiler (e.g. gcc -std=c99 -m32 -O0 myprogram.c)
<br>
<br>In the project directory, run: **make**
<br>To clean up object files and the executable: **make clean**
<br>To run the tests: **make run**

**Testing Methodology**
<br>Unit tests in driver.cpp and driver.c cover:
<br>Addition (B + C) on 2×3 matrices
<br>Multiplication (A * A) on a 2×2 matrix
<br>Scalar multiplication (2·A) on a 2×2 matrix
<br>Transpose (Cᵀ) on a 2×3 matrix
<br>Combined equation D = A + (3·B)·Cᵀ on 2×2/2×3/2×3
<br>Each test compares the computed result against a hand‑calculated expected matrix.  The driver prints PASS or FAIL for each.
<br>Final computed matrix D is printed for visual verification.

**Additional Information**

<br>For C++ version:
<br>The library uses operator() with built‑in bounds checking (throws std::out_of_range).
<br>Error conditions in member functions throw standard C++ exceptions (invalid_argument, out_of_range).

