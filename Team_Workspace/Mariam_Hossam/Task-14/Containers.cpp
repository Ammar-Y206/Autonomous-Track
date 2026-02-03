#include <iostream>
#include <map>
#include <string>

int main(){
    
    std::map<std::string, int> config = { {"Wheel", 4}, {"Motor", 2}, {"Sensor", 5} };;
    
    config.at("Wheel") = 3;
    config.at("Motor") = 5;

std::cout << config["Liser"] << "\n";
std::cout << config["Wheel"] << "\n";
std::cout << config["Motor"] << "\n";
std::cout << config["Sensor"] << "\n";

}