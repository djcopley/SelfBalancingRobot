#include "HelperMacros.h"
#include "UltrasonicSensor.h"
#include "LoggerBase.h"
#include "SerialLogger.h"
#include "Logger.h"

// Pin Definitions
const byte triggerPin = 0;
const byte echoPin = 0;

// Global Class Allocation

Logger *logger = new Logger();

void setup()
{
    logger->registerLogger(new SerialLogger(115200, LOG_LEVEL(ERROR), "{log_level} - {time} - {message}"));
}

void loop()
{
    logger->logMessage(LOG_LEVEL(ERROR), "ERROR");
    delay(100);
    logger->logMessage(LOG_LEVEL(WARNING), "WARNING");
    delay(100);
    logger->logMessage(LOG_LEVEL(INFO), "INFO");
    delay(100);
    logger->logMessage(LOG_LEVEL(DEBUG), "DEBUG");
    delay(1000);
}
