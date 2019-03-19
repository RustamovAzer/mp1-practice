#include "ArrReadWrite.h"

void ArrWrite(const char* name, int* arr, int n)
{
	FILE* f;
	f = fopen(name, "wb");
	fwrite(&n, sizeof(int), 1, f);
	fwrite(arr, n*sizeof(int), n, f);
	fclose(f);
}

void ArrRead(const char* name, int* arr)
{
	int n;
	FILE* fo;
	fo = fopen(name, "rb+");
	fread(&n, 1*sizeof(int), 1, fo);
	printf("%d", n);
	fread(arr, n*sizeof(int), n, fo);
	fclose(fo);
}