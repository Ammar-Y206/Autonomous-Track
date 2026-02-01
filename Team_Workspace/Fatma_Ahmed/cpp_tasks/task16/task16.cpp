// task16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Sort(vector<int>& Vtest)
{
    
}

int main()
{
    vector<float> Speed = { 1.5,5.5,0.5,3.2 };


    std::sort(Speed.begin(), Speed.end(), [](float a, float b) {return a > b; 

    });

    for (auto num : Speed)
    {
        cout << num << endl;

    }
    
}


