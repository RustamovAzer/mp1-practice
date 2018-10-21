#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void main()
{
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "Russian");
	long input;
	int n, i, k, j, nmax, nmin, cows, bulls;
	int used[10] = { 0 }, num[10] = { 0 }, ninput[10] = { 0 }, ninused[10] = { 0 };
	do {
		printf("������� ����� (�� 1 �� 10) ����� \n");
		scanf("%d", &n);
	} while ((n < 0) || (n > 11));
	for (i = 0; i < n; i++) {
		do {
			num[i] = rand() % 10;
		} while ((used[num[i]] == 1) || (num[0] == 0));
		used[num[i]] = 1;
	}

	nmax = pow(10, n);
	nmin = pow(10, (n - 1));
	while (1) {
		for (i = 0; i < 10; i++)
			ninused[i] = 0;
		printf("����������� �������� ����� \n");
		cows = bulls = 0;
		do {
			printf("������� %d - ������� ����� � ���������������� �������  \n ", n);
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
				printf("����� � ����� ����� ����������� \n");
				break;
			};
			
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (num[j] == ninput[i]) {
					if (i == j) bulls++;
					else cows++;
				}
			}
		}
		printf("���������� ����� = %d \n", cows);
		printf("���������� ����� = %d \n", bulls);
		if (bulls == n)
			break;
	}
	printf("���������� ����� = %d \n", input);

}