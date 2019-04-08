//
// Created by djcopley on 4/5/19.
//

#ifndef SELFBALANCINGROBOT_RF24LOGGER_H
#define SELFBALANCINGROBOT_RF24LOGGER_H

#include <Arduino.h>
#include <RF24.h>
#include <Wire.h>
#include "LoggerBase.h"


class RF24Logger : public LoggerBase {
public:
    RF24Logger(LOG_LEVEL maxLogLevel, String formatter, uint8_t cepin, uint8_t cspin);

    void logMessage(LOG_LEVEL msgLogLevel, String message);

private:
    RF24 *radio;
    const uint8_t pipes[2][6] = {"NODE1", "NODE2"};
};


#endif //SELFBALANCINGROBOT_RF24LOGGER_H
