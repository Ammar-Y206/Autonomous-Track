#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>sensor = {10, -5, 20, -1, 30};
    
    for (auto it = sensor.begin() ; it != sensor.end() ;){
        
        if (*it < 0){
            it = sensor.erase(it);
        }
        else{
            it++;
        }
    }
    for (int vec : sensor){
        cout << vec << " ";
    }

    return 0;
}
