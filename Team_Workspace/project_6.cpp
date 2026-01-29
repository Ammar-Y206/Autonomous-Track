#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class thermostat {
private:
    double target_temp;

public:
    void setTempreature(double temp) {
        if (temp > 100.0) {
            cout << "warning too hot\n";
            target_temp = temp;
        }
        else {
            target_temp = temp;
        }
    }

    double getTemperature() {
        return target_temp;
    }
};

int main() {
    thermostat th;

    th.setTempreature(120);
    cout << th.getTemperature();

    return 0;
}
