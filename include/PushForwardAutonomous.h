#ifndef PUSHFORWARDAUTONOMOUS_H
#define PUSHFORWARDAUTONOMOUS_H
#include "Autonomous.h"


class PushForwardAutonomous : public Autonomous
{
  public:
    PushForwardAutonomous();
    void control(DriveTrain*, Lift*, Claw*);
};

#endif