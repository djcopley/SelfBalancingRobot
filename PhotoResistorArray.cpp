//
// Created by djcopley on 4/26/19.
//

#include "PhotoResistorArray.h"

PhotoResistorArray::PhotoResistorArray()
{
}

PhotoResistorArray::~PhotoResistorArray()
{
    if (photoResistors != nullptr) {
        delete photoResistors;
    }
}