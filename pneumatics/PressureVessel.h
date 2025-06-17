#ifndef PRESSUREVESSEL_H
#define PRESSUREVESSEL_H

class PressureVessel {
private:
    int motorPin;
    int inValvePin;
    int outValvePin;
    int pressureSensorPin;
    bool isFilling;

    static constexpr float MIN_PRESSURE = 245.0;
    static constexpr float MAX_PRESSURE = 800.0;
    static constexpr float VOLTAGE = 5.0;
    static constexpr float ADC_RES = 1023.0;

    public:
       PressureVessel(int motorPin, int inValvePin, int outValvePin, int pressureSensorPin);
       void fill();
       void readPressure();
};

#endif 