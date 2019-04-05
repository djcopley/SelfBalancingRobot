//
// Created by Daniel Copley on 2019-04-04.
//

#include "SerialLogger.h"

SerialLogger::SerialLogger(unsigned int baudRate, LOG_LEVEL maxLogLevel, String formatter) : LoggerBase(maxLogLevel, formatter),
                                                                                             baudRate(baudRate)
{
    Serial.begin(baudRate);
}

void SerialLogger::logMessage(LOG_LEVEL msgLogLevel, String message)
{
    if (this->isMsgLoggable(msgLogLevel)) {
        Serial.println(); // Format message and print to display
    }
}
