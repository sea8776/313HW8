// matrixC.c
// 313 HW8 Matrix library implementation in C
#include "matrixC.h"
#include <stdio.h>
#include <stdlib.h>

// Name: *matrix_make
// make dynamic 2d array matrix
Matrix *matrix_make(unsigned int rows, unsigned int cols) {
    // create dynamic 2d array w/ memorry of matrix
    Matrix *matrix = malloc(sizeof(Matrix));
    // if matrix doesnt exist, return null
    if (!matrix) {
        return NULL;
    }

    // set matrix data types
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(double*));
    // check if matrix is null
    if (!matrix->data) {
        free(matrix);
        return NULL;
    }
    // populate array
    for (unsigned int i = 0; i < rows; i++) {
        // allocate memory for all columns in row
        matrix->data[i] = calloc(cols, sizeof(double));
        // if null
        if (!matrix->data[i]) {
            // free old allocated rows
            for (unsigned int k = 0; k < i; k++) {
                free(matrix->data[k]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Name: matrix_delete
// delete matrix array, serves as a destrutor kind of
void matrix_delete(Matrix *matrix) {
    // empty check
    if (!matrix) {
        return;
    }

    // deallocate 2-d array matrix
    for (unsigned int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }

    free(matrix->data);
    free(matrix);
}

// Name: matrix_get()
// returns matrix @ position
double matrix_get(const Matrix *matrix, unsigned int row, unsigned int col) {
    return matrix->data[row][col];
}

// Name: matrix_set()
// sets matrix @ position
void matrix_set(Matrix *matrix, unsigned int row, unsigned int col, double value) {
    matrix->data[row][col] = value;
}

// Name: matrix_add()
// add matrices a and b, RETURNS MATRIX POINTER
Matrix *matrix_add(const Matrix *a, const Matrix *b) {
    Matrix *newMat = matrix_make(a->rows, a->cols);
    if (!newMat) return NULL;
    for (unsigned int i = 0; i < a->rows; i++)
        for (unsigned int j = 0; j < a->cols; j++)
        newMat->data[i][j] = a->data[i][j] + b->data[i][j];
    return newMat;
}

// Name: matrix_mul()
// multiply matrices a and b, RETURNS MATRIX POINTER
Matrix *matrix_mul(const Matrix *a, const Matrix *b) {
    Matrix *newMat = matrix_make(a->rows, b->cols);
    // check if matrix exists
    if (!newMat) {
        return NULL;
    }

    for (unsigned int i = 0; i < a->rows; i++) {
        for (unsigned int j = 0; j < b->cols; j++) {
            double sum = 0.0;
            for (unsigned int k = 0; k < a->cols; k++){
                sum += a->data[i][k] * b->data[k][j];
                newMat->data[i][j] = sum;
            }
        }
    }
    return newMat;
}

// Name: matrix_scalar_mul()
// scalar matrix, RETURNS MATRIX POINTER
Matrix *matrix_scalar_mul(const Matrix *matrix, double scalar) {
    Matrix *newMat = matrix_make(matrix->rows, matrix->cols);
    // check if matrix exists
    if (!newMat) {
        return NULL;
    }

    for (unsigned int i = 0; i < matrix->rows; i++)
        for (unsigned int j = 0; j < matrix->cols; j++)
        newMat->data[i][j] = matrix->data[i][j] * scalar;
    return newMat;
}

// Name: matrix_transpose()
// transposes matrix, RETURNS MATRIX POINTER
Matrix *matrix_transpose(const Matrix *matrix) {
    Matrix *newMat = matrix_make(matrix->cols, matrix->rows);
    // check if matrix exists
    if (!newMat) {
        return NULL;
    }
    // flip rows and cols
        for (unsigned int i = 0; i < matrix->rows; i++){
            for (unsigned int j = 0; j < matrix->cols; j++){
                newMat->data[j][i] = matrix->data[i][j];
            }
        }

    return newMat;
}

// Name: matrix_print()
// print all matrices
void matrix_print(const Matrix *matrix) {
    for (size_t i = 0; i < matrix->rows; i++) {
        if (matrix->cols == 0) {
            printf("\n");
            continue;
        }
        for (size_t j = 0; j + 1 < matrix->cols; j++) {
            printf("%.6g ", matrix->data[i][j]);
        }
        // last element with newline
        printf("%.6g\n", matrix->data[i][matrix->cols - 1]);
    }
}
