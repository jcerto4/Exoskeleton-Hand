#include "PressureVessel.h"
#include <Arduino.h>


PressureVessel::PressureVessel(int motor, int inValve, int outValve, int pressureSensor) 
    : motorPin(motor), inValvePin(inValve), outValvePin(outValve), pressureSensorPin(pressureSensor) {
    pinMode(inValvePin, OUTPUT);
    pinMode(outValvePin, OUTPUT);
    isFilling = false;
}

void PressureVessel::fill() {
    float pressure = readPressure();
    if(!isFilling && pressure < MIN_PRESSURE){
        digitalWrite(outValvePin, LOW);
        digitalWrite(inValvePin, HIGH;)
        digitalWrite(motorPin, HIGH);
        isFilling = true;
    }
    
    if(isFilling && pressure >= MAX_PRESSURE){
        digitalWrite(inValvePin, LOW);
        digitalWrite(motorPin, LOW);
        isFilling = false;
    }
}

float PressureVessel::readPressure() {
    float voltageOut = analogRead(pressureSensorPin) * (VOLTAGE / ADC_RES);
    float pressure = (voltageOut - 0.1f) / 3.0f * 300.0f - 100.0f;
    return max(0.0f, pressure);
}