#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define K 10

void quick_split(int *a, int *i, int *j, int p)
{
    int tmp;
    do
    {
        while (*(a+(*i)) < p) (*i)++;
        while (*(a + (*j)) > p) (*j)--;
        if ((*i) < (*j))
        {
            tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while ((*i) < (*j));
}
void quick_sort(int *a, int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    quick_split(a[0], &i, &j, a[m]);
    if (i < n2)
        quick_sort(a, n1, i);
    if (j > n2)
        quick_sort(a, j, n2);

}
void main()
{

    int i;
    int a[10] = { 0,3,7,3,9,6,8,1,2,4 };
    quick_sort(a, 0, 10);
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    scanf("%d", &i);
}