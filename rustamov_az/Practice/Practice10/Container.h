#ifndef _CONTAINER_H_ 
#define _CONTAINER_H_ 

#include <iostream> 
#include "Exceptions.h" 

using namespace std;

//Контейнер объектов

template <typename T, int maxsize>
class Container
{
    T* arr;
    unsigned count;
    unsigned resized;
    
public:
    Container();
    Container(T*, unsigned);
    Container(const Contaner<typename T, int maxsize>& c);
    ~Container();

    bool IsFull() const; 
    bool IsEmpty() const;
    

    void Add(T x);
    void Delete(T a);
    int Find(const T& x) const;
    void Resize(unsigned rv = 1);

    int getCount() { return count; }

    T& operator[](unsigned idx);
    const T& operator[] (int index) const;
    friend std::ostream& operator << (std::ostream & o, const Container& x)
    {
        for (int i = 0; i < x.count; i++)
        {
            cout << x[i] << " ";
        }
        return o;
    }
    
};

template<typename T, int maxsize>
 Container<T, maxsize>::Container()
{
    arr = new T[maxsize];
    count = 0;
    resized = 0;

}
 template <typename T, int maxsize>
 Container <T, maxsize>::Container(T* arr1, unsigned x)
 {
     count = x;
     arr = new T[maxsize];
     for (int i = 0; i < count; i++)
         arr[i] = arr1[i];
 };

template<typename T, int maxsize>
 Container<T, maxsize>::Container(const Contaner<T, maxsize> & c)
{
     if (x.arr == nullptr) arr = nullptr;
     else
     {
         count = c.count;
         arr = new T[maxsize + c.resized];
         for (int i = 0; i < count; i++)
             arr[i] = c.arr[i];
     }
}

template<typename T, int maxsize>
 Container<T, maxsize>::~Container()
{
     delete[] arr;
     count = 0;
     resized = 0;
}

template<typename T, int maxsize>
 bool Container<T, maxsize>::IsFull() const
{
     return count == maxsize + resized;
}

template<typename T, int maxsize>
 bool Container<T, maxsize>::IsEmpty() const
{
     return count == 0;
}

template<typename T, int maxsize>
 int Container<T, maxsize>::Find(const T & x) const
{
     for (int i = 0; i < count; i++)
         if (arr[i] == a)
             return i;
     return -1;
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Add(T x)
{
     if (IsFull())Resize();
     arr[count++] = x;
}

template<typename T, int maxsize>
 void Container<T, maxsize>::Delete(T a)
{
    if (IsEmpty())throw "Contaner is already empty";
    arr[Find(a)] = arr[--count];
}

 template<typename T, int maxsize>
 int Container<T, maxsize>::Resize(unsigned rv = 1)
 {
     T* tmp = new T[count];
     for (int i = 0; i < count; i++)
         tmp[i] = arr[i];
     delete[]arr;
     arr = new T[maxsize + rv];
     for (int i = 0; i < count; i++)
         arr[i] = tmp[i];
     delete[]tmp;
     resized += rv;

 }

 template<typename T, int maxsize>
 T & Container<T, maxsize>::operator[](unsigned index)
 {
     if ((index < 0) || (index >= count))throw "Index is out of range";
     return arr[index];
 }

 template<typename T, int maxsize>
 const T & Container<T, maxsize>::operator[](int index) const
 {
     if ((index < 0) || (index >= count))throw "Index is out of range";
     return arr[index];
 }


 //Контейнер указателей

 template<typename T, int maxsize>
 class Container<T*, maxsize>
 {
     T** arr;
     unsigned count;
     unsigned resized;
 public:
     Container() : count(0), resized(0), arr(new T*[maxsize]) {};
     ~Container();
     Container(const Container<T*, maxsize>& c);
     Container(T**, unsigned);

     bool IsFull() const { return count == maxsize + resized; }
     bool IsEmpty() const { return count == 0; }

     void Add(T* a);
     int Find(T* a) const;
     void Delete(T* a);
     void Resize(unsigned rv = 1);


     int getCount() { return count; }

     T* operator[] (int index);
     T* const operator[] (int index) const;
     friend std::ostream& operator << (std::ostream & o, const Container& x)
     {
         for (int i = 0; i < x.count; i++)
         {
             cout << *x[i] << " ";
         }
         return o;
     }
 
 };

 template<typename T, int maxsize>
 Container<T*, maxsize>::~Container()
 {
     for (int i = 0; i < count; i++)
         delete arr[i];
     delete arr;
     count = 0;
     resized = 0;
 }

 template <typename T, int maxsize>
 Container <T*, maxsize>::Container(T** arr1, unsigned x)
 {
     count = x;
     arr = new T*[maxsize];
     for (int i = 0; i < count; i++)
         arr[i] = new T(*(arr1[i]));
 };

 template<typename T, int maxsize>
 Container<T*, maxsize>::Container(const Container<T*, maxsize>& a)
     : count(a.count),resized(a.resized), arr(new T*[maxsize])
 {
     for (int i = 0; i < count; i++)
     {
         arr[i] = new T;
         *arr[i] = *a.arr[i];
     }
 }

 template<typename T, int maxsize>
 int Container<T*, maxsize>::Find(T* a) const
 {
     for (int i = 0; i < count; i++)
         if (*arr[i] == *a)
             return i;
     throw - 1;
 }

 template<typename T, int maxsize>
 T* Container<T*, maxsize>::operator[](int index)
 {
     if ((index < 0) || (index >= count))
         throw "Index is out of range";
     return arr[index];
 }

 template<typename T, int maxsize>
 T* const Container<T*, maxsize>::operator[](int index) const
 {
     if ((index < 0) || (index >= count))
         throw "Index is out of range";
     return arr[index];
 }

 template<typename T, int maxsize>
 void Container<T*, maxsize>::Delete(T* a)
 {
     if (IsEmpty())
         throw "Contaner is already empty";

     *arr[Find(a)] = *arr[count - 1];
     delete arr[--count];
 }

 template<typename T, int maxsize>
 void Container<T*, maxsize>::Add(T* a)
 {
     if (IsFull())
         Resize();
     arr[count] = new T;
     *arr[count++] = *a;
 }

 template<typename T, int maxsize>
 int Container<T*, maxsize>::Resize(unsigned rv = 1)
 {
     T** tmp = new T*[count];
     for (int i = 0; i < count; i++)
     {
         tmp[i] = new T;
         *tmp[i] = *arr[i];
         delete arr[i];
     }
     delete arr;
     arr = new T*[maxsize + rv];
     for (int i = 0; i < count; i++)
     {
         *arr[i] = *tmp[i];
         delete tmp[i];
     }
     delete tmp;

 };
#endif