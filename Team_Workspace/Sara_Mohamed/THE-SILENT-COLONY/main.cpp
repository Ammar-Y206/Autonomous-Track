#include <iostream>
#include <vector>
#include <memory>
#include "Robot.hpp"

int main()
{
    std::vector<std::shared_ptr<Robot>> fleet;
    
    fleet.push_back(std::make_shared<Rover>("Rover_1", 100));
    fleet.push_back(std::make_shared<Rover>("Rover_2", 100));
    fleet.push_back(std::make_shared<Drone>("Drone_1", 100));
    
    for (int step = 1 ; step <= 10 ; step++){
        
        for (auto& bot : fleet){
            
            if (bot->getBattery() <= 20) {
                std::cout << "Emergency Charge Triggered!" << std::endl;
                bot->charge();
            }
            else {
                bot->move();
            }
        }
    }
    return 0;
}
