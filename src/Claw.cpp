#include "Claw.h"
#include "Logger.h"

Claw::Claw(vex::motor* leftMtr, vex::motor* rightMtr)
{
  leftMotor = leftMtr;
  rightMotor = rightMtr;

  if (!isReady(__PRETTY_FUNCTION__))
  {
    Logger::log(ErrorLevel::INFO, "Oops, invalid args passed to Claw::Claw, probably a motor issue!\n");
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

void Claw::zero()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    leftMotor->resetRotation();
    rightMotor->resetRotation();
  }
}
bool Claw::isReady(const char* callerName)
{
  bool isLeftMotorReady = true;
  bool isRightMotorReady = true;
  
  // check if the motors exist for the program
  if (leftMotor == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "the `leftMotor` for the claw is nullpointer in %s\n", callerName);
    isLeftMotorReady = false;
  }
  if (rightMotor == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "The `rightMotor` for the Claw is nullpointer in %s\n", callerName);
    isRightMotorReady = false;
  }
  // return early if either motor is uninstalled
  if (!isLeftMotorReady || !isRightMotorReady)
  {
    Logger::log(ErrorLevel::WARNING, "The claw has encountered an error, will not be functional...\n");
    return false;
  }
  // warn if any motors are uninstalled by cut wire, wrong port, broken port, etc.
  if (!leftMotor->installed())
  {
    Logger::log(ErrorLevel::WARNING, "The `leftMotor` for the claw is UNINSTALLED in %s\n", callerName);
  }
  if (!rightMotor->installed())
  {
    Logger::log(ErrorLevel::WARNING, "The `rightMotor` for the claw is UNINSTALLED in %s\n", callerName);
  }
  return true;
}