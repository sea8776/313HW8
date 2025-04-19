#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

class Tester;

class Matrix{
    public:
    friend class Tester;

    // constructors & destructors
    Matrix(); // size 0 matrix
    Matrix(unsigned int rows, unsigned int cols); // 
    Matrix(const Matrix& other); // copy constructor
    Matrix& operator=(const Matrix& rhs); // assignment operator
    ~Matrix(); // destructor

    unsigned int numRows() const { return m_rows; }
    unsigned int numCols() const { return m_cols; }

    // Element access (has bounds checking)
    double& operator()(unsigned int row, unsigned int col);
    const double& operator()(unsigned int row, unsigned int col) const;

    // Basic matrix operations
    Matrix  operator+(const Matrix& rhs) const;// matrix addition
    Matrix  operator*(const Matrix& rhs) const;// matrix multiplication
    Matrix  operator*(double scalar) const;// scalar multiplication
    Matrix  transpose() const;// transpose
    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;

    // output
    friend ostream& operator<<(ostream& os, const Matrix& matrix);
    friend istream& operator>>(istream& is, Matrix& matrix);

    private:
    unsigned int m_rows; // num of rows
    unsigned int m_cols; // num of cols
    vector<vector<double>> m_data; // matrix storage

    // helper func to check bounds on array, throws out of bounds exception
    void checkBounds(unsigned int r, unsigned int c) const;

};

#endif