#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<float>speed = {1.5, 5.5, 0.5, 3.2};
    
    sort(speed.begin(), speed.end(), 
        [](float a, float b){
            return a > b ;
        });
        
    for(float s : speed){
        cout << s << " , ";
    }

    return 0;
}
