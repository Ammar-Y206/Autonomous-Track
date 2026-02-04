
#include <iostream>
#include <vector>
#include <memory> 
#include "Robot.hpp"

using namespace std;

int main() {
    
    vector<shared_ptr<Robot>> fleet;

    fleet.push_back(make_shared<Rover>("Curiosity"));
    fleet.push_back(make_shared<Drone>("Ingenuity"));
    fleet.push_back(make_shared<Rover>("Perseverance"));

    cout << "Mission Started on Mars" << endl;

    for (int step = 1; step <= 8; ++step) {
        cout << "\n[Step " << step << "]" << endl;
        
        for (auto& bot : fleet) {
            bot->move();

            if (bot->getBattery() <= 20) {
                cout << " >> WARNING: Low battery for " << bot->getName() << "!" << endl;
                bot->recharge();
            }
        }
    }

    cout << "\n Mission Accomplished. Return to Base." << endl;

    fleet.clear(); 

    return 0;
}