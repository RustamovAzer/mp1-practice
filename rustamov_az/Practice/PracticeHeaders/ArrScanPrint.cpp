#include "ArrScanPrint.h"

void ArrPrint(const char* name, int* arr, int n)
{
	FILE* f;
	f = fopen(name, "wb");
	fprintf(f, "\d", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "\d", arr[i]);
	}
}

void ArrScan(const char* name, int* arr)
{
	FILE* f;
	int n;
	f = fopen(name, "rb");
	fscanf(f, "\d", n);
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "\d", arr[i]);
	}
}