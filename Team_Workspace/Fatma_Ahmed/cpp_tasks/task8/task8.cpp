// task8.

#include <iostream>
using namespace std;

class Logger {
public:
    Logger() {
        cout << "---- LOG STARTED ---" << endl;

    }
    ~Logger() {
        cout << "--- LOG SAVED & CLOSED ---" << endl;

    }
};

int main()
{
    cout << "step 1 \n";
    {
        Logger obj1;
        cout << "Step 2 (inside Scope)" << endl;
    }
    cout << "Steo 3 (outside Scope)" << endl;
}

