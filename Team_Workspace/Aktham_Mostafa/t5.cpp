#include <iostream>
#include <vector>
using namespace std;

void find_extremes(const vector<double> &v, double &min, double &max) {
	double temp_max, temp_min;
	temp_min = temp_max = v[0];
	for (auto val : v) {
		if (val < temp_min)
			temp_min = val;
		if (val > temp_max)
			temp_max = val;
	}
	min = temp_min;
	max = temp_max;
}

int main() {
	int lmao;
	vector<double> volts = {12.5, 11.8, 13.1, 12.0};
	double min, max;
	min = max = 0.0;
	find_extremes(volts, min, max);
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	return 0;
}
