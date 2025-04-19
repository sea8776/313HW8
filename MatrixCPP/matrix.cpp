// CMSC 313 - Spring 2025 - HW#8
#include "matrix.h"

// Name: Matrix()
// Default constructor: 0-by-0 matrix
Matrix::Matrix(){
    m_rows = 0;
    m_cols = 0;
    m_data = {};
}

// Name: Matrix(unsigned int, unsigned int)
// Creates a rows×cols matrix with all entries initialized to 0.0.
Matrix::Matrix(unsigned int rows, unsigned int cols){
    m_rows = rows;
    m_cols = cols;
    m_data = {rows, vector<double>(cols, 0)};
}

// Name: Matrix(const Matrix&)
// Copy constructor: performs deep copy
Matrix::Matrix(const Matrix& other){
    m_rows = other.m_rows;
    m_cols = other.m_cols;
    m_data = other.m_data;
}

// Name: operator=
// Copy assignment: check for self assign then apply rhs
Matrix& Matrix::operator=(const Matrix& rhs) {
    if (this != &rhs) {
        m_rows = rhs.m_rows;
        m_cols = rhs.m_cols;
        m_data = rhs.m_data;
    }
    return *this;
}

// Name: ~Matrix()
// Destructor: vector will clean up automatically.
Matrix::~Matrix(){
    // empty
}

// Name: checkBounds
// Throws out_of_range if (row,col) is not a valid index.
void Matrix::checkBounds(unsigned int row, unsigned int col) const{
    if (row >= m_rows || col >= m_cols) {
        throw out_of_range("Error: Index out of range");
    }
}

// Name: operator()(unsigned int,unsigned int)
// access matrix element, is mutable
double& Matrix::operator()(unsigned int row, unsigned int col){
    checkBounds(row, col);
    return m_data[row][col];
}

// Name: operator()(unsigned int,unsigned int) const
// access matrix element, is NOT mutable
const double& Matrix::operator()(unsigned int row, unsigned int col) const{
    checkBounds(row, col);
    return m_data[row][col];

}

// Name: operator+
// Matrix addition: need to have same rows and col
Matrix  Matrix::operator+(const Matrix& rhs) const{
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols) {
        throw invalid_argument("Error: Dimensions must match for Matrix Addition");
    }
    Matrix total(m_rows,m_cols);
    for (unsigned int i = 0; i < m_rows; i++)
        for (unsigned int j = 0; j < m_cols; j++)
            total.m_data[i][j] = m_data[i][j] + rhs.m_data[i][j];
    return total;
}

// Name: operator*
// Matrix multiplication: this.cols must equal rhs.rows.
Matrix  Matrix::operator*(const Matrix& rhs) const{
    if (m_cols != rhs.m_rows) {
        throw invalid_argument("Error: Incompatible Matrix Dimensions");
    }
    Matrix total(m_rows, rhs.m_cols);
    for (unsigned int i = 0; i < m_rows; i++) {
        for (unsigned int j = 0; j < rhs.m_cols; j++) {
            double sum = 0;
            for (unsigned int k = 0; k < m_cols; k++)
                sum += rhs.m_data[k][j] * m_data[i][k];
            total.m_data[i][j] = sum;
        }
    }
    return total;
}

// Name: operator*(double)
// Scalar multiplication: multiply every entry by the scalar
Matrix  Matrix::operator*(double scalar) const{
    Matrix total(m_rows, m_cols);
    for (unsigned int i = 0; i < m_rows; i++)
        for (unsigned int j = 0; j < m_cols; j++)
            total.m_data[i][j] = m_data[i][j] * scalar;
    return total;
}

// Name: transpose()
// transpose of this matrix.
Matrix  Matrix::transpose() const{
    Matrix transpose(m_cols, m_rows);
    for (unsigned int i = 0; i < m_rows; i++)
        for (unsigned int j = 0; j < m_cols; j++)
            transpose.m_data[j][i] = m_data[i][j];
    return transpose;
}

// Name: operator==
// if all entries equal eachother, returns true
bool Matrix::operator==(const Matrix& rhs) const{
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols){
        return false;
    } 
    for (unsigned int i = 0; i < m_rows; i++)
        for (unsigned int j = 0; j < m_cols; j++)
            if (m_data[i][j] != rhs.m_data[i][j])
                return false;
    return true;
}

// Name: operator!=
// if entries done equal, return true
bool Matrix::operator!=(const Matrix& rhs) const{
    return !(*this == rhs);
}

// Name: operator<<
// Prints matrix, row-major form
ostream& operator<<(ostream& sout, const Matrix& matrix){
    for (unsigned int i = 0; i < matrix.m_rows; i++) {
        for (unsigned int j = 0; j < matrix.m_cols; j++) {
            sout << matrix.m_data[i][j];
            if (j + 1 < matrix.m_cols){
                sout << ' ';
            }
        }
        sout << '\n';
    }
    return sout;
}

