// CMSC 341 - Fall 2024 - Project 4
#include "matrix.h"
#include <iostream>
using namespace std;

const string DIVIDER = "|-----------------------------|";
const string PASS    = "----Test Passed----";
const string FAIL    = "!!!!Test Failed!!!!";

class Tester {
    public:
        // Computes D = A + (3 * B) * C^T
        bool testEquation();
    };
    
    bool Tester::testEquation() {
        // define A (2×2), B (2×3), C (2×3)
        Matrix A(2,2);
        Matrix B(2,3);
        Matrix C(2,3);
        // fill A
        A(0,0) = 6;
        A(0,1) = 4;
        A(1,0) = 8;
        A(1,1) = 3;

        // fill B
        B(0,0) = 1;
        B(0,1) = 2;
        B(0,2) = 3;
        B(1,0) = 4;
        B(1,1) = 5;
        B(1,2) = 6;

        // fill C
        C(0,0) = 2;
        C(0,1) = 4;
        C(0,2) = 6;
        C(1,0) = 1;
        C(1,1) = 3;
        C(1,2) = 5;
    
        // compute D = A + (3 * B) * C.transpose()
        Matrix D = A + (B * 3.0) * C.transpose();
    
        // expected result:
        // 3*B = [ [3,6,9], [12,15,18] ]
        // C^T = [ [2,1], [4,3], [6,5] ]
        // (3B)*C^T = [ [84,66], [192,147] ]
        // D = A + that = [ [90,70], [200,150] ]
        Matrix expected(2,2);
        expected(0,0) = 90;
        expected(0,1) = 70;
        expected(1,0) = 200;
        expected(1,1) = 150;
        return (D == expected);
    }

    int main() {
        cout << "------------------ MATRIX TEST DRIVER ------------------" << endl;
        Tester tester;
    
        cout << "Test D = A + (3·B) * C^T : ";
        if (tester.testEquation()) {
            cout << PASS << endl;
        }
        else{
            cout << FAIL << endl;
        }
        cout << DIVIDER << endl;
    
        // Also print out the computed matrix for visual inspection
        Matrix A(2,2), B(2,3), C(2,3);
        A(0,0)=6; 
        A(0,1)=4;
        A(1,0)=8;
        A(1,1)=3;
        B(0,0)=1;
        B(0,1)=2;
        B(0,2)=3; 
        B(1,0)=4;
        B(1,1)=5;
        B(1,2)=6;
        C(0,0)=2;
        C(0,1)=4;
        C(0,2)=6; 
        C(1,0)=1;
        C(1,1)=3;
        C(1,2)=5;
    
        Matrix D = A + (B * 3.0) * C.transpose();
        cout << "D:" << endl
             << D;
    
        return 0;
    }