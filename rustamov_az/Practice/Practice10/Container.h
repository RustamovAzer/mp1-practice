#ifndef _CONTAINER_H_ 
#define _CONTAINER_H_ 

#include <iostream> 

using namespace std;

template <typename T, int maxsize>
class Container
{
    T* arr;
    int n;

public:
    Container();
    Container(T*, int);
    Container(const Container &x);
    ~Container();
    bool isFull()const;
    bool isEmpty()const;
    int Find(T a)const;
    void Add(T a);
    void Delete(T a);
    void Delete1(int);
    T& operator[](int); //на запись
    const T& operator[](int) const; //на чтение
    friend std::ostream& operator << (std::ostream & o, const Container& x)
    {
        for (int i = 0; i < x.n; i++)
        {
            cout << x[i] << " ";
        }
        return o;
    }
    friend std::istream& operator >> (std::istream & o, const Container& x)
    {
        for (int i = 0; i < x.n; i++)
        {
            cin >> x[i] >> " ";
        }
        return o;
    }
};

template <typename T, int maxsize>
Container <T, maxsize>::Container()
{
    n = 0;
    arr = new T[maxsize];
};

template <typename T, int maxsize>
Container <T, maxsize>::Container(const Container <T, maxsize> &c)
{
    //Конструктор копирования 
    n = c.n;
    arr = new T[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = c.arr[i];
};

template <typename T, int maxsize>
Container <T, maxsize>::Container(T* arr1, int x)
{
    n = x;
    arr = new T[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = arr1[i];
};

template <typename T, int maxsize>
Container <T, maxsize>::~Container()
{
    n = 0;
    delete[] arr;
};

template <typename T, int maxsize>
bool Container <T, maxsize>::isFull() const
{
    return n == maxsize;
};

template <typename T, int maxsize>
bool Container <T, maxsize>::isEmpty() const
{
    return n == 0;
};

template <typename T, int maxsize>
int Container <T, maxsize>::Find(T a) const
{

    for (int i = 0; i < n; i++)
        if (arr[i] == a)
            return i;
    return -1;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Add(T a)
{
    if (isFull()) //Проверка на полноту 
    {
        throw ContainerIsFullExeption();
    }
    arr[n] = a;
    n++;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Delete1(int idx)
{
    if (isEmpty()) //Проверка на пустоту 
    {
        throw ContainerIsEmptyExeption();
    }
    arr[idx] = arr[n - 1]; //Замена найденного элемента на последний
    n--;
};

template <typename T, int maxsize>
void Container <T, maxsize>::Delete(T a)
{
    Delete1(Find(a)); //Удаление опредленного элемента 
}

template<typename T, int maxsize>
T& Container<T, maxsize>::operator[](int i)
{
    if ((i > maxsize) || (i < 0)) //Проверка на выход за границы 
    {
        throw ContainerOutOfBoundsExeption();
    }
    return arr[i];
};

template<typename T, int maxsize>
const T& Container<T, maxsize>::operator[](int i) const
{
    if ((i > maxsize) || (i < 0))
    {
        throw ContainerOutOfBoundsExeption();
    }
    return arr[i];
};

//Специализация 
template <typename T, int maxsize>
class Container <T*, maxsize>
{
    T** arr;
    int n;

public:
    Container();
    Container(T**, int);
    Container(const Container <T*, maxsize> &x);
    ~Container();
    bool isFull()const;
    bool isEmpty()const;
    int Find(T* a)const;
    void Add(T* a);
    void Delete1(T* a);
    T*& operator[](int);
    const T* operator[](int) const;

    friend std::ostream& operator << (std::ostream & o, const Container& x)
    {
        for (int i = 0; i < x.n; i++)
        {
            cout << *x[i] << " ";
        }
        return o;
    }
    friend std::istream& operator >> (std::istream & o, const Container& x)
    {
        for (int i = 0; i < x.n; i++)
        {
            cin >> x[i] >> " ";
        }
        return o;
    }
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container()
{
    n = 0;
    arr = new T*[maxsize];
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container(T** arr1, int x)
{
    n = x;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = new T(*(arr1[i]));
};

template <typename T, int maxsize>
Container <T*, maxsize>::Container(const Container <T*, maxsize> &c)
{
    n = c.n;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = new T(*(c.arr[i]));
};

template <typename T, int maxsize>
Container <T*, maxsize>::~Container()
{
    for (int i = 0; i < n; i++)
        delete arr[i];
    delete arr;
    n = 0;
};

template <typename T, int maxsize>
bool Container <T*, maxsize>::isFull() const
{
    return n == maxsize;
};

template <typename T, int maxsize>
bool Container <T*, maxsize>::isEmpty() const
{

    return n == 0;
};

template <typename T, int maxsize>
int Container <T*, maxsize>::Find(T* a) const
{
    for (int i = 0; i < n; i++)
        if (*arr[i] == *a)
            return i;
    return -1;
};

template <typename T, int maxsize>

void Container <T*, maxsize>::Add(T* a)
{
    if (isFull())
    {
        throw ContainerIsFullExeption();
    }
    arr[n] = new T; 
    *arr[n] = *a; 
    n++;
};

template <typename T, int maxsize>
void Container <T*, maxsize>::Delete1(T* a)
{
    if (isEmpty())
    {
        throw ContainerIsEmptyExeption();
    }
    *arr[Find(a)] = *arr[n - 1];
    delete arr[--n]; 
                     
};

template<typename T, int maxsize>
T*& Container<T*, maxsize>::operator[](int i)
{
    if ((i > maxsize) || (i < 0))
    {
        throw ContainerOutOfBoundsExeption();
    }
    return arr[i];
};

template<typename T, int maxsize>
const T* Container<T*, maxsize>::operator[](int i) const
{
    if ((i > maxsize) || (i < 0))
    {
        throw ContainerOutOfBoundsExeption();
    }
    return arr[i];
};

class ContainerIsFullExeption : std::exception
{
    const std::string what_str = "This container is full";
public:
    const char* what() const;
};
const char* ContainerIsFullExeption::what() const
{
    return what_str.c_str();
}

class ContainerOutOfBoundsExeption : std::exception
{
    const std::string what_str = "Out of bounds";
public:
    const char* what() const;
};
const char* ContainerOutOfBoundsExeption::what() const
{
    return what_str.c_str();
}
class ContainerIsEmptyExeption : std::exception
{
    const std::string what_str = "This container is empty";
public:
    const char* what() const;
};
const char* ContainerIsEmptyExeption::what() const
{
    return what_str.c_str();
}
#endif