#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
#include <string>
using namespace std;

class Exception
{
private:
    string msg;
public:
    Exception(string _m) : msg(_m) {};
    void Print()
    {
        cout << " Error: " << msg << endl;
    }
};

#endif
