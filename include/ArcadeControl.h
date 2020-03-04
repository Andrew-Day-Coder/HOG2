#ifndef ARCADECONTROL_H
#define ARCADECONTROL_H

#include "DriverControl.h"
class ArcadeControl : public DriverControl{
  public:
    ArcadeControl(vex::controller* cont);
    void control(DriveTrain*, Lift*, Claw*);

};

#endif