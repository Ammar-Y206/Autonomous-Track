#pragma once

#include<string>
#include "MarsUtils.h"


class Robot {
protected:

    std::string RobotName;
    float BatteryPerc;
    float BatteryPerMove;
    Sensor<double>* sensor;

    void SelfRepair();
    bool CheckBattery();

public:

    Robot();
    Robot(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove);
    virtual  ~Robot();

  std::string getRobotName();
    void setRobotName(std::string _RobotName);

     float getBatteryPerc();
     void setBatteryPerc(float _BatteryPerc);

     float getBatteryPerMove();
     void setBatteryPerMove(float _BatteryPerMove);

     virtual void Move();


};

class Rover :public Robot {
public:
    Rover();
    Rover(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove);
    ~Rover() override;

    void Move() override;


};

class Drone : public Robot {
public:
    Drone();
    Drone(std::string _RobotName, float _BatteryPerc, float _BatteryPerMove);

    ~Drone() override;
    void Move() override;


};
