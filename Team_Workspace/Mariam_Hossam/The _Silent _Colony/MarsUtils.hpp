#pragma once
#include <iostream>
#include <string>

template <typename T> 
class Sensor { 
    
private:
    T value;
     
public:
    
    Sensor(T v) : value(v) {}
    
    T getData() const {
        return value;
    }
};