#pragma once

class Monom
{
public:
	double coef;
	int deg;
	Monom* next;

	//конструкторы и деструкторы
	Monom();
	Monom(const Monom& b);
	Monom(int, double);
	~Monom();

	//операторы
	Monom operator+(const Monom&);
	Monom operator*(const Monom & x);
	Monom operator*(const double _coef);
	Monom operator-();
	Monom& operator/(Monom & x);
	Monom & operator/(const double _coef);
	bool operator==(const Monom &);
	bool operator!=(const Monom & x);
	Monom& operator=(Monom & x);

	//методы
	void OutputMonom();
};

class Polinom
{
	Monom* head;
public:
	Polinom();
	~Polinom();

	

	//операторы
	Polinom & operator+(const double _coef);
	Polinom & operator+(const Monom & m);
	Polinom & operator+(const Polinom& b);
	Polinom & operator-(const double _coef);
	Polinom & operator-(const Monom & m);
	Polinom & operator-(const Polinom & b);
	Polinom & operator*(const double _coef);
	Polinom & operator*(const Monom & m);
	Polinom & operator*(const Polinom & b);
	Polinom & operator/(const double _coef);
	Polinom & operator/(Monom & m);
	Polinom & operator/(Polinom & b);
	Polinom & operator=(Polinom & b);
	bool operator==(Polinom & b);

	bool operator!=(Polinom & x);

	//методы
	void DeleteAll();
	void Add(int, double);
	void Add(Monom b);
	void Sub(Monom b);
	void Output();
	void InputPolinom();
	Monom * Search(int _degr, Monom * start);
	Monom * SearchMax(Monom * start);
	Monom * SearchMax();
	void PlaceBefore(Monom * move, Monom * next);
	void PlaceAfter(Monom * move, Monom * prev);
	void Sort();
	Monom* Search(int);
	void GetMax(int * k);
	void RemoveNulls();
	void CombineSameDegs();
	void RemoveMonom(Monom*);
};