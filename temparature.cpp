#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t sda, uint8_t scl)
    : _sda(sda), _scl(scl) {}

void TemperatureSensor::begin() {
    Wire1.begin(_sda, _scl);
}

float TemperatureSensor::readTemperature() {
    Wire1.beginTransmission(LM73_ADDR);
    Wire1.write(0x00);
    Wire1.endTransmission();

    uint8_t count = Wire1.requestFrom(LM73_ADDR, 2);
    float temp = 0.0;
    if (count == 2) {
        byte buff[2];
        buff[0] = Wire1.read();
        buff[1] = Wire1.read();
        temp += (int)(buff[0] << 1);
        if (buff[1] & 0b10000000) temp += 1.0;
        if (buff[1] & 0b01000000) temp += 0.5;
        if (buff[1] & 0b00100000) temp += 0.25;
        if (buff[0] & 0b10000000) temp *= -1.0;
    }
    return temp;
}
