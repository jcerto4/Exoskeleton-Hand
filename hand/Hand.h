#ifndef HAND_H
#define HAND_H

#include "Thumb.h"
#include "Index.h"
#include "MultiFinger.h"
#include "PressureVessel.h"

class Hand {
private:
   int outValvePin;
   Thumb thumb;
   Index index;
   MultiFinger multiFinger;
   PressureVessel vessel;

    public:
        Hand();
        void pinch();
        void grasp();
        void release();
};

#endif 