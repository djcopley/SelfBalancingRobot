//
// Created by Daniel Copley on 2019-04-02.
//

#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(byte triggerPin, byte echoPin) : triggerPin(triggerPin), echoPin(echoPin)
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    digitalWrite(triggerPin,HIGH);
    delay(2000);
}

float UltrasonicSensor::getDistanceCM()
{
    unsigned long duration;

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    duration = pulseIn(echoPin, HIGH, 50000); // 50 milli-seconds timout (50k micro-seconds)

    return duration > 0 ? microsecondsToCentimeters(duration) : 0xFFFF;
}

float UltrasonicSensor::microsecondsToCentimeters(unsigned long microseconds)
{
    return microseconds * (0.034/2); // Convert time to distance
}