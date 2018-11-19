#include <stdio.h>
#include <locale.h>
#define K 5

//Сортировка выбором
void choose_sort(int a[], int n)
{
    int i, j, min, minidx;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        minidx = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minidx = j;
            }
        }
        a[minidx] = a[j];
        a[i] = min;
    }

}
//Сортировка вставками
void insert_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j]>temp))
        {
            a[j + 1] = a[j];
            a[j--] = temp;
        }
    }

}
//Пузырьковая сортировка
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - 1; j++)
        { 
            if (a[j - 1] > a[j])
            {
                temp = a[j];
                a[j] = a[j - 1];
            }
        }
    }
}
//Сортировка подсчётом
void counting_sort(int a[], int n)
{
    int count[K];
    int i, j, idx = 0;
    for (i = 0; i < n; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[a[i]]++;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[idx++] = i;
    }

}