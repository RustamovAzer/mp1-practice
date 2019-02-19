#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include "Sorting.h"

void selectionSort(int a[], int n)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i<n; i++) {
		j = i;
		for (int k = i; k<n; k++) {
			if (a[j]>a[k]) {
				j = k;
			}
		}
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
void bubbleSort(int a[], int n)
{
	int tmp = 0;
	for (int i = 0; i<n; i++) {
		for (int j = (n - 1); j >= (i + 1); j--) {
			if (a[j]<a[j - 1]) {
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
void insertionSort(int a[], int nD)
{
	int key = 0;
	int i = 0;
	for (int j = 1; j<nD; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i]>key) {
			a[i + 1] = a[i];
			i = i - 1;
			a[i + 1] = key;
		}
	}
}
void mergeSort(int a[], int nD)
{
	if (nD>1) {
		int middle = nD / 2;
		int rem = nD - middle;
		int* L = new int[middle];
		int* R = new int[rem];
		for (int i = 0; i<nD; i++) {
			if (i<middle) {
				L[i] = a[i];
			}
			else {
				R[i - middle] = a[i];
			}
		}
		mergeSort(L, middle);
		mergeSort(R, rem);
		merge(a, nD, L, middle, R, rem);
	}
}
void merge(int merged[], int nD, int L[], int nL, int R[], int nR) {
	int i = 0;
	int j = 0;
	while (i<nL || j<nR) {
		if (i<nL & j<nR) {
			if (L[i] <= R[j]) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i<nL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j<nR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}
void quickSort(int a[], int const n)
{
	int const nD = n;
	int pivot = 0;
	int ind = nD / 2;
	int i, j = 0, k = 0;
	if (nD>1) {
		int* L = new int[nD];
		int* R = new int[nD];
		pivot = a[ind];
		for (i = 0; i<nD; i++) {
			if (i != ind) {
				if (a[i]<pivot) {
					L[j] = a[i];
					j++;
				}
				else {
					R[k] = a[i];
					k++;
				}
			}
		}
		quickSort(L, j);
		quickSort(R, k);
		for (int cnt = 0; cnt<nD; cnt++) {
			if (cnt<j) {
				a[cnt] = L[cnt];;
			}
			else if (cnt == j) {
				a[cnt] = pivot;
			}
			else {
				a[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}