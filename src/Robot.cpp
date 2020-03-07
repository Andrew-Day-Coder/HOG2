#include "Robot.h"
#include <iostream>

void Robot::attachControlScheme(ControlScheme* scheme)
{
  controlScheme = scheme;
}
Robot::Robot(DriveTrain* driveTrain, Lift* lift, Claw* claw){
  this->driveTrain = driveTrain;
  this->lift = lift;
  this->claw = claw;
}

ControlScheme* Robot::getControlScheme()
{
  if (controlScheme == nullptr)
  {
    printf("[WARNING]: Control Scheme returned is nullptr in Robot::getControlScheme\n");
  }
  return controlScheme;
}
DriveTrain* Robot::getDriveTrain()
{
  return driveTrain;
}

void Robot::sendControlPulse()
{
  if (controlScheme != nullptr)
  {
    controlScheme->control(getDriveTrain(), getLift(), getClaw());
    if (lift != nullptr)
    {
      lift->update();
    } else {
      printf("Error lift is nullptr in Robot::sendControlPulse\n");
    }
  }
  else
  {
    printf("No control scheme defined in Robot::sendControlPulse\n");
  }
}