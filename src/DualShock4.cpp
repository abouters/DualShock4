#include "DualShock4.h"

DualShock4::DualShock4(CanControl* _can){
    can_ptr = _can;
}

void DualShock4::convert(){
    uint8_t buf1[8] = {};
    uint8_t buf2[8] = {};

    can_ptr->CANDataPull(0x101, buf1);
    can_ptr->CANDataPull(0x102, buf2);

    if(buf1[0]){
        this->up = buf2[0] & 0b10000000;
        this->down = buf2[0] & 0b01000000;
        this->left = buf2[0] & 0b00100000;
        this->right = buf2[0] & 0b00010000;
        this->triangle = buf2[0] & 0b00001000;
        this->cross = buf2[0] & 0b00000100;
        this->square = buf2[0] & 0b00000010;
        this->circle = buf2[0] & 0b00000001;
        this->l1 = buf2[1] & 0b10000000;
        this->l3 = buf2[1] & 0b01000000;
        this->r1 = buf2[1] & 0b00100000;
        this->r3 = buf2[1] & 0b00010000;
        this->share = buf2[1] & 0b00001000;
        this->options = buf2[1] & 0b00000100;
        this->touchpad = buf2[1] & 0b00000010;
        this->psButton = buf2[1] & 0b00000001;
        this->l2 = buf2[2];
        this->r2 = buf2[3];
        this->jslx = buf2[4] + 128;
        this->jsly = buf2[5] + 128;
        this->jsrx = buf2[6] + 128;
        this->jsry = buf2[7] + 128;
    }else{
        this->up = 0;
        this->down = 0;
        this->left = 0;
        this->right = 0;
        this->triangle = 0;
        this->cross = 0;
        this->square = 0;
        this->circle = 0;
        this->l1 = 0;
        this->l3 = 0;
        this->r1 = 0;
        this->r3 = 0;
        this->share = 0;
        this->options = 0;
        this->touchpad = 0;
        this->psButton = 0;
        this->l2 = 0;
        this->r2 = 0;
        this->jslx = 0;
        this->jsly = 0;
        this->jsrx = 0;
        this->jsry = 0;
    }

    if(abs(this->jslx) <= DEAD_BAND)    this->jslx = 0;
    if(abs(this->jsly) <= DEAD_BAND)    this->jsly = 0;
    if(abs(this->jsrx) <= DEAD_BAND)    this->jsrx = 0;
    if(abs(this->jsry) <= DEAD_BAND)    this->jsry = 0;
    
}