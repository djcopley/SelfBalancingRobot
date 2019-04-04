#ifndef SELFBALANCINGROBOT_ULTRASONIC_SENSOR_H
#define SELFBALANCINGROBOT_ULTRASONIC_SENSOR_H

#include <Arduino.h>

/**
 *
 */
class UltrasonicSensor {
public:
    UltrasonicSensor(byte, byte);
    float getDistanceCM(); // Get the distance to the object in front of the Ultra-sonic Sensor

private:
    const byte triggerPin, echoPin;
    float microsecondsToCentimeters(unsigned long);
};


#endif //SELFBALANCINGROBOT_ULTRASONIC_SENSOR_H
