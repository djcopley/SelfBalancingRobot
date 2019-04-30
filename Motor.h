//
// Created by djcopley on 4/26/19.
//

#ifndef SELFBALANCINGROBOT_MOTOR_H
#define SELFBALANCINGROBOT_MOTOR_H

#include <Servo.h>
#include <Arduino.h>

typedef enum SPEED {SPEED_REVERSE = -6, SPEED_STOP = 0, SPEED_LOW = 2, SPEED_MEDIUM = 6, SPEED_HIGH = 10};

class Motor {
public:
    Motor(int lServoPin, int rServoPin);
    void go(SPEED speed, int direction, bool obstacleDetected);
    float getSpeed();
    float getDistanceTraveled();
    void updateDistanceTraveled();

private:
    Servo lServo;
    Servo rServo;

    const int centerSpeed = 90;

    int rServoOffset = 3;
    int lServoOffset = 4;

    SPEED currentSpeed;
    float distanceTraveled = 0;
};


#endif //SELFBALANCINGROBOT_MOTOR_H
