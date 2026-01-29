// task11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void resetID(int* p) {

    if (p == nullptr) return;
    else {
        *p = 0;
        cout << " ID Reset\n";

    }
}

int main()
{
    int robot_id = 1000;
    int* ptr = &robot_id;

    resetID(ptr);
    cout << robot_id;

    resetID(nullptr);


    
}