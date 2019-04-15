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
//UltrasonicSensor *ultrasonicSensor;

void setup()
{
    Serial.begin(115200);
//    ultrasonicSensor = new UltrasonicSensor(2, 3);
//    logger->registerLogger(new SerialLogger(INFO, "{log_level} - {time} - {message}"));
    logger->registerLogger(new RF24Logger(INFO, "{log_level} - {time} - {message}", 7, 8));
}

void loop()
{
    Serial.println("Transmitting...");
    logger->logMessage(INFO, "Testing Testing 1, 2, 3");
    delay(1000);
}
