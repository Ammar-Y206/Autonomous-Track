//task9

#include <iostream>
using namespace std;

class Vehicle {
protected:
    double speed;
public:
    void setSpeed(double s)
    {
        this->speed = s;

    }
    void showSpeed() {
        cout << "Current Speed: " << speed<<endl;

    }
};

class SportsCar :public Vehicle {
public:
    void turboBoost() {
        this->speed *= 2;
        cout << "TURBO ACTIVATED\n";

    };

};
int main()
{
    SportsCar TestCar;
    TestCar.setSpeed(50);
    TestCar.turboBoost();
    TestCar.showSpeed();

}

