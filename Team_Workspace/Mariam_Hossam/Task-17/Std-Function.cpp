#include <iostream>
#include <functional>

void stopMotors() {
    std::cout << "Motors Stopped\n";
}

int main() {
    std::function<void()> emergency_protocol;

    emergency_protocol = stopMotors;


    if (emergency_protocol) {
        emergency_protocol();
    }

    emergency_protocol = []() {
        std::cout << "ALARM SOUNDING!\n";
    };

    
    if (emergency_protocol) {
        emergency_protocol();
    }

    return 0;
}