#include <iostream>

namespace Lidar {
    
    int range = 100;
    
    void print() {
        std::cout << "Lidar Range: " << range << "\n";
    }
}

namespace Sonar {
    
    int range = 5;
    
    void print() {
        std::cout << "Sonar Range: " << range << "\n";
    }
}

int main() {
    Lidar::print();
    Sonar::print();

    return 0;
}