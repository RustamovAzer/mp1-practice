#include "Vector.h"

Vector::Vector()
{
	size = 0;
	v = nullptr;
}

Vector::Vector(int _size)
{
	size = _size;
	v = new int[size];
	for (int i = 0; i < size; i++)
	{
		v[i] = 0;
	}
}

Vector::Vector(int* a, int n)
{
	size = n;
	v = new int[size];
	for (int i = 0; i < size; i++)
	{
		v[i] = a[i];
	}
}

Vector::Vector(const Vector & _v)
{
	size = _v.size;
	v = new int[size];
	for (int i = 0; i < size; i++)
	{
		v[i] = _v.v[i];
	}
}

Vector::~Vector()
{
	delete[] v;
	size = 0;
}

int Vector::e(int index)
{
	if ((index < size) && (index >= 0))
		return v[index];
	throw OutOfBorderException(1);
	return 0;
}

void Vector::PrintVector(const char* message)
{
	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << v[i] << "\n";
		}
	}
	else
	{
		std::cout << message;
	}
		
}

Vector & Vector::operator=(const Vector & _v)
{
	size = _v.size;
	v = new int[size];
	for (int i = 0; i < size; i++)
	{
		v[i] = _v.v[i];
	}
	return *this;
}

Vector& Vector::operator+(const Vector & _v)
{
	
	int minsize = size < _v.size ? size : _v.size;
	int maxsize = size > _v.size ? size : _v.size;
	Vector result(maxsize);
	for (int i = 0; i < minsize; i++)
	{
		result.v[i] = v[i] + _v.v[i];
	}
	return result;
}

Vector & Vector::operator-(const Vector & _v)
{
	int minsize = size < _v.size ? size : _v.size;
	int maxsize = size > _v.size ? size : _v.size;
	Vector result(maxsize);
	for (int i = 0; i < minsize; i++)
	{
		result.v[i] = v[i] - _v.v[i];
	}
	return result;
}

int Vector::operator*(const Vector & _v)
{
	int minsize = size < _v.size ? size : _v.size;
	int result = 0;
	for (int i = 0; i < minsize; i++)
	{
		result += v[i] * _v.v[i];
	}
	return result;
}

Vector& Vector::operator*(int m)
{
	Vector result(*this);
	for (int i = 0; i < size; i++)
	{
		result.v[i] *= m;
	}
	return result;
}

bool Vector::operator==(const Vector& _v)
{
	if (size != _v.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if(v[i] != _v.v[i])
			return false;
	}
	return true;
}

