#include "Hand.h"
#include <Arduino.h>

Hand::Hand()
    :   thumb(4, 5, A0),
        index(6, 7, A1),
        multiFinger(8, 9, A2) {
        //eventually the pressure vessel
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
    thumb.release();
    index.release();
    multiFinger.release();
    delay(500);
}