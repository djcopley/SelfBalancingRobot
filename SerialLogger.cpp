//
// Created by Daniel Copley on 2019-04-04.
//

#include "SerialLogger.h"

void SerialLogger::logMessage(LOG_LEVEL msgLogLevel, String message)
{
    if (this->isMsgLoggable(msgLogLevel)) {
        Serial.println(message); // Format message and print to display
    }
}
