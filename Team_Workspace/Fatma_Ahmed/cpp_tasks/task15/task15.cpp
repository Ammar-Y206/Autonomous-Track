// task15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> Vtest = { 10,-5,20,-2,30 };


    for (auto it = Vtest.begin(); it != Vtest.end(); ) {
        if (*it < 0) {
            it = Vtest.erase(it);
        }
        else {
            it++;
        }
    }

    for (int item : Vtest) {
        cout << item << endl;
    }
}

