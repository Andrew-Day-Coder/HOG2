#ifndef ROBOT_H
#define ROBOT_H

#include "DriveTrain.h"
#include "ControlScheme.h"
#include "Lift.h"
#include "Claw.h"

class Robot
{
  private:
    Lift* lift;
    DriveTrain* driveTrain;
    ControlScheme* controlScheme;
    Claw* claw;
  public:
    Robot(DriveTrain* driveTrain, Lift* lift, Claw* claw);
    DriveTrain* getDriveTrain();
    void attachControlScheme(ControlScheme* scheme);
    void sendControlPulse();
    void setUpController(vex::controller*);
    Lift* getLift() { return lift;}
    Claw* getClaw() { return claw;}
    ControlScheme* getControlScheme();
};

#endif