#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "ControlScheme.h"

/**
 * The class that all autonomous's extend, stores common functionality
 */
class Autonomous : public ControlScheme
{
  public:
    Autonomous();
};

#endif