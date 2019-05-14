#pragma once

//Контейнер объектов

template <typename T, int maxsize>
class Container
{
    T* arr;
    unsigned count;
    
public:
    Container();
    Container(const Contaner& x);
    ~Container();

    bool IsFull() const; 
    bool IsEmpty() const;
    

    void Add(const T& x);
    void Delete(T a);

    T& operator[](unsigned idx);
    int Find(const T& x) const;
};

template<typename T, unsigned maxsize>
 Container<T, maxsize>::Container()
{
    arr = new T[maxsize];
    count = 0;

}

template<typename T, int maxsize>
 Container<T, maxsize>::Container(const Contaner<T, maxsize> & x)
{
     if (x.arr == nullptr) arr = nullptr;
     else
     {
         arr = new T[maxsize];
         for (int i = 0; i < x.count; i++)
         {
             arr[i] = x.arr[i];
         }
     }
}

template<typename T, int maxsize>
 Container<T, maxsize>::~Container()
{
     delete[] arr;
     count = 0;
}

template<typename T, int maxsize>
 bool Container<T, maxsize>::IsFull() const
{
     if (count == maxsize)return true;
     return false;
}

template<typename T, int maxsize>
 bool Container<T, maxsize>::IsEmpty() const
{
    if (arr == nullptr)return true;
    return false;
}

template<typename T, int maxsize>
 int Container<T, maxsize>::Find(const T & x) const
{
    for (int i = 0; i < count; i++)
        if (arr[i] == x) return i;
    return -1;
    
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Add(const T & x)
{
     if (IsFull())throw "Contaner is already full"
     arr[count] = x;
     count++;
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Delete(T a)
{
    if (IsEmpty())throw "Contaner is already empty";
    idx = Find(a);
    if (arr[idx] == arr[count - 1])
    {
        delete arr[count - 1];
        count--;
        return;
    }
    arr[idx] = arr[count - 1];
    delete arr[count - 1];
    count--;
    return;
}
 template<typename T, int maxsize>
 T & Container<T, maxsize>::operator[](unsigned idx)
 {
     if ((idx < 0) || (idx > maxsize))throw "Index is out of range";
     return arr[idx];
 }


 //Контейнер указателей

template <typename T, int maxsize>
class Container<T*, maxsize>
{
    T** arr;
    unsigned count;
public:
    Container();
    Container(const Contaner<T*,maxsize>& x);
    
    ~Container();
    bool IsFull() const;
    bool IsEmpty() const;
    
    int Find(const T* x) const;
    void Add(const T* x);
    void Delete(T* a);
};

template<typename T, int maxsize>
Container<T*, maxsize>::Container(const Contaner<T*, maxsize> & x)
{
    count = x.count;
    if (count == 0)arr = nullptr;
    for (int i = 0; i < count; i++)
    {
        arr[i] = new T;
        *arr[i] = *x.arr[i];
    }
}
template<typename T, unsigned maxsize>
Container<T*, maxsize>::Container()
{
    arr = new T*[maxsize];
    count = 0;
}


template<typename T, int maxsize>
Container<T*, maxsize>::~Container()
{
    for (int i = 0; i < maxsize; i++)
    {
        delete arr[i];
    }
    deleteх[] arr;
}
template<typename T, int maxsize>
int Container<T*,maxsize>::Find(const T * x) const
{
    for (size_t i = 0; i < maxsize; i++)
    {
        if (*arr[i] == *x)return i;
        
    }
    return -1;
}
template<typename T, int maxsize>
void Container<T*, maxsize>::Add(const T* x)
{
    if (IsFull())throw "Contaner is already full";
    *arr[count] = *x;
    
}
template<typename T, int maxsize>
void Container<T*, maxsize>::Delete(T * a)
{
    if (IsEmpty())throw "Contaner is already empty";
    unsigned idx = Find(a);
    if (arr[idx] == arr[count - 1])
    {
        delete arr[count - 1];
        count--;
        return;
    }
    arr[idx] = arr[count - 1];
    delete arr[count - 1];
    count--;
    return;
}
