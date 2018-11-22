#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int price[9999], sale[9999], basket[9999] = { 0 };
int f = 0;
char name[9998][10];


void rng_arr(int a[],int n,int min,int max)
{
    srand(1);
    int i = 0;
    for (; i < n; i++)
    {
        //a[i] = (max - min) / (float)(RAND_MAX * rand() + min);
        a[i] = rand() % max;
    }
}


void get_name(int id)
{
    int i;
    name[1][0] = 'b';
    name[1][1] = 'e';
    name[1][2] = 'd';

    name[10][0] = 'd';
    name[10][1] = 'r';
    name[10][2] = 'e';
    name[10][3] = 's';
    name[10][4] = 's';
    name[10][5] = 'e';
    name[10][6] = 'r';

    name[11][0] = 'm';
    name[11][1] = 'i';
    name[11][2] = 'r';
    name[11][3] = 'r';
    name[11][4] = 'o';
    name[11][5] = 'a';

    name[15][0] = 'c';
    name[15][1] = 'a';
    name[15][2] = 'r';
    name[15][3] = 'p';
    name[15][4] = 'e';
    name[15][5] = 'd';

    name[100][0] = 'w';
    name[100][1] = 'a';
    name[100][2] = 'r';
    name[100][3] = 'd';
    name[100][4] = 'r';
    name[100][5] = 'o';
    name[100][6] = 'b';
    name[100][7] = 'e';

    name[140][0] = 'b';
    name[140][1] = 'o';
    name[140][2] = 'o';
    name[140][3] = 'k';
    name[140][4] = 's';
    name[140][5] = 'h';
    name[140][6] = 'e';
    name[140][7] = 'l';
    name[140][8] = 'f';

    name[200][0] = 's';
    name[200][1] = 'o';
    name[200][2] = 'f';
    name[200][3] = 'a';

    name[1000][0] = 'b';
    name[1000][1] = 'e';
    name[1000][2] = 'n';
    name[1000][3] = 'c';
    name[1000][4] = 'h';

    name[1010][0] = 'c';
    name[1010][1] = 'h';
    name[1010][2] = 'a';
    name[1010][3] = 'i';
    name[1010][4] = 'r';

    name[6000][0] = 'd';
    name[6000][1] = 'e';
    name[6000][2] = 's';
    name[6000][3] = 'k';

    if ((id != 1) && (id != 10) && (id != 11) && (id != 15) && (id != 100) &&
        (id != 140) && (id != 200) && (id != 1000) && (id != 1010) && (id != 6000))
    {
        printf("Товара с таким штрих-кодом нет в магазине\n");

    }
        
    else
    {
        printf("Наименование товара: ");
        for (i = 0; i < 10; i++)
            printf("%c", name[id][i]);
        printf("\n");
        f = 1;
    }
}




void main()
{
    setlocale(LC_ALL, "Russian");
    srand(1);
	char c;
    long total_price = 0, total_sale = 0;
    int i = 0, id = 0;
    rng_arr(price, 9998, 1, 1000);
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
        switch(c)
        {
            case '1':
                printf("Введите штрих-код продукта \n");
                scanf("%d", &id);
                break;

            case '2':
                if (id == 0)
                {
                    printf("Просканируйте товар чтобы получить описание\n");
                }
                else
                {
                    get_name(id);
                    if (f == 1)
                    {
                    printf("Цена без скидки = %d руб.\nСкидка = %d%%,\n", price[id], sale[id]);
                    printf("Цена со скидкой = %f руб.\n", price[id] * (1 - (sale[id] / 100.0f)));
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
                    if (basket[i] != 0)
                    {
                        get_name(i);
                        printf("Цена без скидки за единицу = %d руб,\n ", price[i]);
                        printf("Количество товаров - %d штук \n", basket[i]);
                        printf("Общая стоимость за товар = %d руб.\n", price[i] * basket[i]);
                        total_price += price[i];
                        total_sale += price[i] * (float)(sale[i] / 100.00);
                    }
                }
                printf("Общая стоимость = %ld\n", total_price);
                printf("Суммарная скидка = %ld\n", total_sale);
                printf("Итого = %ld\n", total_price - total_sale);

                break;
            case 5:
                printf("Итого = %ld\n", total_price - total_sale);
                break;

                    
        }
    }while(1);

}
