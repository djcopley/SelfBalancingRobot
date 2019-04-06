//
// Created by Daniel Copley on 2019-04-04.
//

#include "Logger.h"

void Logger::registerLogger(LoggerBase *logger)
{
    this->loggers.push_back(logger);
}

void Logger::logMessage(LOG_LEVEL msgLogLevel, String message)
{
    for (int i = 0; i < this->loggers.size(); i++) {
        this->loggers[i]->logMessage(msgLogLevel, message);
    }
}