#ifndef ARCADECONTROL_H
#define ARCADECONTROL_H

#include "DriverControl.h"
/**
 * A left-stick throttle, right stick to turn controlling scheme for the robot
 */
class ArcadeControl : public DriverControl{
  public:
    /** 
     * Creates a new left-stick throttle, right stick turning, control system
     */
    ArcadeControl();

    /**
     * Override the control method declared in ControlScheme
     * neccessary for controlling the robot
     *
     * @param driveTrain the drivetrain for the robot
     * @param lift the lift of the robot
     * @param claw the claw of the robot
     */
    void control(Robot* robot);

};

#endif