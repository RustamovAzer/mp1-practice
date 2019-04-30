#pragma once
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
    void Add(const T& x) const;
    void Delete(T a);
};

template<typename T, int maxsize>
inline Container<T, maxsize>::Container()
{
    arr = new T(maxsize);
}

template<typename T, int maxsize>
inline Container<T, maxsize>::Container(const Contaner & x)
{
}

template<typename T, int maxsize>
inline Container<T, maxsize>::~Container()
{
    delete arr[];
}

template<typename T, int maxsize>
inline bool Container<T, maxsize>::IsFull() const
{
    if ((sizeof(arr) / sizeof(T)) == maxsize)return true;
    return false;
}

template<typename T, int maxsize>
inline bool Container<T, maxsize>::IsEmpty() const
{
    if (arr == nullptr)return true;
    return false;
}

template<typename T, int maxsize>
inline int Container<T, maxsize>::Find(const T & x) const
{
    bool Found = 0;
    for (int i = 0; i < maxsize; i++)
        if (arr[i] == x) return i;
    return -1;
    
}

template<typename T, int maxsize>
inline void Container<T, maxsize>::Add(const T & x) const
{
    for (int i = 0; i < maxsize; i++)
    {
        if (!arr[i])break;
    }
    arr[i] = x;
}

template<typename T, int maxsize>
inline void Container<T, maxsize>::Delete(T a)
{
    idx = Find(a);
    for (int i = 0; i < maxsize; i++)
    {
        if (!arr[i])break;
    }
    if (arr[idx] == arr[i - 1])
    {
        delete arr[i - 1];
        return;
    }
    arr[idx] = arr[i - 1];
    delete arr[i - 1];
    return;
}
template <typename *T, int maxsize>
class Container
{
    T** arr;
public:
    Container();
    Container(const Contaner& x);
    ~Container();
    bool IsFull() const;
    bool IsEmpty() const;
    int Find(const T* x) const;
    void Add(const T&* x) const;
    void Delete(T a);
};
template<typename T, int maxsize>  
inline Container<T*, maxsize>::Container(const Contaner & x)
{
    for (int i = 0; i < maxsize; i++)
    {

    }
}
