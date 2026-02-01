#include <iostream>
#include <memory>
using namespace std ;

class LidarData{
public :

    LidarData(){
        cout << "Data Allocated" << endl;
    }
    
    ~LidarData(){
        cout << "Data Freed" << endl;
    }
};

int main()
{
    shared_ptr<LidarData>main_ptr = make_shared<LidarData>();
    cout << main_ptr.use_count() << endl;
    
    {
        shared_ptr<LidarData>algo_ptr = main_ptr;
        cout << algo_ptr.use_count()<< endl;
    }
    
    cout << main_ptr.use_count()<< endl;
    main_ptr.reset();
    
    return 0;
}
