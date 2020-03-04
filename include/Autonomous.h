#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "vex.h"
#include "ControlScheme.h"
#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"
class Autonomous : public ControlScheme
{
  public:
    Autonomous();
};

#endif