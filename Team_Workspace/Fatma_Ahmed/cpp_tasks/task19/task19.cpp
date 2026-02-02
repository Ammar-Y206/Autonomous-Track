// task19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


namespace Lidar {
	int range = 100;
	void print() {
		cout << "Lidar Range :" << range << endl;

	}
}
namespace Sonar {
	int range = 5;
	void print() {
		cout << "Sonar Range :" << range << endl;

	}
}
int main()
{
	Lidar::print();
	Sonar::print();


}
