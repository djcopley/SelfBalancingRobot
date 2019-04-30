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

    void generateMessage(String message);
    void logMessage(LOG_LEVEL msgLogLevel, String message);

private:
    RF24 *radio;
    const uint64_t pipes[2] = { 0xDEDEDEDEE7LL, 0xDEDEDEDEE9LL};

    char SendPayload[31] = {};
    char RecvPayload[31] = {};
    char serialBuffer[31] = {};

    boolean stringComplete = false;  // whether the string is complete
    int dataBufferIndex = 0;
    boolean stringOverflow = false;
    char charOverflow = 0;
};


#endif //SELFBALANCINGROBOT_RF24LOGGER_H
