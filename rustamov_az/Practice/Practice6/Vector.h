#ifndef __Vetor.H
#define __Vector.H
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cmath>
#define PI 3.1415926535
typedef struct
{
	int deg;
	double* x;
}Vector;

Vector* CreateV(int _deg);
void DestroyV(Vector *a);
Vector Sum(Vector *a, Vector *b);
Vector Diff(Vector *a, Vector *b);
double Length(Vector *a);
double Skal(Vector *a, Vector *b);
double Angle(Vector *a, Vector *b);

#endif // !__Vetor.H