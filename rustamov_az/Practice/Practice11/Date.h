#pragma once
#include <iostream>
class Date
{
public:
    unsigned year, month, day;
    Date();
    Date(unsigned _year, unsigned _month, unsigned _day);
    ~Date();
    //TODO: Чтение из файла
};

