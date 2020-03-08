#include "ArcadeControl.h"
#include "DriveTrain.h"
#include "DriverControl.h"
#include "Helpers.h"

ArcadeControl::ArcadeControl() : DriverControl(){}

void ArcadeControl::control(Robot* robot)
{
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
  // manage the subsystems in a different method shared between driver control standards
    manageSubSystems(robot);
    int16_t throttle = robot->getController()->Axis3.position(); 
    int16_t difference = robot->getController()->Axis1.position();

    throttle = Helpers::curve(throttle, 2.5, (int16_t) 100);
    difference = Helpers::curve(difference, 2.5, (int16_t) 100);

    int16_t leftPower = throttle + difference;
    int16_t rightPower = throttle - difference;

    leftPower = Helpers::clamp(leftPower, -100, 100);
    rightPower = Helpers::clamp(rightPower, -100, 100);

    if (robot->getController()->ButtonL1.pressing())
    {
      leftPower /= 5;
      rightPower /= 5;
    }
    robot->getDriveTrain()->powerBase(leftPower, rightPower);
  }
}