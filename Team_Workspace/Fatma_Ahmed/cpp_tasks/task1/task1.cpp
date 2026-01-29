
#include <iostream>
using namespace std;

double getDistance(int time_microseconds) {

    double Distance = (double)time_microseconds / 58;
    return (Distance / 100);
}


int main()
{
    int time;
    cout << "enter time in seconds: ";
    cin >> time;

    double distance_meters = getDistance(time);

    cout << "the result is " << distance_meters << endl;



}
