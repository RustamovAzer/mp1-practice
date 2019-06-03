#include "Nvector.h"


Nvector::Nvector(int _dim)
{
    if (dim <= 0) throw VectorIncorrectVariablesException();
    dim = _dim;
    v = new double(dim);
    for (int i = 0; i < dim; i++)
    {
        v[i] = 0.0;
    }
}
Nvector::Nvector(Nvector& _x)
{
    dim = _x.dim;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = _x.v[i];
    }
}
Nvector::Nvector(int _dim, double *_v)
{
    if ((*_v == NULL) || (_dim <= 0))
        throw VectorIncorrectVariablesException();

    dim = _dim;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
        v[i] = _v[i];
}
Nvector::~Nvector()
{
    dim = 0;
    if(v != nullptr) delete[] v;
}

Nvector& Nvector::operator=(const Nvector& _x)
{
    if (this == &_x)
    {
        return *this;
    }
    dim = _x.dim;
    if (v != nullptr)
    {
        delete[] v;
    }
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = _x.v[i];
    }
    return *this;
}



Nvector Nvector::operator+(const Nvector& b)
{
    if (dim != b.dim)
    {
        throw VectorUnequalDimensionException();
    }
    Nvector res(dim);
    for (int i = 0; i < dim; i++)
    {
        res.v[i] = v[i] + b.v[i];
    }
    return res;
}

Nvector Nvector::operator+(const double d)
{
    Nvector res(dim);
    for (int i = 0; i < dim; i++)
    {
        res.v[i] = v[i] + d;
    }
    return res;
}

Nvector Nvector::operator-(const Nvector& _x)
{
    if (dim != _x.dim)
    {
        throw VectorUnequalDimensionException();
    }
    Nvector res(dim);
    for (int i = 0; i < dim; i++)
    {
        res.v[i] = v[i] - _x.v[i];
    }
    return res;
}

Nvector Nvector::operator-(const double d)
{
    Nvector res(dim);
    for (int i = 0; i < dim; i++)
    {
        res.v[i] = v[i] - d;
    }
    return res;
}

double Nvector::operator*(const Nvector& _x)
{
    if (dim != _x.dim)
    {
        throw VectorUnequalDimensionException();
    }
    double res = 0.0;
    for (int i = 0; i < dim; i++)
    {
        res += v[i] * _x.v[i];
    }
    return res;
}

Nvector Nvector::operator*(const double m)
{
    Nvector* res = new Nvector(dim);
    for (int i = 0; i < dim; i++)
    {
        res->v[i] = v[i] * m;
    }
    return *res;
}
double& Nvector::operator[](int n)
{
    if ((n < 0) || (n >= dim))
    {
        throw VectorOutOfBoundsException();
    }
    return v[n];
}
double Nvector::Lenght()
{
    double res = 0.0;
    for (int i = 0; i < dim; i++)
    {
        res += v[i] * v[i];
    }
    res = sqrt(res);
    return res;
}
Nvector Nvector::operator+=(const Nvector& _x)
{
    if (dim != _x.dim)
    {
        throw VectorUnequalDimensionException();
    }
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] + _x.v[i];
    }
    return *this;
}

Nvector Nvector::operator+=(const double d)
{
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] + d;
    }
    return *this;
}

Nvector Nvector::operator-=(const Nvector& _x)
{
    if (dim != _x.dim)
    {
        throw VectorUnequalDimensionException();
    }
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] - _x.v[i];
    }
    return *this;
}

Nvector Nvector::operator-=(const double d)
{
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] - d;
    }
    return *this;
}

Nvector Nvector::operator*=(const Nvector& _x)
{
    if (dim != _x.dim)
    {
        throw VectorUnequalDimensionException();
    }
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] * _x.v[i];
    }
    return *this;
}

Nvector Nvector::operator*=(const double d)
{
    for (int i = 0; i < dim; i++)
    {
        v[i] = v[i] * d;
    }
    return *this;
}

 void* Nvector::operator new(size_t size) 
 {
    void *p = malloc(size);
    if (p == NULL) {
        throw VectorNotEnoughMemoryException();
    }
    return p;
}
 void Nvector::operator delete(void *p) 
 {
     delete p;
 }

 void* Nvector::operator new[](size_t v)
 {
     void *res = malloc(sizeof(Nvector) * v);
     if (res == NULL)
         throw VectorNotEnoughMemoryException();
     return res;
 }

void Nvector::operator delete[](void* v)
 {
     delete[] v;
 }
void Nvector::Print()
 {
     if (dim)
     {
         for (int i = 0; i < dim; i++)
         {
             cout << v[i] << " ";
         }
         cout << endl;
         return;
     }
     cout << "Вектор пуст";
 }
 void Nvector::Input()
 {
     int _dim;
     cout << "Задайте размерность вектора ";
     do {
         cin >> dim;
     } while (dim <= 0);
     delete[] v;
     v = new double[dim];
     cout << "Введите вектор" << endl;
     for (int i = 0; i < dim; i++)
     {
         cin >> v[i];
     }
 }
  istream& operator>> (istream& in, Nvector& _vector)
 {
     for (int i = 0; i < _vector.dim; i++)
         in >> _vector.v[i];

     return in;
 }

  ostream& operator<< (ostream &out, const Nvector& _vector)
 {
     if (_vector.dim == 0)
     {
         out << "Вектор пуст";
         return out;
     }

     out << "(";

     for (int i = 0; i < _vector.dim; i++)
     {
         if (i != _vector.dim - 1)
             out << _vector.v[i] << ", ";
         else
             out << _vector.v[i] << ")";
     }

     return out;
  };

  const char* VectorIncorrectVariablesException::what() const
  {
      return what_str.c_str();
  }

  const char* VectorUnequalDimensionException::what() const
  {
      return what_str.c_str();
  }

  const char* VectorOutOfBoundsException::what() const
  {
      return what_str.c_str();
  }
  const char* VectorNotEnoughMemoryException::what() const
  {
      return what_str.c_str();
  }