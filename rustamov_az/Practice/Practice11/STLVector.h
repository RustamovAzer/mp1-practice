#ifndef _STLV_H_ 
#define _STLV_H_ 

#include <vector>

using namespace std;

void Inverse(vector<int>&  x, int front = 0, int back = -1)
{
    if (back == -1) back = x.size - 1;
    int tmp;
    while (front < back)
    {
        tmp = x[front];
        x[front++] = x[back];
        x[back--] = tmp;
    }
}

int FindMin(const vector<int>& x)
{
    int min = 0;
    for (int i = 1; i < x.size; i++)
    {
        if (x[i] < x[min]) min = i;
    }
    return min;
}

int FindMax(const vector<int>& x)
{
    int max = 0;
    for (int i = 1; i < x.size; i++)
    {
        if (x[i] >= x[max]) max = i;
    }
    return max;
}
#endif
