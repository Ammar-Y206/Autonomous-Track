#include <iostream>
using namespace std;

class Logger {
public:
    Logger() {
        cout << "--- LOG STARTED ---" << endl;
    }

    ~Logger() {
        cout << "--- LOG SAVED & CLOSED ---" << endl;
    }
};

int main() {
    cout << "Step 1" << endl;

    {
        Logger log;
        cout << "Step 2 (Inside Scope)" << endl;
    }

    cout << "Step 3 (Outside Scope)" << endl;
}
