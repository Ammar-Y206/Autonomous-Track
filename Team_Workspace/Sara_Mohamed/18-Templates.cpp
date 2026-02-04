#include <iostream>
#include <string>
using namespace std;

template<typename T>
void logInfo(T a){
    cout << "[SYSTEM LOG]: " << a << endl;
}

int main()
{
   int id = 101;
   logInfo(id);
   
   double battery = 12.5;
   logInfo(battery);
   
   string status = "Ready";
   logInfo(status);

    return 0;
}
