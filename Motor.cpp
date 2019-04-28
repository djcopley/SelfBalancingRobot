//
// Created by djcopley on 4/26/19.
//

#include "Motor.h"
Motor::Motor(bool isTracking, double tiltAngle, bool avoidObstacle, uint8_t leftPWNPin, uint8_t rightPWNPin, uint8_t leftDirPin,
             uint8_t rightDirPin)
: isTrack(isTracking), tiltAngle(tiltAngle), needAvoid(avoidObstacle), leftPWNPin(leftPWNPin),
rightPWNPin(rightPWNPin), leftDirPin(leftDirPin), rightDirPin(rightDirPin)
{
    if(isTrack)
    {
        //set speed//
        analogWrite(leftPWNPin, 100); // need to figure out the relationship between impact and speed.
        analogWrite(rightPWNPin, 100); 

        //move backward(counterclockwise)//
        digitalWrite(leftDirPin, HIGH);
        digitalWrite(rightDirPin, LOW);
        selfBalancing(10); // need to figure out.
        if(needAvoid)
        {
            selfBalancing(0); //no impacts
            analogWrite(leftPWNPin, 170); // turn right.
        }
    }
    else
    {
        selfBalancing(0); //no impacts
    }
}
void Motor::selfBalancing(int impact)
{
    //example: https://www.instructables.com/id/Arduino-Self-Balancing-Robot-1/
}
