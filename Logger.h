//
// Created by Daniel Copley on 2019-04-04.
//

#ifndef SELFBALANCINGROBOT_LOGGER_H
#define SELFBALANCINGROBOT_LOGGER_H

#include <StandardCplusplus.h>
#include <vector>
#include <iterator>
#include "LoggerBase.h"

class Logger {
public:
    // Register a logger
    void registerLogger(LoggerBase *logger);
    // Log a message
    void logMessage(LOG_LEVEL msgLogLevel, String message);

private:
    // Array of loggers
    std::vector<LoggerBase*> loggers;
};


#endif //SELFBALANCINGROBOT_LOGGER_H
