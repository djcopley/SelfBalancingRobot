//
// Created by djcopley on 4/26/19.
//

#include "PhotoResistorArray.h"

PhotoResistorArray::PhotoResistorArray(int numPhotoResistors, int *pinNumbers)
{
    if (numPhotoResistors > 3) {
        float angle = (float) 360 / (float) numPhotoResistors;
        photoResistors = new PhotoResistor[numPhotoResistors];
        for (int i = 0; i < numPhotoResistors; i++) {
            photoResistors[i] = new PhotoResistor(pinNumbers[i], angle * i);
        }
    }
}