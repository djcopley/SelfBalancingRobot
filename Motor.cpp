//
// Created by djcopley on 4/26/19.
//

#include "Motor.h"

Motor::Motor(int lServoPin, int rServoPin)
{
    lServo.attach(lServoPin);
    rServo.attach(rServoPin);
}

void Motor::go(SPEED speed, int direction, bool obstacleDetected)
{
    currentSpeed = speed;

    if (direction > 180) {
        direction = 180;
    } else if (direction < -180) {
        direction = -180;
    }

    int rSpeed, lSpeed;

    if (obstacleDetected) {
        if(direction == 0){
            lSpeed = rSpeed = SPEED_STOP;
        } else if (direction > 0) {
            lSpeed = speed;
            rSpeed = SPEED_STOP;
        } else {
            rSpeed = speed;
            lSpeed = SPEED_STOP;
        }
    } else {
        // Calculate dynamic speed
        float scaleSpeed = speed - (speed) * abs((direction / 180));
        if (direction == 0) {
            lSpeed = rSpeed = speed;
        } else if (direction > 0) {
            lSpeed = speed;
            rSpeed = scaleSpeed;
        } else {
            rSpeed = speed;
            lSpeed = scaleSpeed;
        }
    }
    lServo.write(centerSpeed + lServoOffset + lSpeed);
    rServo.write(centerSpeed + rServoOffset - rSpeed);
}

/**
 * Returns speed in meters per second
 * @return speed in m/s
 */
float Motor::getSpeed()
{
    return currentSpeed == SPEED_LOW ? .122 : currentSpeed == SPEED_MEDIUM ? .346 : currentSpeed == SPEED_HIGH ? .45 : 0;
}

float Motor::getDistanceTraveled()
{
    return distanceTraveled;
}

void Motor::updateDistanceTraveled()
{
    distanceTraveled += getSpeed();
}