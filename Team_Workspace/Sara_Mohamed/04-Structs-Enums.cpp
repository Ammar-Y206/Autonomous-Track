#include <iostream>
#include <string>
using namespace std;

enum class LightColor {
    RED,
    YELLOW,
    GREEN,
};

struct TrafficLight {
    LightColor color;
    int timer_seconds;
};

void updateLight(TrafficLight &light){
    switch(light.color){
        case LightColor::RED:light.color=LightColor::GREEN; Light.timer_seconds=30; break;
        case LightColor::GREEN:light.color=LightColor::YELLOW; Light.timer_seconds=5; break;
        case LightColor::YELLOW:light.color=LightColor::RED; Light.timer_seconds=60; break;
    }
}

int main()
{
    TrafficLight traffic ={LightColor::RED};
    updateLight(traffic);
    updateLight(traffic);

    if (traffic.color == LightColor::RED)
        cout<<"RED";
    else if (traffic.color == LightColor::GREEN)
        cout<<"GREEN"
    else 
        cout<<"YELLOW"

    return 0;
}
