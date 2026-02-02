// task18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
void logInfo(T arg)
{
    cout << "[SYSTEM LOG]: " << arg << endl;

}
int main()
{
    int id = 101;
    double battery =12.5;

    string status = "Ready";
    logInfo<int>(id);
    logInfo<double>(battery);
    logInfo<string>(status);

}

