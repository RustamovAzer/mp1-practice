#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    d = CreateV(7);
    e = CreateV(7);
	DestroyV(b);
	b = CreateV(5);
	for ( i; i < a->deg; i++)
	{
		a->x[i] = i;
		b->x[i] = i + 1;
	}
    printf("������ �:");
    Print(a);
    printf("������ b:");
    Print(b);
	*d = Sum(a, b);
    printf("������ d(����� a � b):");
    Print(d);
	*e = Diff(a, b);
    printf("������ e(�������� a � b):");
    Print(e);
	printf("����� � = %lf\n", Length(a));
    printf("����� b = %lf\n", Length(b));
    printf("����� d(����� a � b) = %lf\n", Length(d));
    printf("����� e(�������� a � b) = %lf\n", Length(e));
	s = Skal(a, b);
	printf("��������� ������������ a � b = %lf\n", s);
	ang = Angle(b, a);
	printf("���� ����� a � b = %lf\n", ang);
    scanf_s("%lf",&l);

}