// matrixC.h
// C99 Matrix library header using dynamic 2D arrays
#ifndef MATRIXC_H
#define MATRIXC_H

#include <stddef.h>

// Matrix with dynamic 2D array (pointer-to-pointer)
typedef struct {
    unsigned int rows;
    unsigned int cols;
    double **data;
} Matrix;

// Allocate a rows by cols matrix
Matrix *matrix_make(unsigned int rows, unsigned int cols);

// Free a matrix allocated by matrix_make
void matrix_delete(Matrix *matrix);

// Get element @ pos
double  matrix_get(const Matrix *matrix, unsigned int row, unsigned int col);

// Set element @ pos
void    matrix_set(Matrix *matrix, unsigned int row, unsigned int col, double val);

// Matrix addition
Matrix *matrix_add(const Matrix *a, const Matrix *b);

// Matrix multiplication
Matrix *matrix_mul(const Matrix *a, const Matrix *b);

// Scalar multiplication
Matrix *matrix_scalar_mul(const Matrix *matrix, double scalar);

// Transpose
Matrix *matrix_transpose(const Matrix *matrix);

// Print matrix to stdout: each row on its own line, elements separated by spaces
void    matrix_print(const Matrix *matrix);

#endif