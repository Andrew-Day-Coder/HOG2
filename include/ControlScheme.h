#ifndef CONTROLSCHEME_H
#define CONTROLSCHEME_H

#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"

/**
 * The top level abstract class
 * that all autonomous and driver
 * control classes must extend
 */
class ControlScheme
{
  private:
    bool liftSmoothing = true;
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
    virtual void control(DriveTrain* driveTrain, Lift* lift, Claw* claw) = 0;
    /**
     * Ensures all the subsystems are ready to go,
     * will be replaced by a method in robot soon
     * 
     * @param driveTrain the drivetrain of the robot
     * @param lift the lift of the robot
     * @param claw the claw of the robot
     * 
     * @returns true if the subsystems are ready to go
     */
    static bool checkErrors(DriveTrain* driveTrain, Lift* lift, Claw* claw);
    /**
     * Enables/Disables lift smoothing
     *
     * @param value - true to enable smoothing, else false
     */
    void setLiftSmoothing(bool value)
    {
      liftSmoothing = value;
    }
    /**
     * Gets if lift smoothing is enabled
     *
     * @returns true if the lift will target based off of encoder location else false.
     */
    bool isLiftSmoothingEnabled()
    {
      return liftSmoothing;
    }
};

#endif