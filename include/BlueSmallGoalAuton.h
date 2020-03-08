#pragma once

#include "Autonomous.h"


/** 
 * The auton that should be run when 
 * the robot is near the blue small goal
 */
class BlueSmallGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};