#pragma once
#include "Passport.h"
class Employee
{
    Passport passport;
    string education;
    string specialisation;
    string division;
    long salary;
    Date receiptD;  //Дата поступления
    Date AppD;      //Дата назначения
public:
    Employee();
    ~Employee();
};

