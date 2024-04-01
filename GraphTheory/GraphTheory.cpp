// GraphTheory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include "factorial.h"

int main()
{
	std::cout << "Hello World!\n";

	sayHello();

	// Specify the file name
	string fileName = "example.txt";

	// Open the file
	ifstream inputFile(fileName);

	// Check if the file is opened successfully
	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << fileName << endl;
		return 1; // Return an error code
	}

	// Read and print the contents of the file
	string line;
	while (getline(inputFile, line))
	{
		cout << line << endl;
	}

	// Close the file
	inputFile.close();

	return 0;
}
