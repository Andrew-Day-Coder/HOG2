#include "RedLargeGoalAuton.h"

void RedLargeGoalAuton::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("Oops, something went wrong in RedLargeGoalAuton::control\n");
    return;
  }

  // code here
}