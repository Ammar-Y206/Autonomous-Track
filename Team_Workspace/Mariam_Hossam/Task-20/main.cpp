#include <iostream>
#include "Calculator.hpp" 

int main() {

    Calculator calc;

    int result = calc.add(5, 5);

    std::cout << "Result: " << result << "\n";

    return 0;
}