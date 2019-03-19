#include "Polinom.h"



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
	//Отсортировать
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