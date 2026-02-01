#include <iostream>

using namespace std;

int main()
{
    int time_microseconds = 5882;
    double distance_cm = static_cast<double>(time_microseconds) / 58;
    double distance_meters = (static_cast<double>(distance_cm)) / 100;
    cout << distance_meters;
    return 0;
}