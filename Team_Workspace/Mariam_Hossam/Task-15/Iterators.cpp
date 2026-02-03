#include <iostream>
#include <vector>

int main() {
    
    std::vector<int> readings = {10, -5, 20, -1, 30};

    for (auto it = readings.begin(); it != readings.end(); ) {
    
        if (*it < 0) {

            it = readings.erase(it); 
        } 
        else {
            
            it++;
        }
    }

    std::cout << "Cleaned Readings: ";
    for (int val : readings) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}