#include "TaskStd.h" 
#include <iostream> 
#include "Task.h"

using namespace std;

TaskStd::TaskStd(string _des, Date _date, Time _t1, Time _t2)
{
    description = _des;
    date = _date;
    t1 = _t1;
    t2 = _t2;
}

TaskStd::~TaskStd()
{
    description = nullptr;
}

void TaskStd::Print()
{
    cout << date << " " << t1 << "  " << t2 << " " << description << endl;
}