#ifndef SENSORLOGGER_H
#define SENSORLOGGER_H

#include <Arduino.h>

class SensorLogger {
public:
    SensorLogger(const String& sensorId);
    void add(const String& name, float& variable);
    void send();

private:
    static const int MAX_SENSORS = 20;
    String _sensorId;
    String _names[MAX_SENSORS];
    float* _values[MAX_SENSORS];
    int _count;
};

#endif