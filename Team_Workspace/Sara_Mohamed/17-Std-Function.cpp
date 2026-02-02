#include <iostream>
#include <functional>

void stopMotors() { 
    std::cout << "Motors Stopped" << std::endl; 
}

int main()
{
   std::function<void()>emergency_protocol;
   
   emergency_protocol = stopMotors;
   emergency_protocol();
   
   emergency_protocol = [](){
       std::cout << "ALARM SOUNDING!" << std::endl;
   };
   emergency_protocol();

    return 0;
}
