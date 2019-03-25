#include "Polinom.h"
#include <iostream>	

Monom::Monom()
{
	next = nullptr;
	deg = 0;
	coef = 0.0;
}

Monom::Monom(const Monom& mono)
{
	next = mono.next;
	deg = mono.deg;
	coef = mono.coef;
}

Monom::~Monom()
{

}

Monom::Monom(int _deg, double _coef)
{
	coef = _coef;
	deg = _deg;
	next = nullptr;
}

Monom Monom::operator+(const Monom & mono)
{
	Monom tmp;
	tmp.next = next;
	tmp.coef = coef + mono.coef;
	return tmp;
}

Monom Monom::operator*(const Monom & mono)
{
	Monom tmp;
	tmp.coef = coef * mono.coef;
	tmp.deg = deg * mono.deg;
	return tmp;
}

Monom Monom::operator*(const double _coef)
{
	Monom tmp;
	tmp.coef = coef * _coef;
	return tmp;
}

Monom& Monom::operator=(Monom & mono)
{
	coef = mono.coef;
	deg = mono.deg;
	return *this;
}

Monom& Monom::operator/(Monom & mono)
{
	Monom* tmp = new Monom(*this);
	tmp->coef = coef / mono.coef;
	tmp->deg = deg - mono.deg;
	return *tmp;
}

Monom& Monom::operator/(const double _coef)
{
	Monom* tmp = new Monom(*this);
	tmp->coef = coef / _coef;
	return *tmp;
}

Monom Monom::operator-()
{
	coef = -coef;
	return Monom();
}
bool Monom::operator== (const Monom&  x)
{
	if ((x.coef == coef) && (x.deg == deg))return true;
	else return false;
}

bool Monom::operator!= (const Monom&  x)
{
	if ((x.coef != coef) && (x.deg != deg))return true;
	else return false;
}
void Monom::OutputMonom()
{
	if (deg == 0)
	{
		std::cout << "+" << coef;
		return;
	}
	std::cout << std::showpos << coef << "x^" << std::noshowpos << deg;
}

Polinom::Polinom()
{
	head = nullptr;
}

Polinom::~Polinom()
{
	DeleteAll();
}

Polinom & Polinom::operator+(const double _coef)
{
	Polinom* tmp = new Polinom();
	Monom* mon = new Monom(0, _coef);
	tmp->Add(*mon);
	return *tmp;

}

Polinom & Polinom::operator+(const Monom & b)
{
		Polinom* tmp = new Polinom();
		tmp->Add(b);
		return *tmp;

}

Polinom & Polinom::operator+(const Polinom & b)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = b.head; i; i = i->next)
		{
			Monom* tm = tmp->Search(i->deg);
			if (tm)
			{
				tm->coef += i->coef;
			}
			else
			{
				tmp->Add(*i);
			}
		}
		RemoveNulls();
		CombineSameDegs();
		return *tmp;
	}

}

Polinom & Polinom::operator-(const Polinom & b)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = b.head; i; i = i->next)
		{
			Monom* tm = tmp->Search(i->deg);
			if (tm)
			{
				tm->coef -= i->coef;
			}
			else
			{
				tmp->Sub(*i);
			}
		}
		RemoveNulls();
		return *tmp;
	}
}

Polinom & Polinom::operator-(double d)
{
	Polinom* tmp = new Polinom(*this);
	Monom* mono = new Monom(0, d);
	tmp->Sub(*mono);
	tmp->CombineSameDegs();
	return(*tmp);
}

Polinom & Polinom::operator-(const Monom & m)
{
	Polinom* tmp = new Polinom(*this);
	tmp->Sub(m);
	tmp->CombineSameDegs();
	return(*tmp);
}

Polinom & Polinom::operator/(const double _coef)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = tmp->head; i; i = i->next)
		{
			*i = *i / _coef;
		}
		return *tmp;
	}
}

Polinom & Polinom::operator/(Monom& b)
{
	if (!head)
		return *this;
	else
	{
		Polinom* tmp = new Polinom(*this);
		for (Monom* i = tmp->head; i; i = i->next)
		{
			*i = *i / b;
		}
		return *tmp;
	}
}
Polinom& Polinom::operator/(Polinom& divider)
{

	Polinom* rez = new Polinom();
	Polinom* dividend = new Polinom(*this);//Делимое
	Polinom quotient; //Частное
	Monom* a = divider.head;
	if (a->next == nullptr)
	{
		*rez = *this / *a;
		return *rez;
	}

	Monom* div = new Monom(*head);
	Monom* max_deg_dividend = dividend->SearchMax();
	Monom* max_deg_div = divider.SearchMax();
	if (max_deg_dividend->deg < max_deg_div->deg)
	{
		rez->Add(0, 0);
		return *rez;
	}
	while (max_deg_dividend->deg >= max_deg_div->deg)
	{
		Monom tmp = *max_deg_dividend / *max_deg_div;
		rez->Add(tmp);
		*dividend = *dividend - (divider * tmp);
		max_deg_dividend = dividend->SearchMax();
		if (max_deg_dividend == nullptr)
			break;
	}
	return *rez;
}



Polinom & Polinom::operator*(double b)
{
	Monom* i;
	for (i = head; i; i = i->next)
	{
		i->coef = i->coef * b;
	}
	return *this;
}

Polinom & Polinom::operator*(const Polinom & b)
{
	Monom* i, *k;
	if (!b.head)
	{
		Polinom* tmp = new Polinom(*this);
		return *tmp;
	}
	Polinom* tmp = new Polinom();
	for (i = head; i; i = i->next)
	{
		for (k = b.head; k; k = k->next)
		{
			tmp->Add((*i) * (*k));
		}
	}
	tmp->RemoveNulls();
	return *tmp;
}

Polinom & Polinom::operator*(const Monom & mono)
{
	if (!head)
		return *this;
	Polinom* tmp = new Polinom(*this);
	for (Monom* i = tmp->head; i; i = i->next)
	{
		i->coef *= mono.coef;
		i->deg += mono.deg;
	}
	return *tmp;
}

Polinom & Polinom::operator=(Polinom & x)
{
	if (x == *this)return *this;
	DeleteAll();
	for (Monom* i = x.head; i; i = i->next)
	{
		Add(*i);
	}
	return *this;
}

bool Polinom::operator==(Polinom & x) 
{
	Sort();
	x.Sort();
	Monom* i = head;
	Monom* j = x.head;
	bool rez = true;
	do
	{
		if ((*i) != (*j)) 
		{
			rez = false;
			return rez;
		}
		i = i->next;
		j = j->next;
	} while ((i) && (j));

}

bool Polinom::operator!=(Polinom & x)
{
	Sort();
	x.Sort();
	Monom* i = head;
	Monom* j = x.head;
	bool rez = false;
	do
	{
		if ((*i) != (*j))
		{
			rez = true;
			return rez;
		}
		i = i->next;
		j = j->next;
	} while ((i) && (j));

}
void Polinom::DeleteAll()
{
	Monom* i = head;
	Monom* del = i;
	while (i != nullptr)
	{
		i = i->next;
		delete del;
		del = i;
	}
	head = nullptr;
}

void Polinom::Add(int _deg, double _coef)
{
	Monom* i;
	if (!head) head = new Monom(_deg, _coef);
	else
	{
		for (i = head; i->next != 0; i = i->next) {}
		i->next = new Monom(_deg, _coef);
	}
}

void Polinom::Add(Monom b)
{
	Monom* i;
	if (!head) head = new Monom(b);
	else
	{
		for (i = head; i->next != 0; i = i->next) {}
		i->next = new Monom(b);
	}
	CombineSameDegs();
}

void Polinom::Sub(Monom mono)
{
	Monom* i;
	if (!head) head = new Monom(-mono);
	else
	{
		for (i = head; i->next != 0; i = i->next) {}
		i->next = new Monom(-mono);
	}
}

void Polinom::Output()
{
	Monom* i = head;
	int s_deg;
	GetMax(&s_deg);
	if (!head) std::cout << "0" << std::endl;
	for (; s_deg >= 0; s_deg--)
	{
		i = Search(s_deg);
		if (i == nullptr) continue;
		i->OutputMonom();
	}
	std::cout << std::endl;
}


void Polinom::InputPolinom()
{
	int indeg;
	double incoef;
	Monom* i;
	incoef = 1;
	for (i = head; i->next != 0; i = i->next) {}
	while (1)
	{
		std::cout << "Введите коэфициент и степень ";
		std::cin >> incoef >> indeg;
		if (incoef == 0) break;
		i->next = new Monom(indeg, incoef);
		i = i->next;
	}
	CombineSameDegs();
}

Monom* Polinom::Search(int s_deg)
{
	Monom* i;
	if (!head) return nullptr;
	for (i = head; i; i = i->next)
	{
		if (i->deg == s_deg) return i;
	}
	return nullptr;
}

void Polinom::GetMax(int *max_deg)
{
	Monom* i;
	int max = 0;
	for (i = head; i; i = i->next)
	{
		if (i->deg > max) max = i->deg;
	}
	*max_deg = max;
}

void Polinom::RemoveNulls()
{
	Monom* i;
	for (i = head; i; i = i->next)
	{
		if (i->coef == 0)
		{
			RemoveMonom(i);
			return;
		}
	}
}

void Polinom::CombineSameDegs()
{
	if (!head)
		return;
	for (Monom* i = head; i; i = i->next)
	{
		while (Monom* temp = Search(i->deg, i->next))
		{
			i->coef += temp->coef;
			RemoveMonom(temp);
		}
	}
}

void Polinom::RemoveMonom(Monom* k)
{
	if (!head)
		return;
	for (Monom* i = head; i; i = i->next)
	{
		if (i->next == k)
		{
			i->next = k->next;
			delete k;
		}
	}
}

Monom* Polinom::Search(int _degr, Monom* start)
{
	if (!head)
		return nullptr;
	if (!start)
		return nullptr;
	for (Monom* i = start; i; i = i->next)
	{
		if (i->deg == _degr)
		{
			return i;
		}
	}
	return nullptr;
}

Monom* Polinom::SearchMax(Monom* start)
{
	if (!start)
		return nullptr;
	Monom* tmp = start;
	int tmp_max_deg = start->deg;
	for (Monom* i = start->next; i; i = i->next)
	{
		if (i->deg > tmp_max_deg)
		{
			tmp = i;
		}
	}
	return tmp;
}

Monom* Polinom::SearchMax()
{
	if (!head)
		return nullptr;
	if (!head->next)
		return head;
	Monom* tmp = head;
	int max_deg = head->deg;
	for (Monom* i = head; i; i = i->next)
		if (i->deg > max_deg)
		{
			max_deg = i->deg;
			tmp = i;
		}
	return tmp;
}

void Polinom::PlaceBefore(Monom* move, Monom* next)
{
	if (!head)
		return;
	if (move == head)
		head = head->next;
	for (Monom* i = head; i; i = i->next)
		if (i->next == move)
		{
			i->next = move->next;
			break;
		}
	if (next == head)
	{
		move->next = head;
		head = move;
		return;
	}
	for (Monom* i = head; i; i = i->next)
	{
		if (i->next == next)
		{
			i->next = move;
			move->next = next;
			break;
		}
	}
}

void Polinom::PlaceAfter(Monom* move, Monom* prev)
{
	if (!head)
		return;
	if (move == head)
		head = head->next;
	for (Monom* i = head; i; i = i->next)
		if (i->next == move)
		{
			i->next = move->next;
			break;
		}
	Monom* tmp = prev->next;
	prev->next = move;
	move->next = tmp;
}

void Polinom::Sort()
{
	if (!head)
		return;
	if (!head->next)
		return;
	Monom* max = SearchMax();
	PlaceBefore(max, head);
	for (Monom* i = head->next; i; i = i->next)
	{
		Monom* next_max = SearchMax(i);
		if (!next_max)
			break;
		PlaceAfter(next_max, max);
		max = next_max;
	}
}

