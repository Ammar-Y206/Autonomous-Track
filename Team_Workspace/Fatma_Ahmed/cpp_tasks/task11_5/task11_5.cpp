// task12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
	int* database = nullptr;


	database = new int[5];

	for (int i = 0; i < 5; i++)
	{
		database[i] = i * 10;

	}

	for (int i = 0; i < 5; i++)
	{
		cout << database[i] << endl;

	}

	delete[] database;
	database = nullptr;

  
}

