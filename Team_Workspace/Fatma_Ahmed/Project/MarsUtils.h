#pragma once
#include <string>

template<typename T>
class Sensor {
private:
    std::string SensorName;
    T Data;

public:
    Sensor() : Data{} {}

    Sensor(std::string _SensorName, T _data)
        : SensorName(_SensorName), Data(_data) {
    }

    ~Sensor() = default;

    T getData() const {
        return Data;
    }

    void setData(T _data) {
        Data = _data;
    }

    std::string getSensorName() const {
        return SensorName;
    }

    void setSensorName(const std::string& _SensorName) {
        SensorName = _SensorName;
    }
};
