#include <iostream>
#include <string>
#pragma once 
#include "MarsUtils.hpp"
using namespace std;

class Robot{

    protected:
      Sensor<double>* sensor;
      string name;
      double battery;
    
    public:
      Robot(string n) {
        name = n;           
        battery = 100.0;   
        sensor = new Sensor<double>(0.0);
    }
    
      virtual ~Robot(){
        delete sensor; 
        cout << "Hardware for " << name << " removed from Heap." << endl;
      }
      virtual void move() = 0;
      
    double getBattery() const { return battery; }

      void recharge() {
        battery = 100.0;
        cout << "Emergency Charge Triggered! " << name << " is now at 100%." << endl;
    }
    
    string getName() const { return name; }
};

class Rover : public Robot {

    public:
      Rover(string n);
      void move() override;
};

class Drone : public Robot {
    public:
      Drone(string n);
      void move() override;
};