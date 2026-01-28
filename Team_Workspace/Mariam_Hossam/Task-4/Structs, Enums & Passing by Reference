#include <iostream>

using namespace std;

enum class LightColor {
    RED,
    YELLOW,
    GREEN
};

struct TrafficLight {
    LightColor color;
    int timer_seconds;
};

void updateLight(TrafficLight &light) {

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

int main() {
    TrafficLight my_light = {LightColor::RED, 60};

    updateLight(my_light);
    updateLight(my_light); 

    cout << "Final Timer: " << my_light.timer_seconds << " seconds" << endl;

    if (my_light.color == LightColor::YELLOW) {
        cout << "Final Color: YELLOW" << endl;
    } else {
        cout << "Final Color: NOT YELLOW (Something is wrong)" << endl;
    }

    return 0;
}