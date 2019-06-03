#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include <string>
#include "Date.h"
#include "Task.h"

using namespace std;

class Todolist
{
    Task **task;
    int n;
public:
    Todolist();
    ~Todolist();
    void read(const string);
    void print(Date);
};

class TaskBadFileExeption : std::exception
{
    const std::string what_str = "Unable to open a file";
public:
    const char* what() const;
};

class TaskIncorrectTypeExeption : std::exception
{
    const std::string what_str = "Incorrect type";
public:
    const char* what() const;
};

class TaskNoTasksExeption : std::exception
{
    const std::string what_str = "You haven`t got tasks on this day";
public:
    const char* what() const;
};
#endif