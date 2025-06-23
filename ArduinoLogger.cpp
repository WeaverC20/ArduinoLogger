#include "SensorLogger.h"

SensorLogger::SensorLogger(const String& sensorId) {
    _sensorId = sensorId;
    _count = 0;
}

void SensorLogger::add(const String& name, float& variable) {
    if (_count < MAX_SENSORS) {
        _names[_count] = name;
        _values[_count] = &variable;
        _count++;
    }
}

void SensorLogger::send() {
    Serial.print(_sensorId);
    for (int i = 0; i < _count; i++) {
        Serial.print(",");
        Serial.print(*_values[i], 4); // 4 decimal places
    }
    Serial.println();
}