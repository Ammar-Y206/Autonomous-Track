#include <iostream>
#include <vector>
using namespace std;

void find_extremes(const std::vector<double> &list , double &min_out , double &max_out){
    min_out = list[0];
    max_out = list[0];
    for(double v : list){
       if(v<min_out){
            min_out=v;
        }
        if(v>max_out){
            max_out=v;
        }
    }
}

int main()
{
    vector<double> volts = {12.5, 11.8, 13.1, 12.0};
    double min_v = 0;
    double max_v = 0;

    find_extremes(volts , min_v , max_v);

    cout<<"min_v = "<<min_v<<endl;
    cout<<"max_v = "<<max_v<<endl;

    return 0;
}
