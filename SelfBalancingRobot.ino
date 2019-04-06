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
    Serial.begin(115200);
    logger->registerLogger(new SerialLogger(LOG_LEVEL(INFO), "{log_level} - {time} - {message}"));
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
    delay(100);
}
