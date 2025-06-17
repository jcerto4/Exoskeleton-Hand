#ifndef HAND_H
#define HAND_H

#include "Finger.h"

class Hand {
private:
   int outValvePin;
   Thumb thumb;
   Index index;
   MultiFinger multiFinger;

    public:
        Hand();
        void pinch();
        void grasp();
        void release();
};

#endif 