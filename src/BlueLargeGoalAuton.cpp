#include "BlueLargeGoalAuton.h"

void BlueLargeGoalAuton::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("Oops, something went wrong in BlueLargeGoalAuton::control\n");
    return;
  }

  // code here
}