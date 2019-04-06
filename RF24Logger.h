//
// Created by djcopley on 4/5/19.
//

#ifndef SELFBALANCINGROBOT_RF24LOGGER_H
#define SELFBALANCINGROBOT_RF24LOGGER_H

#include "LoggerBase.h"

class RF24Logger: public LoggerBase {
public:
    RF24Logger(LOG_LEVEL maxLogLevel, String formatter);

private:

};


#endif //SELFBALANCINGROBOT_RF24LOGGER_H
