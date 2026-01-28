#include <iostream>
using namespace std;
int main()
{
    char gear = 'D';
    double speed = 0.0;
    
    switch (gear) {
        case 'P':
            speed = 0.0;
            std::cout << "Parking" << std::endl;
            break;

        case 'D':
            speed = 10.0;
            std::cout << "Driving Forward" << std::endl;
            break; //remove and it will print Driving Forward and Reversing also speed as -5 , keep and it will print 10 and Driving Forward as normal

        case 'R':
            speed = -5.0;
            std::cout << "Reversing" << std::endl;
            break;

        default:
            std::cout << "Error: Unknown Gear" << std::endl;
            break;
    }
    cout << "Final speed command: " << speed << endl;
    return 0;
}
