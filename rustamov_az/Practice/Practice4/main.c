#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void rng(int a[],int n,int min,int max)
{
    int i = 0;
    srand(1);
    for (; i < n; i++)
    {
        a[i] = ((max - min) / (RAND_MAX * rand() + min));

    }
}



void main()
{
    setlocale(LC_ALL, "Russian");
    int i;
    int price[9998], sale[9998];
    rng(price[], 9998, 1, INT_MAX);
    rng(sale[], 9998, 1, 50);

    printf("�����\n");
    printf("������� �����, ��������������� �������� ������� \n");
    printf("1 - ����������� ����� \n");
    printf("2 - ������� �������� ���������������� ������ \n");
    printf("3 - �������� ������ � ������ � ��� \n");
    printf("4 - ������������ �������� ����� � ������ \n");

    

}