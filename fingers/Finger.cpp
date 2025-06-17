#include "Finger.h"
#include <Arduino.h>

Finger::Finger(int inValve, int pressureSensor) 
    : inValvePin(inValve), pressureSensorPin(pressureSensor) {
    pinMode(inValvePin, OUTPUT);
}

void Finger::actuate() {
    digitalWrite(inValvePin, HIGH);
    delay(500);
    digitalWrite(inValvePin, LOW);
}

float Finger::readPressure() {
    float voltageOut = analogRead(pressureSensorPin) * (VOLTAGE / ADC_RES);
    float pressure = (voltageOut - 0.1f) / 3.0f * 300.0f - 100.0f;
    return max(0.0f, pressure);
}