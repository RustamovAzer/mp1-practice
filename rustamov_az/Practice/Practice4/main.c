#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void rng_arr(int a[],int n,int min,int max)
{
    int i = 0;
    srand(1);
    for (; i < n; i++)
    {
        a[i] = (max - min) / (RAND_MAX * rand() + min);

    }
}




void main()
{
    setlocale(LC_ALL, "Russian");
    int c, i, id = -1;
    int price[9998], sale[9998], basket[9998] = {0};
    rng_arr(price, 9998, 1, 100000);
    rng_arr(sale, 9998, 1, 50);

    printf("�����\n");
    printf("������� �����, ��������������� �������� ������� \n");
    printf("1 - ����������� ����� \n");
    printf("2 - ������� �������� ���������������� ������ \n");
    printf("3 - �������� ������ � ������ � ��� \n");
    printf("4 - ������������ �������� ����� � ������ \n");
    scanf("%d", &c);
    swich (c)
    {
        case 1:
            printf("������� �����-��� �������� \n")
            scanf("%d", &id);
        case 2:

        case 3:
            if(id == -1)
                printf("������������� ����� ����� �������� ��� � ���")
            else
                basket[id]++;
        case 4:
            for (i = 0; i < 9998;i++)
                if basket[i] != 0
                {
                    //���������� ������������
                    printf("")
                }
           
           
        case 5:

    }
}