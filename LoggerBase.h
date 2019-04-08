//
// Created by Daniel Copley on 2019-04-04.
//

#ifndef SELFBALANCINGROBOT_LOGGER_BASE_H
#define SELFBALANCINGROBOT_LOGGER_BASE_H

#include <Arduino.h>

typedef enum LOG_LEVEL {
    ERROR = 0, WARNING = 1, INFO = 2, DEBUG = 3
};

/**
 * Abstract class.
 *
 * Logger classes inherit from here.
 */
class LoggerBase {
public:
    LoggerBase(LOG_LEVEL maxLogLevel, String formatter);

    virtual void logMessage(LOG_LEVEL logLevel, String message) = 0;
    bool isMsgLoggable(LOG_LEVEL msgLogLevel); // Returns true if message loglevel is below the max log level
    String getFormatter();
    void setFormatter(String formatter);
    LOG_LEVEL getMaxLogLevel();
    void setMaxLogLevel(LOG_LEVEL logLevel);

private:
    String formatter;
    LOG_LEVEL maxLogLevel;
};


#endif //SELFBALANCINGROBOT_LOGGER_BASE_H
