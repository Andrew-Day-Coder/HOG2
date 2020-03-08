#include <cmath>
#include <vector>

#include "DriveTrain.h"
#include "vex.h"
#include "Helpers.h"
#include "Logger.h"
#include "PID.h"

DriveTrain::DriveTrain(void){}
DriveTrain::~DriveTrain()
{
  if (deleteMotorsOnDestruction)
  {
    deleteMotors();
  }
};

void DriveTrain::deleteMotors()
{
  for (vex::motor* mtr : leftMotors)
  {
    if (mtr != nullptr)
    {
      // cannot free nullptr
      delete mtr;
    }
  }
  for (vex::motor* mtr : rightMotors)
  {
    if (mtr != nullptr)
    {
      delete mtr;
    }
  }
}
void DriveTrain::addMotorToList(std::vector<vex::motor*>* list, vex::motor* mtr)
{
  if (list == nullptr)
  {
    //printf("Error `list` is nullptr in DriveTrain::addMotorToList\n");
    Logger::log(ErrorLevel::WARNING, "`list` is nullptr in %s\n, could be an indication of an upcoming segfault", __PRETTY_FUNCTION__);
    return;
  }
  list->push_back(mtr);
}
void DriveTrain::addLeftMotor(vex::motor* mtr)
{
  if (mtr != nullptr)
  {
    DriveTrain::addMotorToList(&leftMotors, mtr);
  }
  else {
    //printf("[WARNING]: passed `mtr` as nullptr to DriveTrain::addLeftMotor, could lead to SEGFAULT\n");
    Logger::log(ErrorLevel::WARNING, "`mtr` is nullptr in function \"%s\"", __PRETTY_FUNCTION__);
  }
}
void DriveTrain::addRightMotor(vex::motor* mtr)
{
  if (mtr != nullptr)
  {
    DriveTrain::addMotorToList(&rightMotors, mtr);
  } else
  {
    //printf("[WARNING]: passed `mtr` as nullptr to DriveTrain::addRightMotor, could lead to SEGFAULT\n");
    Logger::log(ErrorLevel::WARNING, "`mtr` is nullptr in function \"%s\"", __PRETTY_FUNCTION__);
  }
}
void DriveTrain::powerBase(int leftPower, int rightPower)
{
  // don't exceed +-100 for power
  leftPower = Helpers::clamp(leftPower, -100, 100);
  rightPower = Helpers::clamp(rightPower, -100, 100);

  for (vex::motor* mtr : leftMotors)
  {
    // add null check
    if (mtr != nullptr)
    {
      mtr->spin(vex::directionType::fwd, leftPower, vex::velocityUnits::pct);
    }
  }
  for (vex::motor* mtr : rightMotors)
  {
    if (mtr != nullptr)
    {
      mtr->spin(vex::directionType::fwd, rightPower, vex::velocityUnits::pct);
    }
  }
}
void DriveTrain::powerBase(int drivingPower)
{
  powerBase(drivingPower, drivingPower);
}
void DriveTrain::deleteMotorsOnDestruct(bool value)
{
  deleteMotorsOnDestruction = value;
}
void DriveTrain::turnRight(int turningPower)
{
  powerBase(turningPower, -turningPower);
}
void DriveTrain::turnLeft(int turningPower)
{
  powerBase(-turningPower, turningPower);
}
void DriveTrain::driveForwardRevs(double revs)
{
  for (vex::motor* mtr : leftMotors)
  {
    // add null check
    if (mtr != nullptr)
    {
      mtr->rotateFor(vex::directionType::fwd, revs, vex::rotationUnits::rev);
    }
  }
  for (vex::motor* mtr : rightMotors)
  {
    if (mtr != nullptr)
    {
      mtr->rotateFor(vex::directionType::fwd, revs, vex::rotationUnits::rev);
    }
  }
}
void DriveTrain::pidTurn(TurningDirection td, double(*errorFunction)(void))
{
  const int turningCoeffient = 2;
  PID turningPID = PID(1.0, 0.0, 0.0, errorFunction);

  turningPID.setAcceptableError(10);
  while(!turningPID.isTargetReached())
  {
    if (td == TurningDirection::RIGHT)
    {
      turnRight(turningPID.getValue() * turningCoeffient);
    }
    if (td == TurningDirection::LEFT)
    {
      turnLeft(turningPID.getValue() * turningCoeffient);
    }
  }
}
void DriveTrain::driveForwardInches(double inches)
{
  const double wheelDiameter = 4.125; //inches
  const double wheelCircumference = wheelDiameter * M_PI;

  const double revs = inches / wheelCircumference;
  driveForwardRevs(revs);

}