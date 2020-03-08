#include "Claw.h"

Claw::Claw(vex::motor* leftMtr, vex::motor* rightMtr)
{
  leftMotor = leftMtr;
  rightMotor = rightMtr;

  if (!isReady(__PRETTY_FUNCTION__))
  {
    printf("Oops, invalid args passed to Claw::Claw, probably a motor issue!\n");
  }
  setOpeningPower(0);
  setSqueezePower(0);
  setOpeningDegrees(0);
}
void Claw::release()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    leftMotor->stop();
    rightMotor->stop();
  }
}
void Claw::open()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    leftMotor->startRotateFor(getOpeningDegrees(), vex::rotationUnits::deg, getOpeningPower(), vex::velocityUnits::pct);
    rightMotor->startRotateFor(getOpeningDegrees(), vex::rotationUnits::deg, getOpeningPower(), vex::velocityUnits::pct);
  }
}
void Claw::squeeze()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    leftMotor->spin(vex::directionType::rev, getSqueezePower(), vex::velocityUnits::pct);
    rightMotor->spin(vex::directionType::rev, getSqueezePower(), vex::velocityUnits::pct);
  }
}
void Claw::update()
{

}

bool Claw::isReady(const char* callerName)
{
  bool isLeftMotorReady = true;
  bool isRightMotorReady = true;
  
  // check if the motors exist for the program
  if (leftMotor != nullptr)
  {
    printf("[CRITICAL]: `left motor` for the claw is nullptr in %s\n", callerName);
    isLeftMotorReady = false;
  }
  if (rightMotor != nullptr)
  {
    printf("[CRITICAL]: `right motor` for the claw is nullptr in %s\n", callerName);
    isRightMotorReady = false;
  }
  // return early if either motor is uninstalled
  if (!isLeftMotorReady || !isRightMotorReady)
  {
    return false;
  }
  // warn if any motors are uninstalled by cut wire, wrong port, broken port, etc.
  if (!leftMotor->installed())
  {
    printf("[WARNING]: `left motor` for the claw is UNINSTALLED in %s\n", callerName);
  }
  if (!rightMotor->installed())
  {
    printf("[WARNING]: `right motor` for the claw is UNINSTALLED in %s\n", callerName);
  }
  return true;
}