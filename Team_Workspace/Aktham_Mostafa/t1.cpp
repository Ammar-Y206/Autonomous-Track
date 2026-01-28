#include <iostream>
using namespace std;

// output: 1.01414
int main() {
	int time_micro = 5882;
	double time_double = static_cast<double>(time_micro) / 58;
	double distance = time_double / 100.0;
	cout << distance << endl;
	return 0;
}
