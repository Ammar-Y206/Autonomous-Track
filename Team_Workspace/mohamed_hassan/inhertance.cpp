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
        speed = speed * 2;
        cout << "TURBO ACTIVATED!" << endl;
    }
};

int main() {
    SportsCar car;

    car.setSpeed(50);
    car.turboBoost();
    car.showSpeed();

    return 0;
}
