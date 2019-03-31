
#include "Vector.h"

typedef struct
{
	int deg;
	double* x;
}Vector;

Vector* CreateV(int _deg)
{
	Vector* tmp = (Vector*)malloc(sizeof(Vector)*_deg);
	return tmp;
}

void DestroyV(Vector *a)
{
	a->deg = 0;
	free(a->x);
}

Vector Sum(Vector *a, Vector *b)
{
	Vector* tmp = (Vector*)malloc(sizeof(Vector)*a->deg);
	int i = 0;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return *a;
	}
	for (i; i < a->deg; i++)
	{
		tmp->x[i] = a->x[i] + b->x[i];
	}
	return *tmp;
}

Vector Diff(Vector *a, Vector *b)
{
	Vector* tmp = (Vector*)malloc(sizeof(Vector)*a->deg);
	int i = 0;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return *a;
	}
	for (i; i < a->deg; i++)
	{
		tmp->x[i] = a->x[i] - b->x[i];
	}
	return *tmp;
	
}

double Length(Vector *a)
{
	double l = 0.0;
	int i = 0;
	for (i; i < a->deg; i++)
	{
		l += a->x[i] * a->x[i];
	}
	return l;
}

double Skal(Vector *a, Vector *b)
{
	double skal = 0.0;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return 0.0;
	}
	int i = 0;
	for (i; i < a->deg; i++)
	{
		skal += a->x[i] * b->x[i];
	}
	return skal;
}
double Angle(Vector *a, Vector *b)
{
	double ang, la, lb, skal;
	if (a->deg != b->deg)
	{
		printf("Размерности векторов не совпадают");
		return 0.0;
	}
	la = Length(a);
	lb = Length(b);
	skal = Skal(a, b);
	ang = acos((skal / (la*lb))) * PI;
	return ang;
}
