#include <iostream>
#include <locale.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "ArrReadWrite.h"
#include "Sorting.h"
#include "RAG.h"
using namespace std;
int main()
{
	
	setlocale(LC_ALL, "Russian");
	int *arr , *a ;
	char name[24], name2[24];
	char ch;
	int n;
	printf("������� ���������� ��������� �������\n");
	scanf("%d", &n);
	a = new int[n];
	RAG(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", a[i]);
	}
	printf("������� �������� �����\n");
	scanf("%s", name);
	ArrWrite(name, a, n);

	printf("1 - ���������� �������\n");
	printf("2 - ����������� ����������\n");
	printf("3 - ���������� ���������\n");
	printf("4 - ���������� ��������\n");
	printf("5 - ������� ���������� (�����)\n");
	scanf("\n%c", &ch);
	printf("%c\n", ch);
	switch (ch)
	{
	case '1':
		selectionSort(a, n);
		break;
	case '2':
		bubbleSort(a, n);
		break;
	case '3':
		insertionSort(a, n);
		break;
	case '4':
		mergeSort(a, n);
		break;
	case '5':
		quickSort(a, n);
		break;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", a[i]);
	}
	printf("������� �������� ������� �����\n");
	scanf("%s", name2);
	ArrWrite(name2, a, n);

	arr = new int[n];
	memset(arr, 0, n * sizeof(int));

	ArrRead(name2, arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d \n", a[i]);
	}
	scanf("%d", &n);
}