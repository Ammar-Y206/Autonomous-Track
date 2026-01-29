#include <iostream>
#include <string>
using namespace std;

class Thermostat {
private :

    double target_temp;
    
public :
    
    void setTemperature(double temp){
        if (temp>100.0){
            printf("WARNING: Too Hot!");
            target_temp = 100.0;
        }
        else{
            target_temp = temp;
        }
    }
    double getTemperature(){
        return target_temp;
    }

    
};

int main(){
    
    Thermostat cpu_monitor;
    cpu_monitor.setTemperature(150.0);
    cout << "\ntemperature = "<< cpu_monitor.getTemperature() << endl;
}
