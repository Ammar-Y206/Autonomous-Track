// task4.

#include <iostream>
using namespace std;

enum LightColor {
  RED,
  YELLOW,
  GREEN,

};

struct TrafficLight {
    LightColor color;
    int timer_seconds;
};

void updateLight(TrafficLight &light)
{
    switch (light.color) {
    case LightColor::RED:
        light.color = LightColor::GREEN;
        light.timer_seconds = 30;
        break;



    case LightColor::GREEN:
        light.color = LightColor::YELLOW;
        light.timer_seconds = 5;
        break;

    case LightColor::YELLOW:
        light.color = LightColor::RED;
        light.timer_seconds = 60;
        break;

    }

}

string getStateString(TrafficLight& light) {
    switch (light.color) {
    case LightColor::RED:
        return "RED";
        break;
    case LightColor::YELLOW:
        return "YELLOW";
        break;
    case LightColor::GREEN:
        return "GREEN";
        break;

    }
}

int main()
{
    TrafficLight test1;
    test1.color = LightColor::RED;
    updateLight(test1);
    updateLight(test1);


    cout << "Final state: " << getStateString(test1);
}

