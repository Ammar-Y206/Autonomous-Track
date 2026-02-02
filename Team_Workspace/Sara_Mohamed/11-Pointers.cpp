#include <iostream>
using namespace std;

void resetID(int* p){
        if (p == nullptr){
            cout << "Safety First!"<< endl ;
        }
        else{
            *p = 0;
            cout << "ID Reset" << endl;
        }
    }

int main()
{
    int robot_id = 1000;
    int* ptr = &robot_id;
    
    resetID(ptr);
    cout << robot_id << endl;
    resetID(nullptr);
    

    return 0;
}
