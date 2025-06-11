#include "Hand.h"
#include <Arduino.h>

Hand::Hand()
    :   outValvePin(5),
        thumb(4, 5, A0),
        index(6, 7, A1),
        multiFinger(8, 9, A2){
    pinMode(outValvePin, OUTPUT);
}

void Hand::pinch() {
    thumb.actuate();
    index.actuate();
    delay(500);
}

void Hand::grasp() {
    thumb.actuate();
    index.actuate();
    multiFinger.actuate();
    delay(500);
}

void Hand::release() {
    digitalWrite(outValvePin, HIGH);
    delay(500);
    digitalWrite(outValvePin, LOW);
}