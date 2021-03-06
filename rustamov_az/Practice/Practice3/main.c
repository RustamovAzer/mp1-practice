#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    setlocale(LC_ALL, "Russian");
    char  c;
    int g, nmin = 1, nmax = 1000, mid, b, n = 0;
    
    do {
    printf("Выберите, кто будет загадывать число: вы или компьютер\n1 - компьютер загадывает число\n2 - вы загадаете число\n ");
    scanf("%d",&g);
    } while ((g != 1) && (g != 2));
    if (g == 1)
    {
        srand((unsigned int)time(0));
        mid = (float)(nmax - nmin) / RAND_MAX*rand() + nmin;
        do {
            printf("Введите отгадку\n");
            scanf("%d", &b);
            if (b < mid) {
                printf("Ваша отгадка меньше загаданного числа\n");
                n++;
            }
            else {
            if (b > mid) {
                printf("Ваша отгадка больше загаданного числа\n");
                n++;
            }
            else break;
            }
        } while (b != mid);
        n += 1;
        printf("Поздравляем, вы угадали число\nЗагаданное число - %d\nКоличество попыток - %d", mid, n);
        return;
    }
    if (g == 2)
    {
        do {
            printf("ВВедите загадываемое число от 1 до 1000\n");
            scanf("%d", &b);
        } while ((b < 1) || (b > 1000));

    }    
    do 
    {
        mid = (nmax + nmin) / 2;
        printf("Отгадка %d\nЕсли загаданное число больше отгадки, введите >\nЕсли меньше - <\nЕсли равно - =\n", mid);
        scanf(" %c", &c);
        switch (c)
        {
        case '>': {
            n += 1;
            nmin = mid + 1;
            break;
        };
        case '<': {
            n += 1;
            nmax = mid - 1;
            break;
        };
        case '=': {
            n += 1;
            break;
        }
        default:
            printf("Неверно введён знак");
            break;
        }

    } while (mid != b);
    printf("Компьютер угадал число\nЗагаданное число - %d\nКоличество попыток - %d", b, n);

}