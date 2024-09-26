#ifndef DUALSHOCK4_H
#define DUALSHOCK4_H

#include <CAN.h>

#define DEAD_BAND 15

class DualShock4{
    public:
        DualShock4(CanControl* _can);

        void convert();

        bool up = 0;
        bool down = 0;
        bool left = 0;
        bool right = 0;
        bool triangle = 0;
        bool cross = 0;
        bool square = 0;
        bool circle = 0;
        bool l1 = 0;
        bool l3 = 0;
        bool r1 = 0;
        bool r3 = 0;
        bool share = 0;
        bool options = 0;
        bool touchpad = 0;
        bool psButton = 0;
        int8_t l2 = 0;
        int8_t r2 = 0;
        int8_t jslx = 0;
        int8_t jsly = 0;
        int8_t jsrx = 0;
        int8_t jsry = 0;

    private:
        CanControl *can_ptr;
};

#endif