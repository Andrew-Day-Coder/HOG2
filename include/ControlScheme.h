#pragma once

#include "DriveTrain.h"
#include "Robot.h"
#include "Logger.h"

// circular reference to robot class so this needs to be declared
class Robot;

/**
 * The top level abstract class
 * that all autonomous and driver
 * control classes must extend
 */
class ControlScheme
{
  public:
    /**
     * does all of the stuff to set up a control scheme
     */
    ControlScheme();
    /**
     * A method called by the Robot class, should not be an
     * while loop.
     * 
     * @param driveTrain the robot's driveTrain
     * @param lift the robot's lift
     * @param claw the robot's claw
     */
    virtual void control(Robot* robot) = 0;
};