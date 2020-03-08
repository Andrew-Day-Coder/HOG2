#pragma once

#include "Autonomous.h"
/** 
 * The auton that should be run when 
 * the robot is near the red small goal
 */
class RedSmallGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};