#include <iostream>
using namespace std;

int main() {
	char gear = 'D';
	double speed = 0.0;

	switch (gear) {
	case 'P':
		speed = 0.0;
		cout << "Parking" << endl;
		break;
	case 'D':
		speed = 10.0;
		cout << "Driving Forward" << endl;
		// rmeoving this break falls down to the R case
		// where it sets the speed from 10 to -5.0 and says both driving Forward
		// and Reversing
		break;
	case 'R':
		speed = -5.0;
		cout << "Reversing" << endl;
		break;
	default:
		speed = 0.0;
		cout << "Gear unkown" << endl;
		break;
	}
	cout << "speed: " << speed << endl;
	return 0;
}
