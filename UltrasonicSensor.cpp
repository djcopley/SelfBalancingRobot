//
// Created by Daniel Copley on 2019-04-02.
//

#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(byte triggerPin, byte echoPin) : triggerPin(triggerPin), echoPin(echoPin)
{
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float UltrasonicSensor::getDistanceCM()
{
    unsigned long duration;

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    return microsecondsToCentimeters(duration);
}

float UltrasonicSensor::microsecondsToCentimeters(unsigned long microseconds)
{
    return microseconds * (2 / 29); // Convert time to distance
}