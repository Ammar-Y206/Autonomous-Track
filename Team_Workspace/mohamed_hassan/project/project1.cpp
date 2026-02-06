#include <iostream>
using namespace std;

class Sonsor {
protected:
    string name;
public:
    Sonsor(string n) : name(n) {}
    string getName() { return name; }
    virtual ~Sonsor() {
        cout << "sensor " << name << " deleted" << endl;
    }
};

class Temperature : public Sonsor {
public:
    double temp = 35.5;
    Temperature() : Sonsor("Temperature") {}
};

class Lidar : public Sonsor {
public:
    int value = 400;
    Lidar() : Sonsor("Lidar") {}
};

int main() {
    Temperature* t = new Temperature();
    Lidar* l = new Lidar();
if (t->temp!=35.5&& l->value!=400) {
    cout << "wrong value";
    return 0;
}
    string drone="drone";
    string rover="rover";
    string b;
    int battery=100;
    cin >> b;
    if (b=="drone") {
        battery-=15;
    }
    if (b=="rover") {
        battery-=5;
    }
    int steps ;
    for (int i=0;i<battery;i++) {
        if (b=="drone") {
            battery-=15;
        }
        if (b=="rover") {
            battery-=5;
        }
        if (battery<=20) {
            cout << "battery is low "<< battery << endl;
            return 0;
        }
    }
    
    cout << t->getName() << ": " << t->temp << endl;
    cout << l->getName() << ": " << l->value << endl;

    delete t;
    delete l;

    return 0;
}
