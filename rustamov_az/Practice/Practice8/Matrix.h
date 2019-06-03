#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix
{
    double *m;
    int rows, cols; 
public:
    Matrix(int _rows, int _cols);
    Matrix(double*, int, int);
    ~Matrix();
    Matrix(const Matrix&);
    Matrix operator+ (const Matrix&);
    Matrix operator- (const Matrix&);
    Matrix operator* (const Matrix&);
    Matrix operator+ (double);
    Matrix operator- (double);
    Matrix operator* (double);
    bool operator==(const Matrix& x) const;
    const double* operator[](int _i) const;

    friend std::ostream& operator<<(std::ostream &, const Matrix&);
    friend std::istream& operator >> (std::istream &, const Matrix&);
};
class MatrixBadSizeExeption : std::exception
{
    const std::string what_str = "Unable to proceed with these sizes";
public:
    const char* what() const;
};

class MatrixIncorrectIndexExeption : std::exception
{
    const std::string what_str = "Incorrect index/indexes";
public:
    const char* what() const;
};

#endif