#include <iostream>
using namespace std;

int main() {
    int time_microseconds = 5882;
    double distance_cm = static_cast<double>(time_microseconds) / 58;
    double distance_meters = distance_cm / 100;
    cout << "Distance in meters: " << distance_meters << endl;
    return 0;
}

