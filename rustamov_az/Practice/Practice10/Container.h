#pragma once

//Контейнер объектов

template <typename T, int maxsize>
class Container
{
    T* arr;
    
public:
    Container();
    Container(const Contaner& x);
    ~Container();
    bool IsFull() const; 
    bool IsEmpty() const;
    int Find(const T& x) const;
    void Add(const T& x);
    void Delete(T a);
    T& operator[](unsigned idx);
    unsigned Next();
};

template<typename T, unsigned maxsize>
 Container<T, maxsize>::Container()
{
    arr = new T(maxsize);
}

template<typename T, int maxsize>
 Container<T, maxsize>::Container(const Contaner & x)
{
}

template<typename T, int maxsize>
 Container<T, maxsize>::~Container()
{
     delete[] arr;
}

template<typename T, int maxsize>
 bool Container<T, maxsize>::IsFull() const
{
     for (size_t i = 0; i < maxsize; i++)
     {
         if (arr[i] == NULL)return false;
     }
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
    bool Found = 0;
    for (int i = 0; i < maxsize; i++)
        if (arr[i] == x) return i;
    return -1;
    
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Add(const T & x)
{
     if (IsFull())throw "Contaner is already full";
     unsigned i = Next();
     arr[i] = x;
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Delete(T a)
{
    if (IsEmpty())throw "Contaner is already empty"
    idx = Find(a);
    unsigned i = Next();
    if (arr[idx] == arr[i - 1])
    {
        delete arr[i - 1];
        return;
    }
    arr[idx] = arr[i - 1];
    delete arr[i - 1];
    return;
}
 template<typename T, int maxsize>
 T & Container<T, maxsize>::operator[](unsigned idx)
 {
     if ((idx < 0) || (idx > maxsize))throw "Index is out of range";
     return arr[idx];
 }

 template<typename T, int maxsize>
 unsigned Container<T, maxsize>::Next()
 {
    if(IsEmpty())return 0;
    if (IsFull())return maxsize;
    for (size_t i = 0; i < maxsize; i++)
    {
        if (arr[i] = NULL)return i;
    }
 }

 //Контейнер указателей

template <typename T*, int maxsize>
class Container
{
    T** arr;
public:
    Container();
    Container(const Contaner& x);
    ~Container();
    //bool IsFull() const;
    //bool IsEmpty() const;
    int Find(const T* x) const;
    void Add(const T* x);
  //void Delete(T* a);
    unsigned Next();
};

template<typename T*, int maxsize>  
 Container<T, maxsize>::Container(const Contaner & x)
{
    for (int i = 0; i < maxsize; i++)
    {

    }
}
 template<typename T*, unsigned maxsize>
 Container<T, maxsize>::Container()
 {
     arr = new T*(maxsize);
 }
 template<typename T*, int maxsize>
 Container<T, maxsize>::Container(const Contaner & x)
 {
     for (size_t i = 0; i < maxsize; i++)
     {
         //Скопировать содержимое указателей
     }
 }
 template<typename T*, int maxsize>
 Container<T, maxsize>::~Container()
 {
     for (size_t i = 0; i < maxsize; i++)
     {
         delete arr[i];
     }
     deleteх[] arr;
 }
 template<typename T*, int maxsize>
  int Container<maxsize>::Find(const T * x) const
 {
      for (size_t i = 0; i < maxsize; i++)
      {
          //Сравнить содержимое arr[i] и x
      }
      return -1;
 }
 template<typename T*, int maxsize>
 void Container<T, maxsize>::Add(const T* x)
 {
     if (IsFull())throw "Contaner is already full";
     unsigned i = Next();
    //Скопировать содержимое указателя x в Next
 }