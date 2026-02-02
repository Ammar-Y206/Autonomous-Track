#include <iostream>
using namespace std ;

class Tracker {
public :
 
    Tracker(){
        cout << "Tracker Born" << endl;
    }

    ~Tracker(){
        cout << "Tracker Died" << endl;
    }
};

int main()
{
    cout << "Start" << endl;
    
    {
        Tracker t1;
        cout << "Inside Scope" << endl;
    }
    
    cout << "End" << endl;
    
    return 0;
}
