#include"Robot.h"
#include<iostream>
//uisng namespace std;


//Robot Class Implementation

Robot::Robot()
    : sensor(new Sensor<double>()) {
}

Robot::Robot(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove)
    : RobotName(_RobotName),
    BatteryPerc(_BatteryPerc),
    BatteryPerMove(_BatteryPerMove),
    sensor(new Sensor<double>())
{
}

Robot::~Robot() {
    delete sensor;
    std::cout << "Hardware for " << RobotName << " Removed from Heap \n ";
};
bool Robot::CheckBattery() {
    if (this->BatteryPerc > 20)
        return true;
    else
        return false;
}

void Robot::SelfRepair() {
    this->BatteryPerc = 100;
    std::cout<<"Emergency charge Triggered\n";
}
std::string Robot::getRobotName() {
    return this->RobotName;
};
 void Robot::setRobotName(std::string _RobotName) {
     this->RobotName = _RobotName;
 };
 float Robot::getBatteryPerc() {
     return BatteryPerc;
 };

 void Robot::setBatteryPerc(float _BatteryPerc) {

     this->BatteryPerc = _BatteryPerc;
 };

 float Robot::getBatteryPerMove() {
     return this->BatteryPerMove;
 };

 void Robot::setBatteryPerMove(float _BatteryPerMove) {
     this->BatteryPerMove = _BatteryPerMove;
 };

 void Robot::Move() {
     if (this->CheckBattery()) {

         this->BatteryPerc = BatteryPerc - (BatteryPerc * (BatteryPerMove / 100.0f));
     }
     else {
         SelfRepair();
     }
 };


//Rover class Implementation 

Rover::Rover() {
    std::cout << "Creating Rover ....\n";
};

Rover::Rover(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove)
    :Robot(_RobotName, _BatteryPerc, _BatteryPerMove) {
    std::cout << "Creating " << _RobotName << " ....\n";
};
Rover::~Rover() {};

void Rover::Move() {
    std::cout << "Drive\n";
    Robot::Move();
};




//Drone Class Implementaion

Drone::Drone() {
    std::cout << "Creating Rover ....\n";
};

Drone::Drone(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove) : Robot(_RobotName, _BatteryPerc, _BatteryPerMove) {
   std::cout << "Creating " << _RobotName << " ....\n";
};
Drone::~Drone() {};

void Drone::Move() {
  std::cout << "Fly\n";
    Robot::Move();
}