#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
void main()
{
    long input, oginput;
    int n, i, k, j, nmax = 1, nmin = 1, cows, bulls;
    int used[10] = { 0 }, num[10] = { 0 }, ninput[10] = { 0 }, ninused[10] = { 0 };
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    do 
    {
        printf("Введите длину (от 1 до 10) числа \n");
        scanf("%d", &n);
    } while ((n < 0) || (n > 11));
    for (i = 0; i < n; i++) 
	{
        do 
		{
            num[i] = rand() % 10;
        } while ((used[num[i]] == 1) || (num[0] == 0));
        used[num[i]] = 1;
    }
    for (i = 0; i < n; i++)
    {
        nmax *= 10;
    }
    for (i = 0; i < n - 1; i++)
    {
        nmin *= 10;
    }
    while (1) 
	{
        for (i = 0; i < 10; i++)
            ninused[i] = 0;
        printf("Попытайтесь отгадать число \n");
        cows = bulls = 0;
        do 
		{
            printf("Введите %d - значное число с неповторяющимися цифрами  \n ", n);
            scanf("%ld", &input);
            oginput = input;
            if ((input >= nmax) || (input < nmin))
            {
                printf("Вы ввели не %d - значное число \n", n);
                continue;
            }
            k = n - 1;
            for (i = 0; i < n; i++)
            {
                ninput[k] = input % 10;
                ninused[input % 10]++;
                input = input / 10;
                k--;
            }

            for (i = 0; i < 10; i++)
            {
                if (ninused[i] > 1)
                {
                    printf("Цифры в вашем числе повторяются \n");
                    for (i = 0; i < 10; i++)
                    {
                        ninused[i] = 0;
                    }
                    continue;
                };

            }
            break;
        } while (1);
        for (i = 0; i < n; i++) 
		{
            for (j = 0; j < n; j++) 
			{
                if (num[j] == ninput[i]) 
				{
                    if (i == j) bulls++;
                    else cows++;
                }
            }
        }
        printf("Количество коров = %d \n", cows);
        printf("Количество быков = %d \n", bulls);
        if (bulls == n)
            break;
    }
    printf("Загаданное число = %d \n", oginput);
    
}