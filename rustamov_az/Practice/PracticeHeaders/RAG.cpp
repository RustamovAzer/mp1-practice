
#include <stdlib.h>
#include <time.h>
#include "RAG.h"
#define NMAX 1000
#define NMIN 1
void RAG(int *arr, int n)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int)(NMAX - NMIN) / RAND_MAX*rand() + NMIN;
	}

}