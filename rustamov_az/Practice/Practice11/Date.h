#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    unsigned year, month, day;
    Date();
    Date(unsigned _year, unsigned _month, unsigned _day);
    Date(string sdate);     //yyyy.mm.dd
    ~Date();



};

