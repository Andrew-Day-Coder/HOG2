#pragma once

#include "Autonomous.h"

class BlueLargeGoalAuton : public Autonomous
{
  private:
  public:
    void control(DriveTrain*, Lift*, Claw*);
};