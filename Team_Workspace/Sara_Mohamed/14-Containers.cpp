#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string , int>spare_parts = {{"Wheel", 4},{"Motor", 2},{"Sensor", 5}};
    
    spare_parts["Wheel"] -= 1;
    spare_parts["Motor"] += 3;
    
    cout << "laser : " << spare_parts["Laser"]<< endl;
    
    for (auto item : spare_parts){
        cout << item.first << " : " << item.second << endl;
    }

    return 0;
}
