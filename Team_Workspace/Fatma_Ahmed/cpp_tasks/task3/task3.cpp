//task3


#include <iostream>
using namespace std;

int main()
{
    double temps[5] = { 35.5, 30.0, 32.2, 40.0, 38.1 };
    double sum = 0.0;

    for (double temp : temps)
    {
        sum += temp;
    }
    double average = sum / 5;


    cout << "sum = " << sum << endl;
    cout << "Average = " << average << endl;


}

