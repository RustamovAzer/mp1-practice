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
		printf("��������, ��� ����� ���������� �����: �� ��� ���������\n1 - ��������� ���������� �����\n2 - �� ��������� ����� ");
		scanf_s("%c", &g);
	} while ((g != 1) || (g != 2));
	if (g == 1)
	{
		srand((unsigned int)time(0));
		a = (nmax - nmin) / RAND_MAX*rand() + nmin;
		do {
			printf("������� �������\n");
			scanf_s("%d", &b);
			if (b < a) {
				printf("���� ������� ������ ����������� �����\n");
				n += 1;
			}
			else {
				if (b > a) {
					printf("���� ������� ������ ����������� �����\n");
					n += 1;
				}
				else break;
			}
		} while (b != a);
		n += 1;
		printf("�����������, �� ������� �����\n���������� ����� - %d\n���������� ������� - %d", a, n);
	}
	if (g == 2)
	{
		do {
			printf("������� ������������ ����� �� 1 �� 1000");
			scanf_s("%d", b);
		} while ((a < 1) || (a > 1000));

	}	do {
		a = (nmax - nmin) / RAND_MAX*rand() + nmin;
		printf("������� %d\n���� ���������� ����� ������ �������, ������� >\n���� ������ - <\n���� ����� - =");
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
				printf("������� ������� ����������");
				break;
			}

		} while (a != b);
	printf("��������� ������ �����\n���������� ����� - %d\n���������� ������� - %d", b, n);

}