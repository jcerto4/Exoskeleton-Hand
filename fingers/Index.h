#ifndef INDEX_H
#define INDEX_H

class Index {
private:
    int inValvePin;
    int outValvePin;
    int pressureSensorPin;

    public:
        Index(int inValve, int outValve, int pressureSensor);
        void actuate();
        void release();
        int readPressure();
};

#endif 