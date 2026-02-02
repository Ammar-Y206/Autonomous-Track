#include <iostream>
using namespace std;

class Logger {
public:
    // Constructor
    Logger() {
        cout << "--- LOG STARTED ---" << endl;
    }
    // Destructor
    ~Logger() {
        cout << "--- LOG SAVED & CLOSED ---" << endl;
    }
};

int main() {
    cout << "Step 1" << endl;

    {
        Logger session;
        cout << "Step 2 (Inside Scope)" << endl;
    } // <-- Destructor is called here automatically

    cout << "Step 3 (Outside Scope)" << endl;

    return 0;
}
