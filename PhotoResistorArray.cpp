//
// Created by djcopley on 4/26/19.
//

#include "PhotoResistorArray.h"

int PhotoResistorArray::getDirection()
{
    int pr1, pr2, pr3;
    pr1 = photoResistors[0].getIntensity();
    pr2 = photoResistors[1].getIntensity();
    pr3 = photoResistors[2].getIntensity();

    if (pr1 > pr3 + threshold && pr2 > pr3 + threshold) {
        if (pr1 > pr2) {
            return -60;
        } else {
            return 60;
        }
    } else if (pr2 > pr1 + threshold && pr3 > pr1 + threshold) {
        if (pr2 > pr3) {
            return 60;
        } else {
            return 180;
        }
    } else if (pr3 > pr2 + threshold && pr1 > pr2 + threshold) {
        if (pr1 > pr3) {
            return -60;
        } else {
            return -180;
        }
    } else {
        return 0;
    }
}