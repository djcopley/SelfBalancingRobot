//
// Created by djcopley on 4/7/19.
//

#include "PhotoResistor.h"

PhotoResistor::PhotoResistor(uint8_t photoResistorPin) : photoResistorPin(photoResistorPin)
{
    centeredIntensity = analogRead(photoResistorPin);
}

short PhotoResistor::getIntensity()
{
    return analogRead(photoResistorPin) - centeredIntensity;
}

void PhotoResistor::calibrate()
{
    centeredIntensity = analogRead(photoResistorPin);
}