#pragma once
#include "Passport.h"
class Employee
{
    Passport passport;    //Паспорт
    string qualification; //Образование 
    string specialisation;//Специализация
    string division;      //Подразделение
    long salary;          //Оклад
    Date receiptD;        //Дата поступления
    Date AppD;            //Дата назначения
public:
    Employee();
    ~Employee();
    //TODO: Чтение из файла
};

