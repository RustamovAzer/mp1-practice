#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	setlocale(LC_ALL, "Russian");
	char  c;
	int g, nmin, nmax, a, b, n = 0;
	do {
		printf("Выберите, кто будет загадывать число: вы или компьютер\n1 - компьютер загадывает число\n2 - вы загадаете число ");
		scanf_s("%c", &g);
	} while ((g != 1) || (g != 2));
	if (g == 1)
	{
		srand((unsigned int)time(0));
		a = (nmax - nmin) / RAND_MAX*rand() + nmin;
		do {
			printf("ВВедите отгадку\n");
			scanf_s("%d", &b);
			if (b < a) {
				printf("Ваша отгадка меньше загаданного числа\n");
				n += 1;
			}
			else {
				if (b > a) {
					printf("Ваша отгадка больше загаданного числа\n");
					n += 1;
				}
				else break;
			}
		} while (b != a);
		n += 1;
		printf("Поздравляем, вы угадали число\nЗагаданное число - %d\nКоличество попыток - %d", a, n);
	}
	if (g == 2)
	{
		do {
			printf("ВВедите загадываемое число от 1 до 1000");
			scanf_s("%d", b);
		} while ((a < 1) || (a > 1000));

	}	do {
		a = (nmax - nmin) / RAND_MAX*rand() + nmin;
		printf("Отгадка %d\nЕсли загаданное число больше отгадки, введите >\nЕсли меньше - <\nЕсли равно - =");
		scanf_s("%c", c);
		switch (c)
			{
			case '>': {
				n += 1;
				nmin = a;
				break;
			};
			case '<': {
				n += 1;
				nmax = a;
				break;
			};
			case '=':{
				n += 1;
				break;
			}
			default:
				printf("Неверно введена переменная");
				break;
			}

		} while (a != b);
	printf("Компьютер угадал число\nЗагаданное число - %d\nКоличество попыток - %d", b, n);

}