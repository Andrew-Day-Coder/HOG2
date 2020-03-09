#include "PushForwardAutonomous.h"

// constructor 
PushForwardAutonomous::PushForwardAutonomous() : Autonomous(){}


// must implement ControlScheme, so this is the method for controlling the robot
void PushForwardAutonomous::control(Robot* robot)
{
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    robot->getLift()->findBottomByImpact();
    robot->getDriveTrain()->powerBase(75);
    vex::this_thread::sleep_for(2000);
    robot->getDriveTrain()->powerBase(-75);
  }
  
}