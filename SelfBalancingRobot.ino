#include "HelperMacros.h"
#include "UltrasonicSensor.h"
#include "LoggerBase.h"
#include "SerialLogger.h"
#include "RF24Logger.h"
#include "Logger.h"

// Pin Definitions
const byte triggerPin = 0;
const byte echoPin = 0;

// Global Class Allocation

Logger *logger = new Logger();

void setup()
{
    Serial.begin(115200);
    logger->registerLogger(new SerialLogger(INFO, "{log_level} - {time} - {message}"));
    logger->registerLogger(new RF24Logger(INFO, "", 7, 8));
}

void loop()
{
    logger->logMessage(ERROR, "ERROR");
    delay(100);
    logger->logMessage(WARNING, "WARNING");
    delay(100);
    logger->logMessage(INFO, "INFO");
    delay(100);
    logger->logMessage(DEBUG, "DEBUG");
    delay(100);
}
