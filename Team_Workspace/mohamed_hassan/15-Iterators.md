#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> readings = {10, -5, 20, -1, 30};

    for (auto it = readings.begin(); it != readings.end(); ) {
        if (*it < 0)
            it = readings.erase(it);
        else
            ++it;
    }

    for (int val : readings)
        cout << val << " ";
}

