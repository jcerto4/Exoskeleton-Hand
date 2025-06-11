#include "Index.h"
#include <Arduino.h>

Index::Index(int inValve, int pressureSensor) 
    : inValvePin(inValve), pressureSensorPin(pressureSensor) {
    pinMode(inValvePin, OUTPUT);
}

void Index::actuate() {
    digitalWrite(inValvePin, HIGH);
    delay(500);
    digitalWrite(inValvePin, LOW);
}

float Index::readPressure() {
    float voltageOut = analogRead(pressureSensorPin) * (VOLTAGE / ADC_RES);
    float pressure = (voltageOut - 0.1f) / 3.0f * 300.0f - 100.0f;
    return max(0.0f, pressure);
}