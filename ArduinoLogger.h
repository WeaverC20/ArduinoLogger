#ifndef ARDUINOLOGGER_H
#define ARDUINOLOGGER_H

#include <Arduino.h>

class ArduinoLogger {
public:
    ArduinoLogger(const String& sensorId);
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