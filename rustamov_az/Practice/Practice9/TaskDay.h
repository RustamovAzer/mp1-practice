#ifndef _TYPE1_H_
#define _TASKDAY_H_
#include "Task.h"

class TaskDay : public Task
{
public:
    TaskDay();
    TaskDay(string, Date);
    ~TaskDay();
    void Print();
};

#endif