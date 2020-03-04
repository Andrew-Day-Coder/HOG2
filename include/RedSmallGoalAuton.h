#pragma once

#include "Autonomous.h"

class RedSmallGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};