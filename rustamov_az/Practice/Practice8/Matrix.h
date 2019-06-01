#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>

class Matrix
{
    unsigned rows;
    unsigned cols;
    double *m;
public:
    Matrix();
    Matrix(const Matrix&);
    Matrix(unsigned _rows, unsigned _cols);
    Matrix(double* _m, unsigned _rows, unsigned _cols);
    ~Matrix();

    void output();
    void input();

    const Matrix& operator=(const Matrix&);
    Matrix operator+(const Matrix&);
    Matrix operator+(double d);
    Matrix operator-(const Matrix&);
    Matrix operator-(double d);
    Matrix operator*(const Matrix&);
    Matrix operator*(double d);

    double* operator[](unsigned);
};



#endif
