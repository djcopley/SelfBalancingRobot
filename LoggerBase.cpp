//
// Created by Daniel Copley on 2019-04-04.
//

#include "LoggerBase.h"

LoggerBase::LoggerBase(LOG_LEVEL maxLogLevel, String formatter)
{
    this->setMaxLogLevel(maxLogLevel);
    this->formatter = formatter;
}

bool LoggerBase::isMsgLoggable(LOG_LEVEL msgLogLevel)
{
    return msgLogLevel <= this->maxLogLevel;
}

String LoggerBase::getFormatter()
{
    return this->formatter;
}

void LoggerBase::setFormatter(String formatter)
{
    this->formatter = formatter;
}

LOG_LEVEL LoggerBase::getMaxLogLevel()
{
    return this->maxLogLevel;
}

void LoggerBase::setMaxLogLevel(LOG_LEVEL maxLogLevel)
{
    this->maxLogLevel = maxLogLevel;
}