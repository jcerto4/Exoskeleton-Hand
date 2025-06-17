#ifndef HAND_H
#define HAND_H

#include "Thumb.h"
#include "Index.h"
#include "MultiFinger.h"

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