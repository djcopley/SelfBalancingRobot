//
// Created by Daniel Copley on 2019-04-04.
//

#ifndef SELFBALANCINGROBOT_SERIAL_LOGGER_H
#define SELFBALANCINGROBOT_SERIAL_LOGGER_H

#include <Arduino.h>
#include "LoggerBase.h"

class SerialLogger : public LoggerBase {
public:
    SerialLogger(LOG_LEVEL maxLogLevel, String formatter) : LoggerBase(maxLogLevel, formatter) {};

    void logMessage(LOG_LEVEL msgLogLevel, String message);
};


#endif //SELFBALANCINGROBOT_SERIAL_LOGGER_H
