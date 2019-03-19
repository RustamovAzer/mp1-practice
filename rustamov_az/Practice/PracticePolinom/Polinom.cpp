#include "Polinom.h"
#include <iostream>
using namespace std;

Polinom::Polinom()
{
	head = 0;
}

Polinom::Polinom(double coef, int deg)
{
	
	Monom* a = new Monom;
	a->coef = coef;
	a->deg = deg;
	head = a;

}

Polinom::Polinom(const Polinom & poli)
{
	Monom* a = poli.head;
	Monom* prev_a = a;
	Monom* copy_a;
	Monom* prev_copy_a;
	while (a)
	{
		prev_copy_a = new Monom;
		prev_copy_a->coef = a->coef;
		prev_copy_a->deg = a->deg;
		if (!head) head = prev_copy_a;
		if (a = a->next)
		{
			copy_a = new Monom;
			copy_a->coef = a->coef;
			copy_a->deg = a->deg;
			prev_copy_a = copy_a;
		}
		else prev_copy_a->next = 0;
	}

}

void Polinom::Add(double coef, int deg)
{
	Monom* i = 0;
	bool nodeg = false;
	for ( i = head; i->deg; i = i->next)
	{
		if (deg == i->deg) i->coef += coef;
		else nodeg = true;
	}
	if (nodeg)
	{
		i->next = new Monom();
		i->next->coef = coef;
		i->next->deg = deg;
	}
}

void Polinom::Sort()
{
	Monom* a = head;
	int num = 0;
	do
	{
		num++;
		a = a->next;
	} while (a);
	a = head;
	int* arrdeg = new int(num);
	double* arrcoef = new double(num);
	for (int i; i<num ; i++)
	{
		arrdeg[i] = a->deg;
		arrcoef[i] = a->coef;
	}

	int key = 0, keycoef = 0;
	int i = 0;
	for (int j = 1; j<num; j++) {
		key = arrdeg[j];
		keycoef = arrcoef[j];
		i = j - 1;
		while (i >= 0 && arrdeg[i]>key) {
			arrdeg[i + 1] = arrdeg[i];
			arrcoef[i + 1] = arrcoef[i];
			i = i - 1;
			arrdeg[i + 1] = key;
			arrcoef[i + 1] = keycoef;
		}
	}


}





Polinom::~Polinom()
{
	DeleteAll();
}

Polinom Polinom::operator+(Polinom poli)
{
	Polinom rez(*this);
	Monom* a = poli.head;
	do
	{
		rez.Add(a->coef, a->deg);
		a = a->next;

	} while (a);
	rez.Sort();
	return rez;
}

Polinom Polinom::operator*(Polinom a)
{
	Polinom rez();

	return rez;
}

void Polinom::DeleteAll()
{
	Monom* i = head;
	Monom* del = i;
	while (i)
	{
		i = i->next;
		delete del;
		del = i;
	}
}

void Polinom::Output()
{
	if (!head) cout << "0\n";
	for (Monom* i = head; i; i = i->next)
	{
		if ((i->coef > 0) && (i != head)) cout << "-";
		cout << i->coef << "x^" << i->deg;
	}
}
