#include <iostream>
using namespace std;

template <typename T>
void logInfo(T value) {
    cout << "[SYSTEM LOG]: " << value << endl;
}

int main() {
    int id = 101;
    double battery = 12.5;
    string status = "Ready";

    logInfo(id);
    logInfo(battery);
    logInfo(status);
}
