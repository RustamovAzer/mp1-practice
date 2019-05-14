#include "Container.h"
#include <iostream>

int main()
{
    using namespace std;
    Container<double, 15> C1;
    C1.Add(5.9); //Добавление элемента

    unsigned f1 = C1.Find(5.9); //Поиск элемента
    cout << f1 << endl; 
    
    Container<double, 15> C3;
    C3.IsEmpty; //Проверка на пустоту контейнера
    
    Container<double, 2> C5; 
    C5.Add(1.2);
    C5.Add(5.41);
    Container<double, 2> C5c(C5);

    C5.IsFull; //Проверка на заполненность контейнера
    C5.Delete(1.2); //Удаление элемента
    C5.IsFull; 
    cout << C5[0] << endl; //Индексация

    //Контейнер указателей
    Container<int*, 10> C2p;
    int a = 60, b = 59;
    int* x = &a, *y = &b;

    for (int i = 0; i < 10; i++)
    {
        C2p.Add(x); //Добавление элемента
    }
    C2p.IsEmpty; //Проверка на пустоту контейнера
    C2p.IsFull; //Проверка на полноту контейнера
    C2p.Delete(x); //Удаление элемента
    C2p.IsFull;
    C2p.Find(y);//Поиск элемента

    //Исключения

    try
    {
        Container<int, 3> C4;
        C4.Delete(2); //Удаление элемента из пустого контейнера
        C4.Add(1);
        C4.Add(1);
        C4.Add(1);

        C4.Add(1); //Добавление элемента в полный контейнер


        Container<double*, 3> C5;
        double el = 0.1;
        double* pt = &el;

        C5.Delete(pt); //Удаление элемента из пустого контейнера(указатель)
       
        C5.Add(pt);
        C5.Add(pt);
        C5.Add(pt);
        
        C5.Add(pt);//Добавление элемента в полный контейнер(указатель)


    }
    catch (char* ex)
    {
        cout << ex << endl;
    }
    
}