#include <iostream>
using namespace std;

enum LightColor
{
    RED,
    YELLOW,
    GREEN
};

struct TrafficLight
{
    LightColor color;
    int timer_seconds;
};

void updateLight(TrafficLight &light)
{
    if (light.color == RED)
    {
        light.color = GREEN;
        light.timer_seconds = 30;
    }
    else if (light.color == GREEN)
    {
        light.color = YELLOW;
        light.timer_seconds = 5;
    }
    else if (light.color == YELLOW)
    {
        light.color = RED;
        light.timer_seconds = 60;
    }
}

int main()
{
    TrafficLight light;

    light.color = RED;
    light.timer_seconds = 0;

    updateLight(light);
    updateLight(light);

    cout << light.color << " " << light.timer_seconds;

    return 0;
}
