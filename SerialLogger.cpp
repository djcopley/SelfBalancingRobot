//
// Created by Daniel Copley on 2019-04-04.
//

#include "SerialLogger.h"

SerialLogger::SerialLogger(unsigned int baudRate) : baudRate(baudRate)
{
    Serial.begin(baudRate);
}