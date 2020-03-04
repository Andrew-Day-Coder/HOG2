#pragma once

#include "Autonomous.h"

class RedLargeGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};