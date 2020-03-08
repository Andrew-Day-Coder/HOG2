#include "DriverControl.h"
#include "Logger.h"
#include "vex.h"

DriverControl::DriverControl()
{
}
void DriverControl::manageSubSystems(Robot* robot)
{
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    // manage the manual control of the lift
    if (robot->getController()->ButtonR1.pressing())
    {
        robot->getLift()->up();
    }
    else if (robot->getController()->ButtonR2.pressing())
    {
        robot->getLift()->down();
    }
    else
    {
      // hold the lift in place if no buttons are held
      robot->getLift()->hold();
    }
    // update the lift
    robot->getLift()->update();

    // manage the manual control of the claw
    if (robot->getController()->ButtonA.pressing())
    {
      robot->getClaw()->squeeze();
    }
  }
}