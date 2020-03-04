#ifndef CONTROLSCHEME_H
#define CONTROLSCHEME_H

#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"

class ControlScheme
{
  private:
    bool liftSmoothing = true;
  public:
    ControlScheme();
    virtual void control(DriveTrain*, Lift*, Claw*) = 0;
    static bool checkErrors(DriveTrain*, Lift*, Claw*);
    void setLiftSmoothing(bool value)
    {
      liftSmoothing = value;
    }
    bool isLiftSmoothingEnabled()
    {
      return liftSmoothing;
    }
};

#endif