// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <string>
#include"MarsUtils.h"
#include"Robot.h"


int main()
{
   std::shared_ptr <Rover>Rover1 = std::make_shared <Rover>("Rover1", 100, 5);
    auto Drone1 = std::make_shared <Drone>("Drone1", 100, 15);


   std:: vector<std::shared_ptr <Robot>> vRobots;
    vRobots.push_back(Rover1);
    vRobots.push_back(Drone1);
    int i = 0;

    while (i < 10) {
        for (auto& robot : vRobots)
        {
            robot->Move();
           std::cout << "Battery percentage " << robot->getBatteryPerc() << std::endl;

        }
        i++;
    }


}

