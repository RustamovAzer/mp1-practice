#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    long input;
    int n, i, k, j, nmax, nmin, cows, bulls;
    int used[10] = { 0 }, num[10] = { 0 }, ninput[10] = { 0 }, ninused[10] = { 0 };
    do {
        printf("¢夨⥠䫨�(1 䮠10) 稱렠\n");
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

    nmax = pow(10, n);
    nmin = pow(10, (n - 1));
    while (1) 
	{
        for (i = 0; i < 10; i++)
            ninused[i] = 0;
        printf("Ϯﻲੲ屼 ठ⼠稱뮠\n");
        cows = bulls = 0;
        do 
		{
            printf("¢夨⥠%d - 筠筮堷豫 �쨱贰ନ  \n ", n);
            scanf("%ld", &input);
        } while ((input >= nmax) || (input <= nmin));
        k = n - 1;
        for (i = 0; i < n; i++) {
            ninput[k] = input % 10;
            ninused[input % 10]++;
            input = input / 10;
            k--;
        }

        for (i = 0; i < 10 ; i++) 
        {
            if (ninused[i] > 1)
            {
                printf("֨䰻 ⠢ล젷豫堯n");
                break;
            };
            
        }
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
        printf("ʮ먷屲⮠ꮰ= %d \n", cows);
        printf("ʮ먷屲⮠Ừ= %d \n", bulls);
        if (bulls == n)
            break;
    }
    printf("Ǡ㠤୭稱뮠= %d \n", input);

}