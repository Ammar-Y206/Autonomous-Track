#include <iostream>
using namespace std;

int main() {
    char gear = 'D';
    double speed = 0.0;

    switch (gear) {
        case 'P':
            speed = 0;
            cout << "Parking" << endl;
            break;
        case 'D':
            speed = 10;
            cout << "Driving Forward" << endl;
        case 'R':
            speed = -5;
            cout << "Reversing" << endl;
            break;
        default:
            speed = 0;
            cout << "Error: Unknown Gear" << endl;
    }

    cout << "Speed: " << speed << endl;
    return 0;
}
