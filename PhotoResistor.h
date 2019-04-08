//
// Created by djcopley on 4/7/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTOR_H
#define SELFBALANCINGROBOT_PHOTORESISTOR_H

#include <Arduino.h>

class PhotoResistor {
public:
    PhotoResistor(uint8_t digitalPin);
    short getIntensity();

private:
    uint8_t digitalPin;
};


#endif //SELFBALANCINGROBOT_PHOTORESISTOR_H
