#include "STLVector.h"
#include <iostream>

using namespace std;
void main()
{
    vector<int> a = { 1,4,2,7,9,111,0 };
    Inverse(a);
    if (FindMin(a) < FindMax(a))Inverse(a, FindMin(a), FindMax(a));
    else Inverse(a, FindMax(a), FindMin(a));
    for (int i = 0; i < a.size; i++)
        cout << a[i] << " " << endl;


}