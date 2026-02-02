#include <iostream>
using namespace std;

enum LightColor { RED, YELLOW, GREEN };

struct TrafficLight {
    LightColor color;
    int timer_seconds;
};

void updateLight(TrafficLight &light) {
    switch (light.color) {
        case RED:
            light.color = GREEN;
            light.timer_seconds = 30;
            break;
        case GREEN:
            light.color = YELLOW;
            light.timer_seconds = 5;
            break;
        case YELLOW:
            light.color = RED;
            light.timer_seconds = 60;
            break;
    }
}

int main() {
    TrafficLight light = {RED, 60};

    updateLight(light);
    updateLight(light);

    cout << "Light color: ";
    if (light.color == RED) cout << "RED";
    else if (light.color == GREEN) cout << "GREEN";
    else if (light.color == YELLOW) cout << "YELLOW";

    cout << ", Timer: " << light.timer_seconds << endl;

    return 0;
}
