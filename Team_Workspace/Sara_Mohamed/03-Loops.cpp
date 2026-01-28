#include <iostream>
using namespace std;

int main()
{
    double temps[5] = {35.5, 30.0, 32.2, 40,0, 38.1};
    double sum  = 0.0;

    for (auto t : temps){
        sum = sum + t;
    }
    printf("Sum = ");
    cout<<sum;

    printf("\nAverage = ");
    cout<<sum/5;

    return 0;
}
