#include "ArrScanPrint.h"

void ArrPrint(const char* name, int* arr, int n)
{
	FILE* f;
	f = fopen(name, "wb");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d", arr[i]);
	}
}

void ArrScan(const char* name, int* arr, int n)
{
	FILE* f;
	f = fopen(name, "rb");
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &(arr[i]));
		printf("%d", arr[i]);
	}
}