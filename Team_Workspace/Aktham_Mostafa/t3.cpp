#include <iostream>
using namespace std;
int main() {
	double temps[5] = {35.5, 30.0, 32.2, 40.0, 38.1};
	double sum = 0.0;
	for (auto temp : temps) {
		sum += temp;
	}
	cout << sum << endl;
	sum /= 5.0;
	cout << sum << endl;
	return 0;
}
