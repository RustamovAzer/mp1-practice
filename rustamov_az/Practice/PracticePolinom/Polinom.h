#pragma once

class Monom
{
public:
	double coef;
	int deg;
	Monom* next;
	Monom();
	Monom(const Monom& b);
	~Monom();
	Monom(int, double);
	Monom operator+(Monom&);
	Monom operator*(Monom & x);
	Monom& operator=(Monom & x);
	Monom& operator/(Monom & x);
	Monom operator-();
	void OutputMonom();
};

class Polinom
{
	Monom* head;
public:
	Polinom();
	~Polinom();
	void DeleteAll();
	void Add(int, double);
	void Add(Monom b);
	void _Add(Monom b);
	void Output();
	void Output1();
	void InputPolinom();
	Polinom& operator+(Polinom& b);
	Polinom & operator/(Monom & b);
	Polinom & operator-(Polinom & b);
	Polinom & operator*(double b);
	Polinom & operator*(Polinom & b);
	Polinom & operator*(Monom & x);
	Polinom & operator=(Polinom & x);
	Monom * Search(int _degr, Monom * start);
	Monom * SearchMax(Monom * start);
	Monom * SearchMax();
	void PlaceBefore(Monom * move, Monom * next);
	void PlaceAfter(Monom * move, Monom * prev);
	void Sort();
	Polinom & operator/(Polinom & b);
	Monom* Search(int);
	void GetMax(int * k);
	void RemoveNulls();
	void CombineSameDegs();
	void RemoveMonom(Monom*);
};