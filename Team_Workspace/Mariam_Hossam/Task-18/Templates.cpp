#include <iostream>
#include <string>

template <typename T>

void logInfo(T value) {

    std::cout << "[SYSTEM LOG]: " << value << "\n";
}

int main() {
    
    int id = 101;

    logInfo(id); 

    double battery = 12.5;

    logInfo(battery);

    std::string status = "Ready";

    logInfo(status);

    return 0;
}