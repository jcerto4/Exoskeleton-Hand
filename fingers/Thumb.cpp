#include "Thumb.h"
#include <Arduino.h>

Thumb::Thumb(int inValve, int outValve, int pressureSensor) 
    : inValvePin(inValve), outValvePin(outValve), pressureSensorPin(pressureSensor) {
    pinMode(inValvePin, OUTPUT);
    pinMode(outValvePin, OUTPUT);
}

void Thumb::actuate() {
    digitalWrite(inValvePin, HIGH);
    digitalWrite(outValvePin, LOW);
    delay(500);
    digitalWrite(inValvePin, LOW);
}

void Thumb::release() {
    digitalWrite(inValvePin, LOW);
    digitalWrite(outValvePin, HIGH);
    delay(500);
    digitalWrite(outValvePin, LOW);
}

float Thumb::readPressure() {
    float voltageOut = analogRead(pressureSensorPin) * (VOLTAGE / ADC_RES);
    float pressure = (voltageOut - 0.1f) / 3.0f * 300.0f - 100.0f;
    return max(0.0f, pressure);
}