#include "Time.h" 
#include <iostream> 

using namespace std;

Time::Time()
{
    h = 0;
    min = 0;
}

Time::Time(int _h, int _min)
{
    if ((_h < 0) || (_h > 24))
    {
        throw TimeIncorrectTimeExeption();
    }
    if ((_min < 0) || (_min > 60))
    {
        throw TimeIncorrectTimeExeption();
    }

    h = _h;
    min = _min;

}

Time::Time(const Time& x)
{
    h = x.h;
    min = x.min;
}

Time::~Time()
{
    h = 0;
    min = 0;
}


const Time& Time::operator=(const Time& x)
{
    if (&x == this)
        return *this;
    h = x.h;
    min = x.min;
    return *this;
}


ostream & operator<<(ostream & o, const Time & x)
{
    o << x.h << ":" << x.min << " ";
    return o;
}

istream & operator >> (istream & o, Time & x)
{
    o >> x.h >> x.min;
    return o;
}

const char* TimeIncorrectTimeExeption::what() const
{
    return what_str.c_str();
}