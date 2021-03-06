#pragma once

#include "Autonomous.h"
/** 
 * The auton that should be run when 
 * the robot is near the red small goal
 */
class RedSmallGoalAuton : public Autonomous
{
  public:
    /**
     * Control the actual robot during autonomous
     *
     * @param robot the robot this control method will be controlling
     */
    void control(Robot* robot);
};