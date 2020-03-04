#include "Lift.h"
#include "Helpers.h"

Lift::Lift(vex::motor* left, vex::motor* right)
{
  if (left == nullptr)
  {
    printf("[CRITICAL]: `leftMotor` is nullptr in Lift constructor (Lift::Lift)\n");
    return;
  }
  if (right == nullptr)
  {
    printf("[CRITICAL]: `rightMotor` is nullptr in Lift constructor (Lift::lift)\n");
    return;
  }
  // basic lift setup in constructor
  
  // always assign to pointer, prevent undefined behavior
  isAtBottom = nullptr;
  
  // assign left and right motors
  leftMotor = left;
  rightMotor = right;

  // assign a default speed
  userSpeed = 80;
}
void Lift::zero()
{
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: No registered right lift motor in Lift::zero\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: No registered left lift motor in Lift::zero\n");
    return;
  }
  rightMotor->resetRotation();
  leftMotor->resetRotation();
}

void Lift::attachIsAtBottomFunction(bool (*bottomLimit)(void))
{
  /*
    assigns to a function pointer, so that lift knows when it at the bottom
  */

  if (bottomLimit == nullptr)
  {
    printf("[WARNING]: `bottomLimit` boolean function pointer is nullptr in Lift::attachIsAtBottomFunction, some functionality may be lost\n");
  }
  isAtBottom = bottomLimit;
}
void Lift::findBottom()
{
  /* 
    This method lowers the lift until it reaches the limit, then zeroes, useful for autonomous
    The reason for the iteration variable is incase of mechanical failure.
  */
  if(hasBottomFunction())
  {
    int iteration = 0;
    while(!isAtBottom() && iteration < 1000)
    {
      // reset power in here if not strong enough
      setPower(-25);
      iteration++;
      vex::this_thread::sleep_for(20);
    }
    // zero the lift when the "bottom" is reached
    zero();
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
  if      (tower == TARGET::BOTTOM)         setEncoderTargetPoint(0);
  else if (tower == TARGET::ALLIANCE_TOWER) setEncoderTargetPoint(1);
  else if (tower == TARGET::LOW_TOWER)      setEncoderTargetPoint(1.25);
  else if (tower == TARGET::MEDIUM_TOWER)   setEncoderTargetPoint(1.5);
}
void Lift::setEncoderTargetPoint(double value)
{
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: `rightMotor` is nullptr in setEncoderTargetPoint\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: `leftMotor` is nullptr in setEncoderTargetPoint\n");
    return;
  }
  Helpers::clamp(value, 0-liftTolerance, maxEncoderValue+liftTolerance);
  isGoingToTarget = true;
  rightMotor->startRotateTo(value, vex::rotationUnits::deg, 100, vex::velocityUnits::pct);
  leftMotor->startRotateTo(value, vex::rotationUnits::deg, 100, vex::velocityUnits::pct); 
}
void Lift::setPower(int units)
{
  /*
    Sets the power that the lift motors will use
  */

  // null check the motors, don't want a SEGFAULT
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: No registered right lift motor in Lift::setPower\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: No registered left lift motor in Lift::setPower\n");
    return;
  }
  cancelTarget();
  leftMotor->spin(vex::directionType::fwd, units, vex::velocityUnits::pct);
  rightMotor->spin(vex::directionType::fwd, units, vex::velocityUnits::pct);
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
  // calibrate lift at bottom
  if (hasBottomFunction())
  {
    if (isAtBottom())
    {
      zero();
    }
  }
}
void Lift::up()
{
  cancelTarget();
  setPower(getUserSpeed());
}
void Lift::down()
{
  cancelTarget();
  setPower(-getUserSpeed());
}
void Lift::release()
{
  /*
    stops the motors from targeting the predefined point
  */
  // ensure motors are not null  
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: No registered right lift motor in Lift::release\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: No registered left lift motor in Lift::release\n");
    return;
  }
  // stop motors
  rightMotor->stop();
  leftMotor->stop();
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
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: No registered right lift motor in Lift::hold\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: No registered left lift motor in Lift::hold\n");
    return;
  }
  leftMotor->stop(vex::brakeType::hold);
  rightMotor->stop(vex::brakeType::hold);
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
  if (rightMotor == nullptr)
  {
    printf("[CRITICAL]: No registered right lift motor in Lift::resetTargetLocation\n");
    return;
  }
  if (leftMotor == nullptr)
  {
    printf("[CRITICAL]: No registered left lift motor in Lift::resetTargetLocation\n");
    return;
  }
  targetLocation = (leftMotor->position(vex::rotationUnits::rev) + rightMotor->position(vex::rotationUnits::rev)) / 2;
  setEncoderTargetPoint(targetLocation);
}

