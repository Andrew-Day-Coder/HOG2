#pragma once

#include "Autonomous.h"


/** 
 * The auton that should be run when 
 * the robot is near the blue small goal
 */
class BlueSmallGoalAuton : public Autonomous
{
  public:
    /**
     * Control the actual robot during autonomous
     *
     * @param robot the robot this control method will be controlling
     */
    void control(Robot* robot);
};