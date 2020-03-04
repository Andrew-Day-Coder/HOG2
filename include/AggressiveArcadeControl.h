#pragma once

#include "DriverControl.h"
class AggressiveArcadeControl : public DriverControl{
  private:
    void powerRedistribution(int16_t* leftPower, int16_t* rightPower);
  public:
    AggressiveArcadeControl(vex::controller* cont);
    void control(DriveTrain*, Lift*, Claw*);

};
