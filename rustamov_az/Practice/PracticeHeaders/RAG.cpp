
#include <stdlib.h>
#include <time.h>
#include "RAG.h"
#define NMAX 1000
#define NMIN 1
void RAG(int *arr, int n)
{
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int)rand()%1000;
	}

}