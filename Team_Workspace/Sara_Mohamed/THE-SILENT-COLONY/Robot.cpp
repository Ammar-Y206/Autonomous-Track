#include <iostream>
#include <string>
#include "MarsUtils.hpp"
#include "Robot.hpp"

    Robot::Robot(std::string n , int b){
        name = n;
        battery = b;
        sensor = new Sensor<double>(0.0);
    }
    Robot::~Robot(){
        std::cout << "Hardware for " << name << " removed from Heap" << std::endl; 
        delete sensor;
    } 
    void Robot::move(){
    }
    int Robot::getBattery() const {
        return battery;
    }
    void Robot::charge() {
    battery = 100;
    std::cout << " Emergency Charge Triggered!" << std::endl;
} 

    Rover::Rover(std::string n , int b) : Robot(n, b){
        name = n;
        battery = b;
    }
    void Rover::move(){
        if (battery <= 20){
            battery = 100;
            std::cout << "Emergency Charge Triggered!" << std::endl;
        }
        else {
            battery = battery - 5;
            std::cout << name << " is Driving . battery = " << battery << "%" << std::endl;
        }
    }

    Drone::Drone(std::string n , int b) : Robot(n, b){
        name = n;
        battery = b;
    }

   void Drone::move(){
        if (battery <= 20){
            battery = 100;
            std::cout << "Emergency Charge Triggered!" << std::endl;
        }
        else{
            battery = battery - 15;
            std::cout << name << " is Flying . battery = " << battery << "%" << std::endl;
        }
        
    }
