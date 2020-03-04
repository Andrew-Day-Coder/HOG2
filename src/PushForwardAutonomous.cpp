#include "PushForwardAutonomous.h"

// constructor 
PushForwardAutonomous::PushForwardAutonomous() : Autonomous(){}


// must implement ControlScheme, so this is the method for controlling the robot
void PushForwardAutonomous::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("Oops, something went wrong in PushForwardAutonomous::control\n");
  }
  lift->findBottom();
  driveTrain->powerBase(75);
  vex::this_thread::sleep_for(2000);
  driveTrain->powerBase(-75);
  
}