#include "BlueSmallGoalAuton.h"

void BlueSmallGoalAuton::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("Oops, something went wrong in BlueSmallGoalAuton::control\n");
    return;
  }

  // code here
}