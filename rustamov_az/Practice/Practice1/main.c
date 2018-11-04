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
	h /= 100.0;
	printf("������� ������ ����� � ��(�� 80 �� 120 ��)\n");
	scanf("%d", &w);
	if ((w > 120) || (w < 80))
	{
		printf("������: ������ ����� ������� �� �������� �������\n");
		return;
	}
	w /= 100.0;
	printf("������� ������� ����� � ��(�� 50 �� 90 ��)\n");
	scanf("%d", &d);
	if ((d > 90) || (d < 50))
	{
		printf("������: ������� ����� ������� �� �������� �������\n");
		return;
	}
	d /= 100.0;
	printf("������� ��������� ��� � ��/�^3 \n");
	scanf("%lf", &pDVP);
	if (pDVP <= 0) 
	{
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
	if (pWOOD <= 0) 
	{
		printf("������: ��������� ������ ���� ������ ����\n");
		return;
	}
	mBack = (h * w * 0.005 * pDVP);
	mSides = (2 * h * d * 0.015 * pDSP);
	mTop = (2 * w * d * 0.015 * pDSP);
	mDoors = (h * w * 0.01 * pWOOD);
	mShelf = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * 0.015 * pDSP;
	Mass = mBack + mSides + mTop + mDoors + mShelf;
	printf("����� �����: %lf �� \n", Mass);
}	
