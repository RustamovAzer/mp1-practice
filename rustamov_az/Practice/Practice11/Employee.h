#pragma once
#include "Passport.h"
class Employee
{
    Passport passport;
    string education;
    string specialisation;
    string division;
    long salary;
    Date receiptD;  //���� �����������
    Date AppD;      //���� ����������
public:
    Employee();
    ~Employee();
};

