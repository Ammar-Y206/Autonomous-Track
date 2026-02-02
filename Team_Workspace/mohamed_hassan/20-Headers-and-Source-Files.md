#include <iostream>
using namespace std;

class Calculator {
public:
    int add(int a, int b);
};

int Calculator::add(int a, int b) {
    return a + b;
}

int main() {
    Calculator calc;
    cout << calc.add(5, 5) << endl;
}
