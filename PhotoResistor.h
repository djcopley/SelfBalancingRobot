//
// Created by djcopley on 4/7/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTOR_H
#define SELFBALANCINGROBOT_PHOTORESISTOR_H

#include <Arduino.h>

class PhotoResistor {
public:
    PhotoResistor(uint8_t photoResistorPin);
    short getIntensity();
    void calibrate();

private:
    const uint8_t photoResistorPin;
    short centeredIntensity;
};


#endif //SELFBALANCINGROBOT_PHOTORESISTOR_H
