#include "Matrix.h"

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    m = nullptr;
}

Matrix::Matrix(const Matrix& _m)
{
    rows = _m.rows;
    cols = _m.cols;
    unsigned elements = rows * cols;
    m = new double[elements];
    for (unsigned i = 0; i < elements; i++)
        m[i] = _m.m[i];
}

Matrix::Matrix(unsigned _rows, unsigned _cols)
{
    rows = _rows;
    cols = _cols;
    unsigned elements = rows * cols;
    m = new double[elements];
    for (unsigned i = 0; i < elements; i++)
        m[i] = 0;
}

Matrix::Matrix(double* _m, unsigned _rows, unsigned _cols)
{
    rows = _rows;
    cols = _cols;
    unsigned elements = rows * cols;
    m = new double[elements];
    for (unsigned i = 0; i < elements; i++)
        m[i] = _m[i];
}

Matrix::~Matrix()
{
    rows = 0;
    cols = 0;
    delete[] m;
}

void Matrix::output()
{
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
            std::cout << m[i * cols + j] << " ";
        std::cout << '\n';
    }
}

void Matrix::input()
{
    std::cout << "������� ����� �����: ";
    std::cin >> rows;
    std::cout << "������� ����� ��������: ";
    std::cin >> cols;
    *this = Matrix(rows, cols);
    std::cout << "������� �������� ��������� �������: ";
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
    {
        std::cin >> m[i];
    }
}

Matrix Matrix::operator+(const Matrix& _m)
{
    if ((rows != _m.rows) || (cols != _m.cols))
        throw "������� ������ �� ���������\n";
    Matrix result(rows, cols);
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
        result.m[i] = m[i] + _m.m[i];
    return result;
}

Matrix Matrix::operator+(double d)
{
    if ((rows == 0) || (cols == 0))
        return Matrix();
    Matrix result(rows, cols);
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
        result.m[i] = m[i] + d;
    return result;
}

Matrix Matrix::operator-(const Matrix& _m)
{
    if ((rows != _m.rows) || (cols != _m.cols))
        throw "������� ������ �� ���������\n";
    Matrix result(rows, cols);
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
        result.m[i] = m[i] - _m.m[i];
    return result;
}

Matrix Matrix::operator-(double d)
{
    if (!rows || !cols)
        return Matrix();
    Matrix result(rows, cols);
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
        result.m[i] = m[i] - d;
    return result;
}

Matrix Matrix::operator*(const Matrix& _m)
{
    if ((rows != _m.cols) || (cols != _m.rows))
        throw "���������� �������� ���������\n";
    Matrix result(rows, _m.cols);
    for (unsigned i = 0; i < rows; i++)
        for (unsigned j = 0; j < cols; j++)
            for (unsigned k = 0; k < result.cols; k++)
                result.m[i * cols + j] += m[i * result.cols + k] * _m.m[k * _m.cols + j];
    return result;
}

Matrix Matrix::operator*(double d)
{
    if ((rows == 0) || (cols == 0))
        return Matrix();
    Matrix result(rows, cols);
    unsigned elements = rows * cols;
    for (unsigned i = 0; i < elements; i++)
        result.m[i] = m[i] * d;
    return result;
}

const Matrix& Matrix::operator=(const Matrix& _m)
{
    if ((rows == _m.rows) && (cols == _m.cols) && (m == _m.m))
        return *this;
    delete[] m;
    rows = _m.rows;
    cols = _m.cols;
    unsigned elements = rows * cols;
    m = new double[elements];
    for (unsigned i = 0; i < elements; i++)
        m[i] = _m.m[i];
    return *this;
}

double* Matrix::operator[](unsigned index)
{
    return m + index * cols;
}