#pragma once
#include <iostream>
#include <string>

template <typename T>
class Sensor{
    
private : 

    T data;
    
public :

    Sensor (T d){
        data = d;
    }
    
    T getData(){
        return data;
    }
};
