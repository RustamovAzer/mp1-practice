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
	void DeleteAll();
	void Output();
	~Polinom();
	Polinom operator+(Polinom a);
	Polinom operator*(Polinom a);
};

struct Monom
{
	double coef;
	int deg;
	Monom* next;
};

