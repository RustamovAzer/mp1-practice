#pragma once
#include <string>
using namespace std;
class Place
{
public:
    string region;
    string city;
    string home;
    string apartment;
    Place();
    Place(string _region, string _city, string _home, string _apartment) { region = _region; city = _city; home = _home; apartment = _apartment; }
    ~Place();
    //TODO: Чтение из файла
};

