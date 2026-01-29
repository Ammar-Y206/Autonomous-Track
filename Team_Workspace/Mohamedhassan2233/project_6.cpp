#include <bits/stdc++.h>
using namespace std;

class Thermostat {
private:
    double target_temp;

public:
    void setTemperature(double temp) {
        if (temp > 100.0) {
            cout << "WARNING: Too Hot!\n";
            target_temp = 100.0;   // حماية
        } else {
            target_temp = temp;
        }
    }

    double getTemperature() {
        return target_temp;
    }
};

int main() {
    Thermostat th;

    th.setTemperature(120);

    cout << "Final Temperature = " << th.getTemperature() << endl;

    return 0;
}
