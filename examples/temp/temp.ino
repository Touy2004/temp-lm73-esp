#include <TemperatureSensor.h>

TemperatureSensor sensor(4, 5);  // SDA and SCL pins

void setup() {
    Serial.begin(9600);
    sensor.begin();
}

void loop() {
    float data = sensor.readTemperature();
    Serial.println(data);
    delay(1000);
}