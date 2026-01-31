#include <iostream>
#include <memory>
using namespace std;

class LidarData {
public:
    LidarData() { cout << "Data Allocated\n"; }
    ~LidarData() { cout << " Data Freed\n"; }
};

int main() { 

    shared_ptr<LidarData> main_ptr = make_shared<LidarData>();
    cout << "Pointer Use Count: " << main_ptr.use_count() << "\n"; 

    {
         shared_ptr<LidarData> algo_ptr = main_ptr;
         
         cout << "Pointer Use Count: " << main_ptr.use_count() << "\n"; 
    } 
    
    cout << "Pointer Use Count: " << main_ptr.use_count() << " (Back to 1)\n";
    
    cout << "--- End of Main ---\n";
    return 0;

} 