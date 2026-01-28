#iclude <iostream>
using namespace std;

int main()
{
    int time_microseconds = 5882;
    double distance_centimeters = static_cast<double>(time_microseconds)/58;
    double distance_meters = distance_centimeters/100;
    cout <<distance_meters;
    return 0;
}
