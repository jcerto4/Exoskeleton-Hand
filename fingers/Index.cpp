#include "Index.h"
#include <Arduino.h>

Index::Index(int inValve, int outValve, int pressureSensor) 
    : inValvePin(inValve), outValvePin(outValve), pressureSensorPin(pressureSensor) {
    pinMode(inValvePin, OUTPUT);
    pinMode(outValvePin, OUTPUT);
}

void Index::actuate() {
    digitalWrite(inValvePin, HIGH);
    digitalWrite(outValvePin, LOW);
    delay(500);
    digitalWrite(inValvePin, LOW);
}

void Index::release() {
    digitalWrite(inValvePin, LOW);
    digitalWrite(outValvePin, HIGH);
    delay(500);
    digitalWrite(outValvePin, LOW);
}

float Index::readPressure() {
    int raw = analogRead(pressureSensorPin);
    float voltage = raw * (VOLTAGE / ADC_RES);
    float pressure = (voltage - 0.1f) / 3.0f * 300.0f - 100.0f;
    return max(0.0f, pressure);
}