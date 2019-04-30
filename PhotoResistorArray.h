//
// Created by djcopley on 4/26/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
#define SELFBALANCINGROBOT_PHOTORESISTORARRAY_H

#include "PhotoResistor.h"

class PhotoResistorArray {
public:
    int getDirection();


private:
    const int numPhotoResistors = 3;

    const int threshold = 50;

    PhotoResistor photoResistors[3] = {
            PhotoResistor(0),
            PhotoResistor(1),
            PhotoResistor(2)
    };
};


#endif //SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
