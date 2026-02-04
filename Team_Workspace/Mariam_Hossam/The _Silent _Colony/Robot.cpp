#include "Robot.hpp"
using namespace std;

Rover::Rover(string n) : Robot(n) {}

void Rover::move() {
    battery -= 5;
    cout << "Rover " << name << " driving (Battery: " << battery << "%)" << endl;
}

Drone::Drone(string n) : Robot(n) {}

void Drone::move() {
    battery -= 15;
    cout << "Drone " << name << " flying (Battery: " << battery << "%)" << endl;
}