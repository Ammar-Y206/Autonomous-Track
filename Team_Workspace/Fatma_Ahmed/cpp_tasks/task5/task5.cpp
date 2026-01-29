// task5.
#include <iostream>
#include <vector>

using namespace std;

void find_extremes(const vector<double>& list,float &max,float &min) {
	max = min = list[0];

	for (float num : list) {
		if (num > max)
			max = num;
		if (num < min)
			min = num;

	}

}

int main()
{
	std::vector<double> volts = { 12.5, 11.8, 13.1, 12.0 };

	float min_v=0.0, max_v = 0.0;
	find_extremes(volts, max_v, min_v);

	cout << "max =  " << max_v << endl;
	cout << "min = " << min_v << endl;

}

