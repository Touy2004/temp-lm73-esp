#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <Wire.h>

#define LM73_ADDR 0x4D  // Fixed I2C address for the LM73 sensor

class TemperatureSensor {
public:
    TemperatureSensor(uint8_t sda, uint8_t scl);
    void begin();
    float readTemperature();

private:
    uint8_t _sda;
    uint8_t _scl;
};

#endif
