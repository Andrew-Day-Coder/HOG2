#include "Claw.h"

Claw::Claw(vex::motor* leftMtr, vex::motor* rightMtr)
{
  if (leftMtr == nullptr)
  {
    printf("[CRITICAL]: `leftMtr` argument to Claw::Claw is nullptr\n");
    return;
  }
  if (rightMtr == nullptr)
  {
    printf("[CRITICAL]: 'rightMtr' argument to Claw::Claw is nullptr\n");
    return;
  }

  leftMotor = leftMtr;
  rightMotor = rightMtr;

  setOpeningPower(0);
  setSqueezePower(0);
  setOpeningDegrees(0);
}
void Claw::release()
{
  if (leftMotor == nullptr)
  {
    printf("[ERROR]: `leftMotor` is nullptr in Claw::release\n");
    return;
  }
  if (rightMotor == nullptr)
  {
    printf("[ERROR]: `rightMotor` is nullptr in Claw::release\n");
  }
  leftMotor->stop();
  rightMotor->stop();
}
void Claw::open()
{
  if (rightMotor == nullptr)
  {
    printf("[ERROR]: `rightMotor` is nullptr in Claw::open\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[ERROR]: `leftMotor` is nullptr in Claw::open\n");
    return;
  }
  leftMotor->startRotateFor(getOpeningDegrees(), vex::rotationUnits::deg, getOpeningPower(), vex::velocityUnits::pct);
  rightMotor->startRotateFor(getOpeningDegrees(), vex::rotationUnits::deg, getOpeningPower(), vex::velocityUnits::pct);
}
void Claw::squeeze()
{
  if (leftMotor == nullptr)
  {
    printf("[ERROR]: `leftMotor` is nullptr in Claw::squeeze");
    return;
  }
  if (rightMotor == nullptr)
  {
    printf("[ERROR]: `rightMotor` is nullptr in Claw::squueze");
  }
  leftMotor->spin(vex::directionType::rev, getSqueezePower(), vex::velocityUnits::pct);
  rightMotor->spin(vex::directionType::rev, getSqueezePower(), vex::velocityUnits::pct);
}
void Claw::update()
{

}