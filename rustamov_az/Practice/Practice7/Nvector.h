#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


class Nvector
{
    int dim;
    double* v;
public:
    Nvector(int _dim);
    Nvector(Nvector & _x);
    Nvector(int _size, double * _v);
    ~Nvector();

    const Nvector & operator=(const Nvector & _x);
    Nvector operator+(const Nvector & b);
    Nvector operator+(const double b);
    Nvector operator-(const Nvector & _x);
    Nvector operator-(const double b);
    double operator*(const Nvector & _x);
    Nvector operator*(const double m);
    double & operator[](int index);
    const double & operator[](int index)const;
    double Lenght();
    Nvector& operator+=(const Nvector & temp);
    Nvector& operator+=(const double d);
    Nvector& operator-=(const Nvector & _x);
    Nvector& operator-=(const double d);
    Nvector& operator*=(const Nvector & _x);
    Nvector& operator*=(const double d);
    void * operator new(size_t size);
    void operator delete(void * p);
    void * operator new[](size_t v);
    void operator delete[](void * v);
    friend istream & operator>> (istream & in, Nvector & _vector);
    friend ostream & operator<<(ostream & out, const Nvector & _vector);
};

class VectorIncorrectVariablesException : std::exception
{
    const std::string what_str = "Incorrect variables";
public:
    const char* what() const;
};

class VectorUnequalDimensionException : std::exception
{
    const std::string what_str = "Unequal dimension";
public:
    const char* what() const;
};

class VectorOutOfBoundsException : std::exception
{
    const std::string what_str = "Out of bounds";
public:
    const char* what() const;
};
class VectorNotEnoughMemoryException : std::exception
{
    const std::string what_str = "Not enough memory";
public:
    const char* what() const;
};

