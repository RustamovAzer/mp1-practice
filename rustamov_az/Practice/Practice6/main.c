#include <locale.h>
#include "Vector.h"
main()
{
	setlocale(LC_ALL, "Russian");
	Vector *a, *b, *c, *d, *e;
	int i = 0;
	double l, s, ang;
	a = CreateV(5);
	b = CreateV(5);
	c = CreateV(7);
	DestroyV(b);
	b = CreateV(5);
	for ( i; i < a.deg; i++)
	{
		a.x[i] = i;
		b.x[i] = i + 1;
	}
	d = Sum(a, b);
	e = Diff(a, b);
	l = Length(a);
	printf("%lf", l);
	s = Skal(a, b);
	printf("%lf", s);
	ang = Angle(b, a);
	printf("%lf", ang);

}