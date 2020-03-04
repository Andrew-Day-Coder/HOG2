#pragma once

#include "Autonomous.h"

class BlueSmallGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};