#pragma once
#include "Nvector.h"
#include <iostream>
using namespace std;


void main()
{
    double a1[5] = { 1, 2, 3, 4, 5 }, 
        a2[5] = { 3, 1, 4, 1, 5 }, 
        a3[3] = { 1, -3, -1 };

    try
    {
        Nvector v1(5, a1), v2(5, a2), v3(3, a3), v4(3);
        cout << "������ v1 = " << v1 << endl;
        cout << "������ v2 = " << v2 << endl;
        cout << "������ v3 = " << v3 << endl;
        cout << "������ v4 = " << v2 << endl << endl;

        cout << "����� v1 = " << v1.Length() << endl;
        cout << "����� v2 = " << v2.Length() << endl;
        cout << "����� v3 = " << v1.Length() << endl;
        cout << "����� v4 = " << v2.Length() << endl;

        cout << "v1 + v2 = " << v1 + v2 << endl;
        cout << "v1 - v2 = " << v1 - v2 << endl;
        cout << "v1 * v2 = " << v1 * v2 << endl << endl;

        cout << "v1 + 5 = " << v1 + 5 << endl;
        cout << "v1 - 3 = " << v1 - 3 << endl;
        cout << "v1 * 8 = " << v1 * 8 << endl << endl;

        cout << "v1[5] = " << v1[5] << endl << endl;
        cout << "v2[2] = " << v2[2] << endl << endl;
        cout << "v2[2] + 2 " << v2[2] + 2 << endl << endl;

        Nvector *test = new Nvector(3);
        cout << "test = " << *test << endl << endl;
        delete test;

        Nvector vt(0, a1);
        cout << "v3 * v1 = ";

    }
    catch (const int& ex)
    {
        switch (ex)
        {
        case 0:
            cout << "����������� ������� ������"<< endl;
            break;
        case 1:
            cout << "����������� �������� �� ���������" << endl;
            break;
        case 2:
            cout << "����� �� ������� ���������" << endl;
            break;
        case 3:
            cout << "�� ���������� ������" << endl;
            break;
        default:
            cout << "����������� ������" << endl;
            break;
        }
    }
}