#include <iostream>
#include <vector>

using namespace std;

void find_extremes(const vector<double> &list, double &min_out, double &max_out) {

    if (list.empty()) {
        return;
    }

    min_out = list[0];
    max_out = list[0];

    for (double val : list) {

        if (val < min_out) {
            min_out = val;
        }

        if (val > max_out) {
            max_out = val;
        }
    }
}

int main() {

    vector<double> volts = {12.5, 11.8, 13.1, 12.0};
    double min_v = 0.0;
    double max_v = 0.0;

    find_extremes(volts, min_v, max_v);

    cout << "Battery Report" << endl;
    cout << "Minimum Voltage: " << min_v << endl;
    cout << "Maximum Voltage: " << max_v << endl;

    return 0;
}