#pragma once
#include <string>
#include "Date.h"
#include "Place.h"
using namespace std;

class Passport
{
    bool ns;      //���
    long s;       //�����
    long num;     //�����
    string WhoGP; //��� �����
    Date dOfGP;   //����� �����
    Date dOfBirth;//���� ��������
    Place pofP;   //����� ��������

public:
    Passport();
    ~Passport();
    //TODO: ������ �� �����
};

