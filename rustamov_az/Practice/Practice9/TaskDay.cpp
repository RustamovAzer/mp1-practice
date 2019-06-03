#include "TaskDay.h" 
#include <iostream> 
#include "Task.h"

using namespace std;

TaskDay::TaskDay()
{
}

TaskDay::TaskDay(string _des, Date _date)
{
    description = _des;
    date = _date;
}

TaskDay::~TaskDay()
{
    description = nullptr;
}

void TaskDay::Print()
{
    cout << date << "Your task is: " << description << endl;
}