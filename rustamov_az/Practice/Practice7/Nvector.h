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

    Nvector operator+(const Nvector & b);
    Nvector operator+(const double b);
    Nvector operator-(const Nvector & _x);
    Nvector operator-(const double b);
    double operator*(const Nvector & _x);
    Nvector operator*(const double m);
    double & operator[](int index);
    double Length();
    Nvector operator+=(const Nvector & temp);
    Nvector operator+=(const double d);
    Nvector operator-=(const Nvector & _x);
    Nvector operator-=(const double d);
    Nvector operator*=(const Nvector & _x);
    Nvector operator*=(const double d);
    void * operator new(size_t size);
    void operator delete(void * p);
    void * operator new[](size_t v);
    void operator delete[](void * v);
    void Print();
    void Input();
    friend istream & operator>> (istream & in, Nvector & _vector);
    friend ostream & operator<<(ostream & out, const Nvector & _vector);
};

