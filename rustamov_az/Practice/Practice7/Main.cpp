#pragma once
#include "Nvector.h"
#include <iostream>
using namespace std;


void main()
{
    int n1;
    cout << "Enter size vector 1: ";
    cin >> n1;
    Nvector v1(n1);
    cout << " Enter coordinats" << " v1 = " << endl;
    cin >> v1;
    cout << "Coordinates of your vector: ";
    cout << v1;
    cout << endl << endl;



    int n2;

    cout << "Enter size vector 2: ";
    cin >> n2;
    Nvector v2(n2);
    cout << " Enter coordinates" << " V2 = " << endl;
    cin >> v2;
    cout << "Coordinates of your vector: ";
    cout << v2;
    cout << endl << endl;

    int a;
    double l, m;
    try
    {
        cout << "Addition of this vector: ";
        cout << " V1 + V2 = V ( " << (v1 + v2) << ")" << endl;
    }
    catch (VectorUnequalDimensionException)
    {
        cout << "Unequal dimentions \n";
    }
    try
    {
        cout << "Subtraction of this vector: ";
        cout << " V1 - V2 = V ( " << (v1 - v2) << ")" << endl << endl;
    }
    catch (VectorUnequalDimensionException)
    {
        cout << "Unequal dimentions \n";
    }

    try
    {
        cout << "Scalar product of two vectors = " << (v1 * v2);
        cout << endl;
    }
    catch (VectorUnequalDimensionException)
    {
        cout << "Unequal dimentions \n";
    }

    try
    {
        cout << "Enter const for addition with Vector 1: ";
        cin >> a;
        cout << " V1 + const = V ( " << (v1 + a) << ")" << endl;

        cout << "Enter const for subtraction with Vector 1: ";
        cin >> a;
        cout << " V1 - const = V ( " << (v1 - a) << ")" << endl;

        cout << "Enter const for multiplication with Vector 1: ";
        cin >> a;
        cout << " V1 * const = V ( " << (v1 * a) << ")" << endl;

        cout << endl;
        v1 += v2;
        cout << " V1 += V2 = V ( " << v1 << ")" << endl;

        v1 -= v2;
        cout << " V1 -= V2 = V ( " << v1 << ")" << endl;

        cout << endl;
        cout << "Enter const for addition with Vector 1 (+=): ";
        cin >> a;
        v1 += a;
        cout << " V1 += const = V ( " << v1 << ")" << endl;

        cout << "Enter const for subtraction with Vector 1(-=): ";
        cin >> a;
        v1 -= a;
        cout << " V1 -= const = V ( " << v1 << ")" << endl << endl;

        l = v1.Lenght();
        cout << "Lenght of vector 1: " << l << endl;

        m = v2.Lenght();
        cout << "Lenght of vector 2: " << m << endl;
    }
    catch (VectorUnequalDimensionException)
    {
        cout << "Unequal dimentions \n";
    }
}