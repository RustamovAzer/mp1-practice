#pragma once
#include <string>
#include "Date.h"
#include "Place.h"
using namespace std;

class Passport
{
    bool ns;      //Пол
    long s;       //Серия
    long num;     //Номер
    string WhoGP; //Кем выдан
    Date dOfGP;   //Когда выдан
    Date dOfBirth;//Дата рождения
    Place pofP;   //Место прописки

public:
    Passport();
    ~Passport();
    //TODO: Чтение из файла
};

