#ifndef DRIVERCONTROL_H
#define DRIVERCONTROL_H

#include "ControlScheme.h"
class DriverControl : public ControlScheme
{
  private:
    vex::controller* cont;
  protected:
    vex::controller* getController()
    {
      return cont;
    }
  public:
    DriverControl(vex::controller* cont);
    void manageSubSystems(Lift* lift, Claw* claw);

    static int8_t sgn(int x);

    static int curve(int x, double degree, int max);
    void pidTurn(double(*errorFunction)(void));
};
#endif