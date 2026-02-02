#include <iostream>

using namespace std;

class Thermostat {
    private:
        double target_temp;

    public:
    
        Thermostat() {
            target_temp = 20.0;
        }

        void setTemperature(double temp) {
            if (temp > 100.0) {
                
                cout << "WARNING: Too Hot!" << endl; 
                target_temp = 100.0;
            } else {
                target_temp = temp;
            }
        }

        double getTemperature() {
            return target_temp;
        }
};

int main() {
    Thermostat cpu_monitor;
    
    cpu_monitor.setTemperature(150.0);
    
    cout << cpu_monitor.getTemperature() << endl;

    return 0;
}