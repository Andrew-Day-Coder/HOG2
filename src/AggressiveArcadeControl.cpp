#include "AggressiveArcadeControl.h"
#include "DriveTrain.h"
#include "DriverControl.h"
#include "Helpers.h"
#include "Logger.h"

AggressiveArcadeControl::AggressiveArcadeControl() : DriverControl(){}

void AggressiveArcadeControl::powerRedistribution(int16_t* leftPower, int16_t* rightPower)
{
  /* 
    The power arguments are between -200, 200
    if one exceeds +-100 the number needed to be added to reach 
    100 is also added to the other power variable, this makes
    it so that when leftPower is requested to be 200, and rightPower
    is requested to be 0, it will take the leftPower, remove 100
    and then take the right power and remove 100.  leaving with leftPower
    being set to 100, and rightPower being set to -100.  This will make
    cornering the robot very aggressive at high speeds.
    
    THIS FUNCTION IS EXPERIMENTAL, DO NOT USE IN COMPETITION, UNTIL TESTED
    */
  //                    THIS METHOD RETURNS THE NUMBER NEED TO BE ADDED TO THE FIRST VARIABLE, TO CONSTRAIN IT TO THE RANGE OF NUMBERS (2ND ARG, 3RD ARG)
  int leftClampValue = Helpers::clampReturnCoeffient((double*) leftPower, -100, 100);
  int rightClampValue = Helpers::clampReturnCoeffient((double*) rightPower, -100, 100);

  if (abs(leftClampValue) > 0 && abs(rightClampValue) > 0)
  {
    printf("[Warning]: the variables for left and right power of the drivetrain are not being constrained correctly, could cause overheating, poor steering, etc\n");
    return;
  }
  if (leftClampValue != 0)
  {
    *rightPower -= leftClampValue;
  }
  else if(rightClampValue != 0)
  {
    *leftPower -= rightClampValue;
  }
}
void AggressiveArcadeControl::control(Robot* robot)
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

    powerRedistribution(&leftPower, &rightPower);

    if (robot->getController()->ButtonL1.pressing())
    {
      leftPower /= 5;
      rightPower /= 5;
    }
    robot->getDriveTrain()->powerBase(leftPower, rightPower);
  }
}