#include "DriverControl.h"
#include "vex.h"

DriverControl::DriverControl(vex::controller* cont)
{
  this->cont = cont;
}
void DriverControl::manageSubSystems(Lift* lift, Claw* claw)
{
  // do the nullchecks
  if (lift == nullptr)
  {
    printf("[CRITICAL]: lift is nullptr, in DriverControl::manageSubSystems\n");
    return;
  }
  if (claw == nullptr)
  {
    printf("[CRITICAL]: claw is nullptr, in DriverControl::manageSubSystems\n");
  }
  if (getController() == nullptr)
  {
    printf("[CRITICAL]: controller is nullptr, in DriverControl::manageSubSystems\n");
  }
  // manage the manual control of the lift
  if (getController()->ButtonR1.pressing())
  {
    if (isLiftSmoothingEnabled())
    {
      lift->smoothUp();
    } else
    {
      lift->up();
    }
  } else if (getController()->ButtonR2.pressing())
  {
    if (isLiftSmoothingEnabled())
    {
      lift->smoothDown();
    } else
    {
      lift->down();
    }
  }
  else
  {
    lift->hold();
  }
  lift->update();

  // manage the manual control of the claw
  if (getController()->ButtonA.pressing())
  {
    claw->squeeze();
  }
}