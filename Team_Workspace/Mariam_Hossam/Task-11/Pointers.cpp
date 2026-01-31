#include <iostream>
using namespace std;

void resetID(int* p){
    
    if (p == nullptr) {
        
        cout << "Error: Pointer is null!\n";
        return; 
    }

    *p = 0; 
    
    cout << "ID Reset Successful.\n";
}

int main() {
   int robot_id = 1000;
   int* ptr = &robot_id;

   resetID(ptr);
   cout<< robot_id;

   resetID(nullptr); 

    return 0;
}