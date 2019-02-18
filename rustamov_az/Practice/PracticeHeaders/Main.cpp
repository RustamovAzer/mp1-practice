#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "ArrScanPrint.h"
#include "Sorting.h"
#include "RAG.h"
using namespace std;
int main()
{
	
	setlocale(LC_ALL, "Russian");
	int *arr = 0, *a;
	char name[1024], name2[1024];
	char ch;
	int n;
	printf("������� ���������� ��������� �������\n");
	scanf("%d", &n);
	a = new int[n];
	RAG(a, n);
	printf("������� �������� �����\n");
	scanf_s("%s", &name, 1024);
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
	scanf_s("%s", &name2, 1024);
	ArrPrint(name2, a,  n);
	ArrScan(name2, arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", arr[i]);
	}

}