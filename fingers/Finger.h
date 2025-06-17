#ifndef FINGER_H
#define FINGER_H

class Finger {
private:
    int inValvePin;
    int pressureSensorPin;

    static constexpr float VOLTAGE = 5.0;
    static constexpr float ADC_RES = 1023.0;

    public:
        Finger(int inValve, int pressureSensor);
        void actuate();
        float readPressure();
};

#endif 