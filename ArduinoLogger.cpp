#include "ArduinoLogger.h"

ArduinoLogger::ArduinoLogger(const String& sensorId) {
    _sensorId = sensorId;
    _count = 0;
}

void ArduinoLogger::add(const String& name, float& variable) {
    if (_count < MAX_SENSORS) {
        _names[_count] = name;
        _values[_count] = &variable;
        _count++;
    }
}

void ArduinoLogger::send() {
    Serial.print("sensor_id:");
    Serial.print(_sensorId);

    for (int i = 0; i < _count; i++) {
        Serial.print(",");
        Serial.print(_names[i]);
        Serial.print(":");
        Serial.print(*_values[i], 4); // 4 decimal places
    }

    Serial.println();
}