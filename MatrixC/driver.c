// driver.c
// test code for HW #8 in C

#include "matrixC.h"
#include <stdio.h>
#include <stdlib.h>

static const char *PASS = "----Test Passed----";
static const char *FAIL = "!!!!Test Failed!!!!";

// helper func to make matrices for test functions
static void setup_ABC(Matrix **A, Matrix **B, Matrix **C) {
    *A = matrix_make(2,2);
    *B = matrix_make(2,3);
    *C = matrix_make(2,3);

    // A = [6 4; 8 3]
    matrix_set(*A,0,0,6); 
    matrix_set(*A,0,1,4);

    matrix_set(*A,1,0,8);
    matrix_set(*A,1,1,3);
    // B = [1 2 3; 4 5 6]
    matrix_set(*B,0,0,1);
    matrix_set(*B,0,1,2);
    matrix_set(*B,0,2,3);

    matrix_set(*B,1,0,4);
    matrix_set(*B,1,1,5);
    matrix_set(*B,1,2,6);
    // C = [2 4 6; 1 3 5]
    matrix_set(*C,0,0,2);
    matrix_set(*C,0,1,4);
    matrix_set(*C,0,2,6);

    matrix_set(*C,1,0,1);
    matrix_set(*C,1,1,3);
    matrix_set(*C,1,2,5);
}

// test addition
int test_add(void) {
    // make matrices
    Matrix *A, *B, *C;
    setup_ABC(&A,&B,&C);
    // add matrices
    Matrix *added = matrix_add(B, C);
    // correct array
    double correct[6] = { 3,6,9, 5,8,11 };
    int works = 1;
    // check if equal
    for(unsigned i=0;i<2;i++) {
        for(unsigned j=0;j<3;j++) {
            if (matrix_get(added,i,j) != correct[i*3 + j]){
                works = 0;
            } 
        }
    }
    // deallocate
    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(added);
    // result
    return works;
}

// test mult
int test_mul(void) {
    // make matrices
    Matrix *A, *B, *C;
    setup_ABC(&A,&B,&C);
    // mult matrices
    Matrix *mult = matrix_mul(A, A);
    // correct array
    double correct[4] = { 68,36, 72,41 };

    int works = 1;

    // check if equal
    for(unsigned i=0;i<2;i++){
      for(unsigned j=0;j<2;j++){
        if (matrix_get(mult,i,j) != correct[i*2 + j]) works = 0;
      }
    }
    // deallocate
    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(mult);
    // result
    return works;
}

// test scalar
int test_scalar(void) {
    // make matrices
    Matrix *A, *B, *C;
    setup_ABC(&A,&B,&C);
    // scalar matrices
    Matrix *R = matrix_scalar_mul(A, 2.0);
    // correct array
    double correct[4] = { 12,8, 16,6 };
    int works = 1;
    // check if equal
    for(unsigned i=0;i<2;i++){
      for(unsigned j=0;j<2;j++){
        if (matrix_get(R,i,j) != correct[i*2 + j]) works = 0;
      }
    }
    // deallocate
    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(R);
    // result
    return works;
}

// Test 4: transpose of C  (2×3 → 3×2)
int test_transpose(void) {
    // make matrices
    Matrix *A, *B, *C;
    setup_ABC(&A,&B,&C);
    // transpose matrices
    Matrix *R = matrix_transpose(C);
    // correct array
    double correct[6] = { 2,1, 4,3, 6,5 };
    int works = 1;
    // check if equal
    for(unsigned i=0;i<3;i++){
      for(unsigned j=0;j<2;j++){
        if (matrix_get(R,i,j) != correct[i*2 + j]) works = 0;
      }
    }
    // deallocate
    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(R);
    // result
    return works;
}

// Test 5: the original combined equation
int test_equation(void) {
    // make matrices
    Matrix *A, *B, *C;
    setup_ABC(&A,&B,&C);

    // equation for matrices
    Matrix *B3 = matrix_scalar_mul(B,3.0);
    Matrix *Ct = matrix_transpose(C);
    Matrix *M  = matrix_mul(B3, Ct);
    Matrix *D  = matrix_add(A, M);
    // correct array
    double correct[4] = {90,70, 200,150};
    int works = 1;
    // check if equal
    for(unsigned i=0;i<2;i++){
      for(unsigned j=0;j<2;j++){
        if (matrix_get(D,i,j) != correct[i*2 + j]) works = 0;
      }
    }
    // print out new matrix
    printf("\n");
    puts("Computed D:"); matrix_print(D);
    printf("\n");

    // deallocate
    matrix_delete(A);
    matrix_delete(B);
    matrix_delete(C);
    matrix_delete(B3);
    matrix_delete(Ct);
    matrix_delete(M);
    matrix_delete(D);
    // result
    return works;
}

int main(void) {
    if (test_add()) {
        printf("Add TEST (B + C): %s\n", PASS);
    } else {
        printf("Add TEST (B + C): %s\n", FAIL);
    }

    if (test_mul()) {
        printf("Mul TEST (A * A): %s\n", PASS);
    } else {
        printf("Mul TEST (A * A): %s\n", FAIL);
    }

    if (test_scalar()) {
        printf("Scalar TEST (2*A): %s\n", PASS);
    } else {
        printf("Scalar TEST (2*A): %s\n", FAIL);
    }

    if (test_transpose()) {
        printf("Transpose TEST (C^T): %s\n", PASS);
    } else {
        printf("Transpose TEST (C^T): %s\n", FAIL);
    }

    if (test_equation()) {
        printf("Combined equation TEST : %s\n", PASS);
    } else {
        printf("Combined equation TEST : %s\n", FAIL);
    }

    return 0;
}