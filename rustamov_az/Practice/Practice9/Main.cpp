#include "Todolist.h"
#include "Time.h"
#include "Date.h"
#include <iostream>
#include <conio.h>
#include "Task.h"
using namespace std;

int main()
{
    try
    {
        Todolist l;
        Date d;
        cout << "Enter date: ";
        cin >> d;
        l.read("ToDoList.txt");
        l.print(d);
    }
    catch (TaskNoTasksExeption)
    {
        cout << "You haven`t got tasks on this day";
    }
}