#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<float> robot_speeds = {1.5, 5.5, 0.5, 3.2};

    for (float s : robot_speeds) std::cout << s << " ";

    std::sort(robot_speeds.begin(), robot_speeds.end(), [](float a, float b) {

        return a > b; 
    });

    std::cout << "Sorted (High to Low): ";
    
    for (float speed : robot_speeds) {
        std::cout << speed << " ";
    }
    std::cout << "\n";

    return 0;
}