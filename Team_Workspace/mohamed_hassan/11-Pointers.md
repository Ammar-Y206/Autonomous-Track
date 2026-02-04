#include <iostream>
using namespace std;
void reset(int*p) {
    
    if (p!=nullptr) {
        *p=0;
        cout << "ID Reset"<< endl;
    }
    else {
        cout << "ID Not Reset"<< endl;
    }
}

int main() {
   int robot_id =1000;
    int*ptr = &robot_id;
    reset(ptr);
cout << "Robot ID = " << robot_id << endl;
    
    return 0;
}
