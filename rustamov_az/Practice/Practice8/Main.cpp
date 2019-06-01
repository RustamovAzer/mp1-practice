#include <iostream>
#include "Matrix.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "Russian");
    double d = 0.0f;
    std::cout << "Ведите число d = ";
    std::cin >> d;
    std::cout << "Матрица 1\n";
    Matrix m1;
    m1.input();
    m1.output();

    std::cout << "Матрица 2\n";
    Matrix m2;
    m2.input();
    m2.output();

    Matrix m3;
    std::cout << "m1 + m2:\n";
    try
    {
        m3 = m1 + m2;
        m3.output();
    }
    catch (char* msg)
    {
        std::cout << "Исключение: " <<msg;
    }

    std::cout << "m1 + d:\n";
    m3 = m1 + d;
    m3.output();

    std::cout << "m1 - m2:\n";
    try
    {
        m3 = m1 - m2;
        m3.output();
    }
    catch (char* msg)
    {
        std::cout << "Исключение: " << msg;
    }

    std::cout << "m1 - d:\n";
    m3 = m1 - d;
    m3.output();

    std::cout << "m1 * m2:\n";
    try
    {
        m3 = m1 * m2;
        m3.output();
    }
    catch (char* msg)
    {
        std::cout << "Исключение: " << msg;
    }

    std::cout << "m1 * d:\n";
    m3 = m1 * d;
    m3.output();
}