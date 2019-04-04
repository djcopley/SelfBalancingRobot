//
// Created by Daniel Copley on 2019-04-04.
//

#ifndef SELFBALANCINGROBOT_SERIAL_LOGGER_H
#define SELFBALANCINGROBOT_SERIAL_LOGGER_H

#include "LoggerBase.h"
#include <Arduino.h>

class SerialLogger: public LoggerBase {
public:
    SerialLogger(unsigned int);

private:
    const unsigned int baudRate;
};


#endif //SELFBALANCINGROBOT_SERIAL_LOGGER_H
