#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> inventory;

    inventory["Wheel"] = 4;
    inventory["Motor"] = 2;
    inventory["Sensor"] = 5;

    inventory["Wheel"] -= 1;
    inventory["Motor"] += 3;

    cout << inventory["Laser"] << endl;

    for (auto &item : inventory) {
        cout << item.first << ": " << item.second << endl;
    }
}
