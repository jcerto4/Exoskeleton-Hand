#ifndef THUMB_H
#define THUMB_H

class Thumb {
private:
    int inValvePin;
    int outValvePin;
    int pressureSensorPin;

    static constexpr float VOLTAGE = 5.0;
    static constexpr float ADC_RES = 1023.0;

    public:
        Thumb(int inValve, int outValve, int pressureSensor);
        void actuate();
        void release();
        float readPressure();
};

#endif 
