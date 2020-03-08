#ifndef DRIVERCONTROL_H
#define DRIVERCONTROL_H

#include "ControlScheme.h"
/**
 * A class that all of the driving
 * types extend, also it manages the subsystems
 * control directly, by using the passed controller
 */
class DriverControl : public ControlScheme
{
  private:
    vex::controller* cont;
  protected:
    /**
     * gets the active controller used to control the robot
     * 
     * @returns the controller used to control the ControlScheme
     */
    vex::controller* getController()
    {
      return cont;
    }
  public:
    /**
     * creates a new driver control
     * 
     * @param cont the controller to use for the drivetrain
     */
    DriverControl(vex::controller* cont);
    /**
     * manage the control of the subsystems, such as the lift and the claw
     */
    void manageSubSystems(Lift* lift, Claw* claw);

    /**
     * Be able to make a turn based off of pid
     * 
     * @param errorFunction a pointer to the function that returns an error
     */
    void pidTurn(double(*errorFunction)(void));
};
#endif