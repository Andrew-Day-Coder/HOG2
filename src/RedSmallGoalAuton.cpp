#include "RedSmallGoalAuton.h"

void RedSmallGoalAuton::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("Oops, something went wrong in RedSmallGoalAuton::control\n");
    return;
  }

  // code here
}