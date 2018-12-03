#include <stdio.h>
#include <locale.h>
#define K 5

// Сортировка выбором (1)
void choose_sort(int a[], int n)
{
    int i, j, min, minidx;
    for (i = 0; i < n - 1; i++)
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
        a[minidx] = a[i];
        a[i] = min;
    }

}
// Сортировка вставками (2)
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
// Пузырьковая сортировка (3)
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i - 1; j++)
        { 
            if (a[j - 1] > a[j])
            {
                temp = a[j];
                a[j] = a[j - 1];
            }
        }
    }
}
// Сортировка подсчётом (4)
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

//Сортировка Хоара(быстрая) (5)
void quick_sort(int a, int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    quick_split(a, &i, &j, m);
    if (i > n1)
        quick_sort(a, n1, i);
    if (j < n2)
        quick_sort(a, j, n2);
}
void quick_split(int a[], int *i, int *j, int p)
{
    int tmp;
    do
    {
        while (a[*i] < p) (*i)++;
        while (a[*j] > p) (*j)--;
        if (*i <= *j)
        {
            tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i < *j);
} 

//Сортировка слиянием (6)
void merge_sort(int a[], int l, int r)
{
    int m;
    if (l >= r)return;
    m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
}
void merge(int a[], int l, int m, int r)
{
    int *c, k;
    c = (int*)malloc((r-l+1)*sizeof(int));
    int  i = l, j = m + 1;
    do
    {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
        if (i = m+1)
            while (j <= r)
                c[k++] = a[j];
        if (j > r)
            while (i <= m);
                c[k++] = a[i];
    } while ((i < m) && (j < r));

}

void main()
{

    int a[10] = {6,3,8,3,9,6,8,9,311,1};
    int i;
    char c;
    scanf("%c", &c);
    switch (c)
    {
    case '1':
    {
        choose_sort(a, 10);
        for (i = 0; i < 10; i++)
            printf("%d\n", a);
    }
        case '2'
    }
    
    
}