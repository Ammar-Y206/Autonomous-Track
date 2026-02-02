// task14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <map>

using namespace std;


int main()
{
	map<string, int>test_map;
	test_map.insert({ "Wheel",4 });
	test_map.insert({ "Motor",2 });
	test_map.insert( { "Sensor",5 });


	test_map["Wheel"]--;
	test_map["Motors"] += 3;


	cout << test_map["Laser"]<<endl;
	cout << test_map["Wheel"]<<endl;
	cout << test_map["Motor"]<<endl;
	cout << test_map["Sensor"]<<endl;






}

