#include "HelperMacros.h"
#include "UltrasonicSensor.h"
#include "LoggerBase.h"
#include "SerialLogger.h"
#include "RF24Logger.h"
#include "Logger.h"
#include "PhotoResistorArray.h"
#include "Motor.h"

// Pin Definitions
const byte triggerPin = 2;
const byte echoPin = 3;
const byte lServoPin = 4;
const byte rServoPin = 5;

// Global Class Allocation

Logger *logger;
UltrasonicSensor *ultrasonicSensor;
PhotoResistorArray *photoResistorArray;
Motor *motorControl;

SPEED currentSpeed;

void setup()
{
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    Serial.begin(115200);

    ultrasonicSensor = new UltrasonicSensor(triggerPin, echoPin);
    photoResistorArray = new PhotoResistorArray();
    motorControl = new Motor(lServoPin, rServoPin);

    logger = new Logger();
    logger->registerLogger(new RF24Logger(INFO, "{log_level} - {time} - {message}", 7, 8));
}

bool obstacleDetected = false;
unsigned long timer = millis();

void loop()
{
    float distance = ultrasonicSensor->getDistanceCM();
    Serial.println(distance);

    if (distance > 60) {
        currentSpeed = SPEED_HIGH;
        obstacleDetected = false;
    } else if (distance > 40) {
        currentSpeed = SPEED_MEDIUM;
        obstacleDetected = false;
    } else {
        currentSpeed = SPEED_LOW;
        if (distance > 20) {
            obstacleDetected = false;
        } else {
            obstacleDetected = true;
        }
    }

    motorControl->go(currentSpeed, photoResistorArray->getDirection(), obstacleDetected);

    if (millis() > timer + 1000) {
        logger->logMessage(INFO, "Current speed: " + String(motorControl->getSpeed()) + "m/s");
        logger->logMessage(INFO, "Current speed: " + String(motorControl->getDistanceTraveled()) + "m");
        timer = millis();
    }
}
