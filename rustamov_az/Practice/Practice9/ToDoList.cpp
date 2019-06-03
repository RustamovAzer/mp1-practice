#include "ToDoList.h" 
#include "TaskDay.h"
#include "TaskStd.h"
#include <iostream> 
#include <fstream>

using namespace std;

Todolist::Todolist()
{
    n = 0;
}

void Todolist::read(const string namef)
{
    string s;
    string description;
    int type;
    Date date;
    Time t1;
    Time t2;
    ifstream f;
    f.open(namef);
    if (!f.is_open())
        throw TaskBadFileExeption();
    f >> n; 
    task = new Task*[n];
    for (int i = 0; i < n; i++)
    {
        f >> type;
        if (type == 1)
        {
            f >> date;
            getline(f, description); 
            task[i] = new TaskDay(description, date);
        }

        else if (type == 2)
        {
            f >> date >> t1 >> t2;
            getline(f, description);
            task[i] = new TaskStd(description, date, t1, t2);
        }
        else throw TaskIncorrectTypeExeption();
    }
    f.close();
}

void Todolist::print(Date _d)
{
    int fl = 0;

    for (int i = 0; i < n; i++)
    {

        if (task[i][0].GetDate() == _d)
        {
            cout << "Your plans for the day: " << endl;
            task[i][0].Print();
            fl = 1;
        }
    }
    if (fl == 0)
        throw TaskNoTasksExeption();
}

Todolist::~Todolist()
{
    n = 0;
    delete[] task;
}

const char* TaskBadFileExeption::what() const
{
    return what_str.c_str();
}
const char* TaskIncorrectTypeExeption::what() const
{
    return what_str.c_str();
}
const char* TaskNoTasksExeption::what() const
{
    return what_str.c_str();
}