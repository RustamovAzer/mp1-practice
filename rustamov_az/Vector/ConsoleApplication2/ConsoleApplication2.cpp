#include <iostream>
#include "Vector.h"
int main()
{
	int* elements = new int[50];
	for (int i = 0; i < 50; i++)
	{
		elements[i] = i;
	}
	Vector* v1 = new Vector;
	Vector* v2 = new Vector(5);
	Vector* v3 = new Vector(elements, 5);
	v1->PrintVector("Empty\n");
	std::cout << "--------------------\n";
	v2->PrintVector();
	std::cout << "--------------------\n";
	v3->PrintVector();
	std::cout << "--------------------\n";
}