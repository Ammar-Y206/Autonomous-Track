#pragma once
#include <iostream>
#include <string>
#include "MarsUtils.hpp"

class Robot{
    
protected :

    std::string name;
    int battery;
    Sensor<double>* sensor;

public :

    Robot(std::string n , int b);    
    ~Robot();
    
    virtual void move() = 0;
    int getBattery() const;
    void charge();
};

class Rover : public Robot {
    public :
    Rover(std::string n , int b);
    void move() override ;
};

class Drone : public Robot {
    public :
    Drone(std::string n , int b);
    void move() override ;
};
