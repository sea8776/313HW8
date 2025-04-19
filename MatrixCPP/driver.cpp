// CMSC 341 - Fall 2024 - Project 4
#include "matrix.h"
#include <iostream>
using namespace std;

const string DIVIDER = "|-----------------------------|";
const string PASS    = "----Test Passed----";
const string FAIL    = "!!!!Test Failed!!!!";

class Tester {
    public:
        bool testAdd();
        bool testMul();
        bool testScalar();
        bool testTranspose();
        bool testEquation();
        void setup_ABC(Matrix &A, Matrix &B, Matrix &C);
    };
    
    void Tester::setup_ABC(Matrix &A, Matrix &B, Matrix &C) {
        A = Matrix(2,2);
        B = Matrix(2,3);
        C = Matrix(2,3);
        // A = [6 4; 8 3]
        A(0,0) = 6; 
        A(0,1) = 4;
        A(1,0) = 8; 
        A(1,1) = 3;
        // B = [1 2 3; 4 5 6]
        B(0,0) = 1; 
        B(0,1) = 2; 
        B(0,2) = 3;
        B(1,0) = 4; 
        B(1,1) = 5; 
        B(1,2) = 6;
        // C = [2 4 6; 1 3 5]
        C(0,0) = 2; 
        C(0,1) = 4; 
        C(0,2) = 6;
        C(1,0) = 1; 
        C(1,1) = 3; 
        C(1,2) = 5;
    }

    bool Tester::testAdd() {
        Matrix A, B, C;
        setup_ABC(A, B, C);
        // add
        Matrix added = B + C;
        // correct array
        double correct[] = { 3,6,9, 5,8,11 };
        // check if equal
        for (unsigned i = 0; i < 2; i++)
            for (unsigned j = 0; j < 3; j++)
                if (added(i,j) != correct[i*3 + j])
                    return false;
        return true;
    }
    
    bool Tester::testMul() {
        Matrix A, B, C;
        setup_ABC(A, B, C);
        // multiply
        Matrix mult = A * A;
        // correct array
        double correct[] = { 68,36, 72,41 };
        // check if equal
        for (unsigned i = 0; i < 2; i++)
            for (unsigned j = 0; j < 2; j++)
                if (mult(i,j) != correct[i*2 + j])
                    return false;
        return true;
    }
    
    bool Tester::testScalar() {
        Matrix A, B, C;
        setup_ABC(A, B, C);
        // mult
        Matrix scalar = A * 2.0;
        // correct array
        double correct[] = { 12,8, 16,6 };
        // check if equal
        for (unsigned i = 0; i < 2; i++)
            for (unsigned j = 0; j < 2; j++)
                if (scalar(i,j) != correct[i*2 + j])
                    return false;
        return true;
    }
    
    bool Tester::testTranspose() {
        Matrix A, B, C;
        setup_ABC(A, B, C);
        // transpose
        Matrix transpose = C.transpose();
        // correct array
        double correct[] = { 2,1, 4,3, 6,5 };
        // check if equal
        for (unsigned i = 0; i < 3; i++)
            for (unsigned j = 0; j < 2; j++)
                if (transpose(i,j) != correct[i*2 + j])
                    return false;
        return true;
    }
    
    bool Tester::testEquation() {
        Matrix A, B, C;
        setup_ABC(A, B, C);
        Matrix D = A + (B * 3.0) * C.transpose();
        // correct result
        double correct[] = { 90,70, 200,150 };
        
        // check if equa;
        for (unsigned i = 0; i < 2; i++)
            for (unsigned j = 0; j < 2; j++)
                if (D(i,j) != correct[i*2 + j])
                    return false;
        cout << "\nD:" << endl <<  D << "\n";
        
        return true;
    }

    int main() {
        cout << "------------------ MATRIX TEST DRIVER ------------------" << endl;
        Tester tester;
        // -----------------------------------------------------------------------------------------------
        if (tester.testAdd()) {
            cout << "Addition TEST (B + C): " << PASS << endl;
        } else {
            cout << "Addition TEST (B + C): " << FAIL << endl;
        }

        cout << DIVIDER << endl;

        // -----------------------------------------------------------------------------------------------
        if (tester.testMul()) {
            cout << "Multiplication TEST: " << PASS << endl;
        } else {
            cout << "Multiplication TEST: " << FAIL << endl;
        }

        cout << DIVIDER << endl;

        // -----------------------------------------------------------------------------------------------
        if (tester.testScalar()) {
            cout << "Scalar TEST: " << PASS << endl;
        } else {
            cout << "Scalar TEST: " << FAIL << endl;
        }

        cout << DIVIDER << endl;

        // -----------------------------------------------------------------------------------------------
        if (tester.testTranspose()) {
            cout << "Transpose TEST: " << PASS << endl;
        } else {
            cout << "Transpose TEST: " << FAIL << endl;
        }

        cout << DIVIDER << endl;

        // -----------------------------------------------------------------------------------------------
        if (tester.testEquation()) {
            cout << "Combined equation TEST: " << PASS << endl;
        } else {
            cout << "Combined equation TEST: " << FAIL << endl;
        }
        cout << DIVIDER << endl;

        // -----------------------------------------------------------------------------------------------
    
        return 0;
    }