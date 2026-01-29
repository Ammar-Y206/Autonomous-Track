// task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Thermostat {
private: double target_temp;
public: 
    Thermostat() {};
    void setTempertaure(double temp) {
        if (temp >= 100)
        {
            cout << "WARNING:Too Hot!!" << endl;
            target_temp = 100.0;

        }
        else {
            target_temp = temp;

        }
    }
    double getTemperature() {
        return target_temp;
    }
};

int main()
{
    Thermostat cpu_monitor;
    cpu_monitor.setTempertaure(150.0);
    cout << "temperature: " << cpu_monitor.getTemperature() << endl;

}

