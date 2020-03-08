#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "vex.h"
#include "ControlScheme.h"
#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"

/**
 * The class that all autonomous's extend, stores common functionality
 */
class Autonomous : public ControlScheme
{
  public:
    Autonomous();
};

#endif