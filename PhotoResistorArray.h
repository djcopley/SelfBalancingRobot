//
// Created by djcopley on 4/26/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
#define SELFBALANCINGROBOT_PHOTORESISTORARRAY_H

#include "PhotoResistor.h"

class PhotoResistorArray {
public:
    PhotoResistorArray(int numPhotoResistors, int *pinNumbers);

private:
    PhotoResistor *photoResistors;
    int numPhotoResistors;

};


#endif //SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
