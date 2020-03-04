#include "ArcadeControl.h"
#include "DriveTrain.h"
#include "DriverControl.h"
#include "Helpers.h"

ArcadeControl::ArcadeControl(vex::controller* cont) : DriverControl(cont){}

void ArcadeControl::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (lift == nullptr)
  {
    printf("[CRITICAL]: lift is nullptr in ArcadeControl::control\n");
    return;
  }
  if (claw == nullptr)
  {
    printf("[CRITICAL]: claw is nullptr in ArcadeControl::control\n");
    return;
  }
  if (driveTrain == nullptr)
  {
    printf("[CRITICAL]: driveTrain is nullptr in ArcadeControl:control\n");
    return;
  }
  if (getController() == nullptr)
  {
    printf("[CRITICAL]: No controller registered for ArcadeControl::control\n");
    return;
  }
  // manage the subsystems in a different method shared between driver control standards
  manageSubSystems(lift, claw);
  int16_t throttle = getController()->Axis3.position(); 
  int16_t difference = getController()->Axis1.position();

  throttle = Helpers::curve(throttle, 2.5, (int16_t) 100);
  difference = Helpers::curve(difference, 2.5, (int16_t) 100);

  int16_t leftPower = throttle + difference;
  int16_t rightPower = throttle - difference;

  leftPower = Helpers::clamp(leftPower, -100, 100);
  rightPower = Helpers::clamp(rightPower, -100, 100);

  if (getController()->ButtonL1.pressing())
  {
    leftPower /= 5;
    rightPower /= 5;
  }
  driveTrain->powerBase(leftPower, rightPower);
}