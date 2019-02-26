#pragma once
#include <iostream>

class Vector
{
	int *v;
	int size;
public:
	Vector();
	Vector(int);
	Vector(int*, int);
	Vector(const Vector&);
	~Vector();
	
	int e(int);
	void PrintVector(const char* = "");

	Vector& operator = (const Vector&);
	Vector& operator + (const Vector&);
	Vector& operator - (const Vector&);
	int operator * (const Vector&);
	Vector& operator * (int);
	bool operator == (const Vector&);
};

struct OutOfBorderException
{
	int type;
	OutOfBorderException(int _type): 
	type(_type) {};
};