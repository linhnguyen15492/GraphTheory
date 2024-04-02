#pragma once
#include <iostream>
using namespace std;

int factorial(int number)
{
	int iteration, factorial = 1;
	for (iteration = 1; iteration <= number; iteration++)
	{
		factorial = factorial * iteration;
	}
	return factorial;
}

void sayHello()
{
	cout << "Welcome to CSC00008 LTDT Project!" << endl;
}
