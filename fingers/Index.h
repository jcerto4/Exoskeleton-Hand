#ifndef INDEX_H
#define INDEX_H

class Index {
private:
    int inValvePin;
    int pressureSensorPin;

    static constexpr float VOLTAGE = 5.0;
    static constexpr float ADC_RES = 1023.0;

    public:
        Index(int inValve, int pressureSensor);
        void actuate();
        float readPressure();
};

#endif 