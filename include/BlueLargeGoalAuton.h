#pragma once

#include "Autonomous.h"

/** 
 * The auton that should be run when 
 * the robot is near the blue large goal
 */
class BlueLargeGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};