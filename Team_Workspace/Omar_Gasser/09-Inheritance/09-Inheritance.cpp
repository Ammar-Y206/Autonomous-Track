#include <iostream>
using namespace std;

class Vehicle {
protected:
    double speed;

public:
    void setSpeed(double s) {
        speed = s;
    }

    void showSpeed() {
        cout << "Current Speed: " << speed << endl;
    }
};

class SportsCar : public Vehicle {
public:
    void turboBoost() {
        speed *= 2; 
        cout << "TURBO ACTIVATED!" << endl;
    }
};

int main() {
    SportsCar my_car;

    my_car.setSpeed(50);     // Parent method
    my_car.turboBoost();    // Child method
    my_car.showSpeed();     // Parent method

    return 0;
}
