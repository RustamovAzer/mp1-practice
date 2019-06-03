#ifndef _TYPE2_H_
#define _TASKSTD_H_
#include "Task.h"

class TaskStd : public Task
{
    Time t1, t2;
public:
    TaskStd(string, Date, Time, Time);
    ~TaskStd();
    void Print();
};

#endif