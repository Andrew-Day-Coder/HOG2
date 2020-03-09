#include "Lift.h"
#include "Helpers.h"
#include "Logger.h"

Lift::Lift(vex::motor* left, vex::motor* right)
{
  // assign left and right motors
  leftMotor = left;
  rightMotor = right;

  if (!isReady(__PRETTY_FUNCTION__))
  {
    Logger::log(ErrorLevel::INFO, "Invalid args passed to Lift constructor, the motors are not really ready");
    leftMotor = nullptr;
    rightMotor = nullptr;
  }
  // basic lift setup in constructor
  
  // always assign to pointer, prevent undefined behavior
  isAtBottom = nullptr;
  

  // assign a default speed
  userSpeed = 80;
}


void Lift::zero()
{
  /*
    zeroes the encoders
  */
  if (isReady(__PRETTY_FUNCTION__))
  {
    rightMotor->resetRotation();
    leftMotor->resetRotation();
  }
}


void Lift::setTargetLocation(TARGET tower)
{
  /* 
    Makes the lift attempt to lift to defined point on field
  */

  // assign class field
  target = tower;
  // indicate state where we are traveling somewhere predefined
  isGoingToTarget = true;

  // start going to tower
  if      (tower == TARGET::BOTTOM)         setEncoderTargetPoint(10);
  else if (tower == TARGET::ALLIANCE_TOWER) setEncoderTargetPoint(445);
  else if (tower == TARGET::LOW_TOWER)      setEncoderTargetPoint(450);
  else if (tower == TARGET::MEDIUM_TOWER)   setEncoderTargetPoint(600);
}


void Lift::setEncoderTargetPoint(double value)
{
  Logger::log(ErrorLevel::INFO, "the %s method has been called\n", __PRETTY_FUNCTION__);
  // make sure the motors are ready to go
  if (isReady(__PRETTY_FUNCTION__))
  {
    value = Helpers::clamp(value, 0-liftTolerance, maxEncoderValue+liftTolerance);
    Logger::log(ErrorLevel::INFO, "The lift is headed to %f\nf", value);
    release();
    isGoingToTarget = true;

    rightMotor->startRotateTo(value, vex::rotationUnits::deg, 50, vex::velocityUnits::pct);
    leftMotor->startRotateTo(value, vex::rotationUnits::deg, 50, vex::velocityUnits::pct); 
  }
}


void Lift::setPower(int units)
{
  /*
    Sets the power that the lift motors will use
  */

  if (isReady(__PRETTY_FUNCTION__))
  {
    cancelTarget();
    leftMotor->spin(vex::directionType::fwd, units, vex::velocityUnits::pct);
    rightMotor->spin(vex::directionType::fwd, units, vex::velocityUnits::pct);
  }
}


void Lift::cancelTarget()
{
  /*
    interupts the lift's attempt to go to a predefined point
  */
  if(isGoingToTarget)
  {
    isGoingToTarget = false;
    release();
  }
}


void Lift::update()
{
  /*
    This function is for anything that needs to be updated every tick
  */
  if (isReady(__PRETTY_FUNCTION__))
  {
    //Logger::log(ErrorLevel::INFO, "The lift's location is %f\n", (rightMotor->position(vex::rotationUnits::deg) + leftMotor->position(vex::rotationUnits::deg))/2);
  }
}


void Lift::up()
{
  Logger::log(ErrorLevel::INFO, "%s called\n", __PRETTY_FUNCTION__);
  setPower(getUserSpeed());
}


void Lift::down()
{
  setPower(-getUserSpeed());
}


void Lift::release()
{
  /*
    stops the motors from targeting the predefined point
  */
  // ensure motors are not null  
  if (isReady(__PRETTY_FUNCTION__))
    {
    // stop motors
    rightMotor->stop();
    leftMotor->stop();
  }
}


void Lift::upTarget()
{
  /*
    This method makes the lift target a target that is above the current one
  */
  if      (target == TARGET::BOTTOM)         setTargetLocation(TARGET::ALLIANCE_TOWER);
  else if (target == TARGET::ALLIANCE_TOWER) setTargetLocation(TARGET::LOW_TOWER);
  else if (target == TARGET::LOW_TOWER)      setTargetLocation(target = TARGET::MEDIUM_TOWER);
}


void Lift::downTarget()
{
  /*
    This method makes the lift target a target that is below the current one
  */ 
  
  //sorry if one line if-else statements aren't your thing
  if      (target == TARGET::ALLIANCE_TOWER)  setTargetLocation(TARGET::BOTTOM);
  else if (target == TARGET::LOW_TOWER)       setTargetLocation(TARGET::ALLIANCE_TOWER);
  else if (target == TARGET::MEDIUM_TOWER)    setTargetLocation(TARGET::LOW_TOWER);
}


std::string Lift::getTargetAsString()
{

  // return the stringizitized version of the current target
  if (!isGoingToTarget)
  {
    return "None";
  }
  if (target == TARGET::BOTTOM) return "BOTTOM";
  if (target == TARGET::ALLIANCE_TOWER)  return "ALLIANCE TOWER";
  if (target == TARGET::LOW_TOWER) return "LOW TOWER";
  if (target == TARGET::MEDIUM_TOWER) return "MEDIUM TOWER";
  return "";
}


void Lift::hold()
{

  // hold the lift at a certain point
  if (isReady(__PRETTY_FUNCTION__))
  {
      leftMotor->stop(vex::brakeType::hold);
      rightMotor->stop(vex::brakeType::hold);
  }
}


void Lift::smoothUp()
{
  targetLocation += targetLocationIncrement;
  setEncoderTargetPoint(targetLocation);
}


void Lift::smoothDown()
{
  targetLocation -= targetLocationIncrement;
  setEncoderTargetPoint(targetLocationIncrement);
}



void Lift::resetTargetLocation()
{
  if (isReady(__PRETTY_FUNCTION__)){
    targetLocation = (leftMotor->position(vex::rotationUnits::rev) + rightMotor->position(vex::rotationUnits::rev)) / 2;
    setEncoderTargetPoint(targetLocation);
  }
}


void Lift::findBottomByImpact()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
  Logger::log(ErrorLevel::INFO, "%s called!!\n", __PRETTY_FUNCTION__);
  // make the lift head towards the ground
  setPower(-25);
  while(isAtBottomMeasuredByTorque())
  {
    setPower(-25);
    vex::this_thread::sleep_for(10);
  }
  // zero the lift motors
  //zero();
  leftMotor->setPosition(-30, vex::rotationUnits::deg);
  rightMotor->setPosition(-30, vex::rotationUnits::deg);
  // cease active power to motors
  release();
  }
}

bool Lift::isAtBottomMeasuredByTorque()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    double leftTorque = leftMotor->torque();
    double rightTorque = rightMotor->torque();
    double average = (leftTorque + rightTorque) / 2;
    Logger::log(ErrorLevel::INFO, "Torque Lift @ %f\n", average);
    return average < 0.7;
  }
  return false;
}
bool Lift::isMoving()
{
  if (isReady(__PRETTY_FUNCTION__))
  {
    return leftMotor->isSpinning() && rightMotor->isSpinning();
  }
  return false;
}


bool Lift::isReady(const char* functionName)
{
  // stores the states of the motors such that 
  // as many errors as possible are captured
  // at once.
  bool isEitherMotorNull = false;

  // null check the left motor
  if (leftMotor == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "`leftMotor` in lift is nullptr, called by\"%s\"\n", functionName);
    isEitherMotorNull = true;
  }
  // null check the right motor
  if (rightMotor == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "`rightMotor` in lift is nullptr, called by \"%s\"\n", functionName);
    isEitherMotorNull = true;
  }
  // return early if either motor is null, failed test
  if (isEitherMotorNull)
  {
    return false;
  }
  // ensure both motors are installed
  if (!leftMotor->installed())
  {
    Logger::log(ErrorLevel::WARNING, "`leftMotor` on the lift is not INSTALLED in \"%s\"\n", functionName);
  }
  if (!rightMotor->installed())
  {
    Logger::log(ErrorLevel::WARNING, "`rightMotor` on the lift is not INSTALLED in \"%s\"\n", functionName);
  }
  // all tests passed!!!
  return true;
}