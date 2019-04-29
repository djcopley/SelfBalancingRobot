//
// Created by djcopley on 4/26/19.
//

#ifndef SELFBALANCINGROBOT_MOTOR_H
#define SELFBALANCINGROBOT_MOTOR_H

#include <Servo.h>

class Motor {
public:
    Motor(bool isTracking, double tiltAngle, bool avoidObstacle,
          uint8_t leftPWNPin, uint8_t rightPWNPin, uint8_t leftDirPin, uint8_t rightDirPin);

private:
    void selfBalancing(int impact);
    const uint8_t leftPWNPin;
    const uint8_t rightPWNPin;
    const uint8_t leftDirPin;
    const uint8_t rightDirPin;
    bool isTrack;
    double tiltAngle;
    bool needAvoid;
};


#endif //SELFBALANCINGROBOT_MOTOR_H
