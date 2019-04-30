//
// Created by djcopley on 4/26/19.
//

#include "Motor.h"

Motor::Motor(int lServoPin, int rServoPin)
{
    lServo->attach(lServoPin);
    rServo->attach(rServoPin);

    speed = LOW;
}

void Motor::go(SPEED speed, float direction, bool obstacleDetected)
{
    if (direction > 180) {
        direction = 180;
    } else if (direction < -180) {
        direction = -180;
    }

    int rSpeed, lSpeed;

    if (obstacleDetected) {
        if (direction > 0) {
            lSpeed = speed;
            rSpeed = SPEED_STOP;
        } else {
            rSpeed = speed;
            lSpeed = SPEED_STOP;
        }
    } else {
        // Calculate dynamic speed
        float scaleSpeed = speed - (speed) * abs((direction/180));
        if (direction > 0) {
            lSpeed = speed;
            rSpeed = scaleSpeed;
        } else {
            rSpeed = speed;
            lSpeed = scaleSpeed;
        }
    }
    lServo->write(centerSpeed + lServoOffset + speed);
    rServo->write(centerSpeed + rServoOffset + speed);
}