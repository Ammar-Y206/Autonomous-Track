#include <iostream>
using namespace std;

class Tracker {
public:
    Tracker() { cout << "Tracker Born\n"; }
    ~Tracker() { cout << "Tracker Died\n"; }
};

int main() {
    
    cout << "Start\n";

    {
        Tracker t1;
        cout << "Inside Scope\n";
    }

    cout << "End\n";

    return 0;
}