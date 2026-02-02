#include <iostream>
using namespace std;

int main()
{
    char gear = 'D';
    double speed = 0.0;

    switch(gear){
    
        case 'P':
        speed = 0.0;
        printf("Parking");
        break;

        case 'D':
        speed = 10.0;
        printf("Driving Forward");
        break;

        case 'R':
        speed = -5.0;
        printf("Reversing");
        break;

        default:
        speed = 0.0;
        printf("Error: Unknown Gear");
        break;
    }

    printf("\nspeed = ");
    cout<<speed;

    return 0;
}
