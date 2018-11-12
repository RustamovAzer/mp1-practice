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

    printf("Касса\n");
    printf("Введите цифру, соответствующую желаемой команде \n");
    printf("1 - Сканировать товар \n");
    printf("2 - Вывести описание отсканированного товара \n");
    printf("3 - Добавить данные о товаре в чек \n");
    printf("4 - Сформировать итоговую сумму к оплате \n");

    

}