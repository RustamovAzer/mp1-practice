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
	printf("��������, ��� ����� ���������� �����: �� ��� ���������\n1 - ��������� ���������� �����\n2 - �� ��������� �����\n ");
    scanf_s("%d", &g);
    } while ((g != 1) || (g != 2));
	if (g == 1)
	{
		srand((unsigned int)time(0));
		mid = (nmax - nmin) / RAND_MAX*rand() + nmin;
		do {
			printf("������� �������\n");
			scanf_s("%d", &b);
			if (b < mid) {
				printf("���� ������� ������ ����������� �����\n");
				n++;
			}
			else {
			if (b > mid) {
				printf("���� ������� ������ ����������� �����\n");
				n++;
			}
			else break;
			}
		} while (b != mid);
		n += 1;
		printf("�����������, �� ������� �����\n���������� ����� - %d\n���������� ������� - %d", mid, n);
	}
	if (g == 2)
	{
		do {
			printf("������� ������������ ����� �� 1 �� 1000");
			scanf_s("%d", &b);
		} while ((mid < 1) || (mid > 1000));

	}	do {
		mid = (nmax - nmin) / 2;
		printf("������� %d\n���� ���������� ����� ������ �������, ������� >\n���� ������ - <\n���� ����� - =", mid);
		scanf_s("%c", &c);
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
			case '=':{
				n += 1;
				break;
			}
			default:
				printf("������� ����� ����");
				break;
			}

		} while (mid != b);
	printf("��������� ������ �����\n���������� ����� - %d\n���������� ������� - %d", b, n);

}