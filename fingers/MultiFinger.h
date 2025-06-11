#ifndef MULTIFINGER_H
#define MULTIFINGER_H

class MultiFinger {
private:
    int inValvePin;
    int pressureSensorPin;

    static constexpr float VOLTAGE = 5.0;
    static constexpr float ADC_RES = 1023.0;

    public:
        MultiFinger(int inValve, int pressureSensor);
        void actuate();
        float readPressure();
};

#endif 