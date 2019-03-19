#include "Polinom.h"
#include <iostream>
using namespace std;

Polinom::Polinom()
{
	Monom* a = new Monom;
	a->coef = 0;
	a->deg = 0;
	head = a;
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

Polinom Polinom::operator+(double a)
{
	Polinom rez(*this);
	rez.Add(a, 0);
	return rez;
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

Polinom Polinom::operator-(double a)
{
	Polinom rez(*this);
	rez.Add(-a, 0);
	return rez;
}

Polinom Polinom::operator-(Polinom poli)
{
	Polinom rez(*this);
	Monom* a = poli.head;
	do
	{
		rez.Add(-(a->coef), a->deg);
		a = a->next;

	} while (a);
	rez.Sort();
	return rez;
}


Polinom Polinom::operator*(Polinom poli)
{
	Polinom rez(0,0);
	Monom* i = head;
	Monom* j = poli.head;

	while (i)
	{
		while (j)
		{
			rez.Add(i->coef * j->coef, i->deg + j->deg);
			j = j->next;
		}
		i = i->next;
	}
	rez.Sort();
	return rez;
}

Polinom Polinom::Multiply(double coef, int deg)
{
	Polinom rez;
	Monom* i = head;

	while (i)
	{
		rez.Add(i->coef * coef, i->deg + deg);
	}
	rez.Sort();
	return rez;
}

Polinom Polinom::operator*(double a)
{
	Polinom rez(*this);
	Monom * i = rez.head;
	while (i)
	{
		i->coef = i->coef * a;
		i = i->next;
	}
	return rez;
}

Polinom Polinom::operator/(double a)
{
	Polinom rez(*this);
	Monom * i = rez.head;
	while (i)
	{
		i->coef = i->coef / a;
		i = i->next;
	}
	return rez;
}

Polinom Polinom::operator/(Polinom poli)
{
	Polinom rez;
	Polinom delimoe(*this); //Делимое
	Polinom chast;			//Целая часть частного
	//Polinom ost = *this;	//Остаток
	if (poli == 0) 
	{
		cout << "Ошибка: Деление на ноль. Возвращено делимое";
		return *this;
	}
	if (poli.Count = 1)
	{
		return((*this) / poli.head->coef);
	}

	Sort();
	poli.Sort;
	Monom * i = head;
	Monom * j = poli.head;

	while ((j->deg) < (i->deg))
	{
		chast = poli.Multiply(1, i->deg - j->deg);
		delimoe = delimoe - chast;
		i = delimoe.head;
		rez = rez + chast;

	}
	

	return rez;
}


Polinom Polinom::operator%(Polinom poli)
{
	Polinom rez;
	Polinom delimoe(*this); //Делимое
	Polinom chast;			//Целая часть частного
	//Polinom ost = *this;	//Остаток
	if (poli == 0)
	{
		cout << "Ошибка: Деление на ноль. Возвращено делимое";
		return *this;
	}
	if (poli.Count = 1)
	{
		return((*this) / poli.head->coef);
	}

	Sort();
	poli.Sort;
	Monom * i = head;
	Monom * j = poli.head;

	while ((j->deg) < (i->deg))
	{
		chast = poli.Multiply(1, i->deg - j->deg);
		delimoe = delimoe - chast;
		i = delimoe.head;

	}


	return delimoe;
}

Polinom& Polinom::operator=(const Polinom& poli)
{
	Polinom rez(poli);
	return(rez);
}

bool Polinom::operator==(double a)
{
	if ((Count() != 1)&& (head->deg != 0)&&(head->coef != a))return false;
	else return true;
}

int Polinom::Count()
{
	Monom* i = head;
	int count = 0;
	while (i)
	{
		count++;
		i = i->next;
	}
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
	head = 0;
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
