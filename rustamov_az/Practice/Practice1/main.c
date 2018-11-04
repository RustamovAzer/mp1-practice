#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	int h, d, w;
	double pDVP, pDSP, pWOOD, mBack, mSides, mTop, mShelf, mDoors , Mass;
	setlocale(LC_ALL, "Russian");
	printf("������� ������ ����� � ��(�� 180 �� 220 ��)\n");
	scanf("%d", &h);
	if ((h > 220) || (h < 180))
	{
		printf("������: ������ ����� ������� �� �������� �������\n");
		return;
	}
	printf("������� ������ ����� � ��(�� 80 �� 120 ��)\n");
	scanf("%d", &w);
	if ((w > 120) || (w < 80))
	{
		printf("������: ������ ����� ������� �� �������� �������\n");
		return;
	}
	printf("������� ������� ����� � ��(�� 50 �� 90 ��)\n");
	scanf("%d", &d);
	if ((d > 90) || (d < 50))
	{
		printf("������: ������� ����� ������� �� �������� �������\n");
		return;
	}
	printf("������� ��������� ��� � ��/�^3 \n");
	scanf("%lf", &pDVP);
	if (pDVP <= 0) {
		printf("������: ��������� ������ ���� ������ ����\n");
		return;
	}

	printf("������� ��������� ��� � ��/�^3 \n");
	scanf("%lf", &pDSP);
	if (pDSP <= 0) {
		printf("������: ��������� ������ ���� ������ ����\n");
		return;
	}

	printf("������� ��������� ������ � ��/�^3 \n");
	scanf("%lf", &pWOOD);
	if (pWOOD <= 0) {
		printf("������: ��������� ������ ���� ������ ����\n");
		return;
	}
	mBack = (h * w * 0.5 * pDVP);
	mSides = (2 * h * d* 1.5 * pDSP);
	mTop = (2 * w * d * 1.5 * pDSP);
	mDoors = (h * w * 1 * pWOOD);
	mShelf = d * (w - 3) * 1.5 * floor(h / 40);
	Mass = (mBack + mSides + mTop + mDoors + mShelf) / 1000000;
	printf("����� �����: %lf �� \n", Mass);
}	
