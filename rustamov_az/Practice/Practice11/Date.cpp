#include "Date.h"



Date::Date()
{
    year = 2000;
    month = 1;
    day = 1;
}

Date::Date(unsigned _year, unsigned _month, unsigned _day)
{
    year = _year;
    month = _month;
    day = _day;
}


Date::~Date()
{
}

