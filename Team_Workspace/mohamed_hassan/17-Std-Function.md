#include <iostream>
#include <functional>
using namespace std;

void stopMotors() {
    cout << "Motors Stopped" << endl;
}

int main() {
    function<void()> emergency_protocol;

    emergency_protocol = stopMotors;
    emergency_protocol(); 


    emergency_protocol = []() { cout << "ALARM SOUNDING!" << endl; };
    emergency_protocol(); 
}
