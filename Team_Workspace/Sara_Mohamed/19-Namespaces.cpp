#include <iostream>

namespace Lidar{
    
    int range = 100;
    
    void print(){
        std::cout << "Lidar Range:[" << range <<"]" << std::endl;
    }
}

namespace Sonar{
    
    int range = 5;
    
    void print(){
        std::cout << "Sonar Range:[" << range <<"]" << std::endl;
    }
}

int main()
{
   Lidar::print();
   Sonar::print();

    return 0;
}
