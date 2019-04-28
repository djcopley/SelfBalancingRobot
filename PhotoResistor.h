//
// Created by djcopley on 4/7/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTOR_H
#define SELFBALANCINGROBOT_PHOTORESISTOR_H

#include <Arduino.h>

class PhotoResistor {
public:
    PhotoResistor(uint8_t photoResistorPin, float angle);
    short getIntensity();
    void calibrate();

private:
    const uint8_t photoResistorPin; // analog pin for photo-resistor
    const float angle;
    short centeredIntensity;
};


#endif //SELFBALANCINGROBOT_PHOTORESISTOR_H
