#include "ControlScheme.h"
ControlScheme::ControlScheme(){}

bool ControlScheme::checkErrors(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  /*
    returns true if no errors caught, otherwise false;
  */
  if (driveTrain == nullptr)
  {
    printf("[CRITICAL]: drivetrain is `nullptr` when passed to some sub-class of ControlScheme\n");
    return false;
  }
  if (lift == nullptr)
  {
    printf("[CRITICAL]: lift is `nullptr` when passed to some sub-class of ControlScheme\n");
    return false;
  }
  if (claw == nullptr)
  {
    printf("[CRITICAL]: claw is `nullptr` when passed to some sub-class of ControlScheme\n");
    return false;
  }
  return true;
}