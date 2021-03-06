#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int sale[9999], basket[9999] = { 0 };
int f = 0;
char code[10][5] = { "0001","0010","0011","0015","0100","0140",
"0200","1000","1010","6000" };
char name[10][10] = { "bed", "dresser", "mirror","carpet","wardrobe",
"bookshelf","sofa","bench","chair","desk" };
int cost[10] = { 2000, 4000, 500, 400, 700, 1000, 4000, 400, 150, 500 };


void rng_arr(int a[], int n, int min, int max)
{
    srand(1);
    int i = 0;
    for (; i < n; i++)
    {
        a[i] = rand() % max + min;
    }
}


void get_name(char* input)
{
    int i;
    f = 0;
    if (strcmp(input, "0001") && strcmp(input, "0010") && strcmp(input, "0011") &&  
        strcmp(input, "0015") && strcmp(input, "0100") &&
        strcmp(input, "140") && strcmp(input, "0200") && strcmp(input, "1000") && 
        strcmp(input, "1010") && strcmp(input, "6000"))
    {
        printf("Товара с таким штрих-кодом нет в магазине\n");

        printf("%s\n", input);
        printf("%d\n", atoi(input));

    }

    else
    {
        printf("Наименование товара: ");
        for (i = 0; i < 10; i++)
            if (atoi(input) == (atoi)(code[i]))
                printf("%s", name[i]);
        printf("\n");
        f = 1;
    }
}




void main()
{
    
    char c;
    long total_price = { 0 }, total_sale = { 0 };
    char input[4];
    int i = 0, j= 0, id = 0;
    setlocale(LC_ALL, "Russian");
    srand(1);
    rng_arr(sale, 9998, 1, 50);


    printf("Касса\n");
    printf("Введите цифру, соответствующую желаемой команде \n");
    printf("1 - Сканировать товар \n");
    printf("2 - Вывести описание отсканированного товара \n");
    printf("3 - Добавить данные о товаре в чек \n");
    printf("4 - Сформировать чек за покупку \n");
    printf("5 - Сформировать итоговую сумму к оплате \n");
    printf("Ctrl + C - Завершить работу программы \n");

    do
    {
        scanf("%c", &c);
        switch (c)
        {
        case '1':
            printf("Введите штрих-код продукта \n");
            scanf("%s",&input);
            id = atoi(input);
            break;

        case '2':
            if (id == 0)
            {
                printf("Просканируйте товар чтобы получить описание\n");
            }
            else
            {
                get_name(input);
                if (f == 1)
                {
                    printf("Цена без скидки = %d руб.\nСкидка = %d%%,\n", cost[id], sale[id]);
                    printf("Цена со скидкой = %f руб.\n", cost[id] * (1 - (sale[id] / 100.0f)));
                }
            }
            break;
        case '3':
            if (id == 0)
                printf("Просканируйте товар чтобы добавить его в чек\n");
            else
                basket[id]++;
            break;
        case '4':
            printf("Чек:\n");
            for (i = 0; i < 9998; i++)
            {
                for (j = 0; j < 10; j++);
                {
                    if (atoi(code[j]) == i)
                    {
                        if (basket[i] != 0)
                        {
                            get_name(code[j]);
                            printf("Цена без скидки за единицу = %d руб,\n", cost[i]);
                            printf("Количество товаров - %d штук \n", basket[i]);
                            printf("Общая стоимость за товар = %d руб.\n", cost[i] * basket[i]);
                            total_price += cost[i];
                            total_sale += cost[i] * (float)(sale[i] / 100.00);
                        }
                    }
                }
                
            }
            printf("Общая стоимость = %ld\n", total_price);
            printf("Суммарная скидка = %ld\n", total_sale);
            printf("Итого = %ld\n", total_price - total_sale);

            break;

        case '5':
            printf("Итого = %ld\n", total_price - total_sale);
            break;


        }
    } while (1);

}