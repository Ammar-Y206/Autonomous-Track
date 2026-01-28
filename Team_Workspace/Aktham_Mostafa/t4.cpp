#include <iostream>
using namespace std;

enum LightColor { Red, Yellow, Green };

struct TrafficLight {
	LightColor color;
	int timer_seconds;
};
void set_traffic(LightColor c, int t, TrafficLight &light) {
	light.color = c;
	light.timer_seconds = t;
}
void update_light(TrafficLight &tl) {
	switch (tl.color) {
	case LightColor::Red:
		set_traffic(LightColor::Green, 30, tl);
		break;
	case LightColor::Green:
		set_traffic(LightColor::Yellow, 5, tl);
		break;
	case LightColor::Yellow:
		set_traffic(LightColor::Red, 60, tl);
		break;
	}
	cout << tl.color << endl;
	cout << tl.timer_seconds << endl;
}
int main() {
	TrafficLight lmao = {LightColor::Red, 60};
	update_light(lmao);
	update_light(lmao);
	update_light(lmao);
	return 0;
}
