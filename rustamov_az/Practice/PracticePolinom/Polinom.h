#pragma once
#include <iostream>
class Polinom
{
	Monom* head;
public:
	Polinom();
	Polinom(double coef, int deg);
	Polinom(const Polinom&);
	void Add(double coef, int deg);
	void Sort();
	bool operator==(double a);
	int Count();
	void DeleteAll();
	void Output();
	Polinom Multiply(double coef, int deg);
	~Polinom();
	Polinom operator+(double a);
	Polinom operator+(Polinom a);
	Polinom operator-(double a);
	Polinom operator-(Polinom poli);
	Polinom operator*(Polinom a);
	
	Polinom operator*(double a);
	Polinom operator/(double a);
	Polinom operator/(Polinom poli);
	Polinom operator%(Polinom poli);
};

struct Monom
{
	double coef;
	int deg;
	Monom* next;
};

