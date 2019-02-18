#include <iostream>
#include <locale.h>
#include "ArrScanPrint.h"
#include "Sorting.h"
#include "RAG.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int *arr, *a;
	char *name,*name2;
	char ch;
	int n;
	printf("������� ���������� ��������� �������\n");
	scanf("%d", &n);
	a = new int[n];
	RAG(a, n);
	printf("������� �������� �����\n");
	scanf("%s", name);
	ArrPrint(name, a, n);

	printf("1 - ���������� �������\n");
	printf("2 - ����������� ����������\n");
	printf("3 - ���������� ���������\n");
	printf("4 - ���������� ��������\n");
	printf("5 - ������� ���������� (�����)\n");
	scanf("%c", &ch);
	switch (ch)
	{
	case 1:
		selectionSort(a, n);
		break;
	case 2:
		bubbleSort(a, n);
		break;
	case 3:
		insertionSort(a, n);
		break;
	case 4:
		mergeSort(a, n);
		break;
	case 5:
		quickSort(a, n);
		break;
	default:
		break;
	}

	printf("������� �������� ������� �����\n");
	scanf("%s", name2);
	ArrPrint(name2, a,  n);
	ArrScan(name2, arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", arr[i]);
	}

}