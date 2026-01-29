
//task2


#include <iostream>
using namespace std;

int main()
{
	char gear = 'D';
	double speed = 0.0;


	switch (gear) {
	case 'P':
		speed = 0;
		cout << "parking...";
		break;

	case 'D':
		speed = 10;
		cout << "Driving...";
		break;
	case 'R':
		speed = -5;
		cout << "Revdersing...";
		break;
	default:
		speed = 0;
		cout << "Error:Unknown Gear";


	}

}

