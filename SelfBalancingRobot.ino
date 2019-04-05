#include "HelperMacros.h"
#include "UltrasonicSensor.h"
#include "LoggerBase.h"
#include "SerialLogger.h"

// Pin Definitions
const byte triggerPin = 0;
const byte echoPin = 0;

// Global Class Allocation

void setup()
{
    LoggerBase *a = new SerialLogger(115200, LOG_LEVEL(WARNING), "{log_level} - {time} - {message}");
}

void loop()
{

}
