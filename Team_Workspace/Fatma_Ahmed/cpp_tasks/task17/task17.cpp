// task17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
using namespace std;


void stopMotors() { cout << "Motors Stopped\n"; }

int main()
{
	std::function<void()> emergency_portocol;

	
	emergency_portocol = stopMotors;

	emergency_portocol();

	emergency_portocol = []() {cout << "ALARM SOUNDING!"; };

	emergency_portocol();
}

