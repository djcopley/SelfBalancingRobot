//
// Created by djcopley on 4/26/19.
//

#ifndef SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
#define SELFBALANCINGROBOT_PHOTORESISTORARRAY_H

#include "PhotoResistor.h"

class PhotoResistorArray {
public:
    PhotoResistorArray();
    ~PhotoResistorArray();


private:
    const int numPhotoResistors = 3;
    PhotoResistor photoResistors[3] = {
            PhotoResistor(0, 0),
            PhotoResistor(1, 120),
            PhotoResistor(2, 240)
    };
};


#endif //SELFBALANCINGROBOT_PHOTORESISTORARRAY_H
