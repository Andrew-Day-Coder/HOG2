#ifndef ROBOT_H
#define ROBOT_H

#include "DriveTrain.h"
#include "ControlScheme.h"
#include "Lift.h"
#include "Claw.h"

/**
 * the class that handles the subsystems for the robot
 */
class Robot
{
  private:
    Lift* lift;
    DriveTrain* driveTrain;
    ControlScheme* controlScheme;
    Claw* claw;
  public:
    /**
     * Creates a new robot with a drivetrain, lift, and claw
     */
    Robot(DriveTrain* driveTrain, Lift* lift, Claw* claw);
    /**
     * Gets the drivetrain object from the robot
     * @returns the instance of drivetrain that the robot
     * owns and controls.
     */
    DriveTrain* getDriveTrain();
    /**
     * Hands control over to a class which will control the robot
     * this can be things such as autonomous and drivercontrol
     */
    void attachControlScheme(ControlScheme* scheme);
    /**
     * calls the update method on the subsystems, which really
     * should be an interface where the update method
     * can be guarenteed. Also calls control on the 
     * current ControlScheme attached to the robot.
     */
    void sendControlPulse();
    /**
     * Sets up the controller, cannot be used
     * effectively, due to limitiations in the vex
     * api as will as c++.
     */
    void setUpController(vex::controller*);
    /**
     * Returns the lift subsystem
     *
     * @returns The poitner to the lift associated with the robot
     */
    Lift* getLift() { return lift;}
    /**
     * Returns the claw subsystem
     *
     * @returns the claw system
     */
    Claw* getClaw() { return claw;}
    /**
    * returns the control scheme
    * @returns the control scheme
    */
    ControlScheme* getControlScheme();
    
    /**
     * Ensures the subsystems for the robot are ready
     *
     * @param callerFunctionName the name of the function `__PRETTY_FUNCTION__` calling this funtion
     *
     * @returns true if the subsystems are ready for competition, else false
     */
    bool areSubsystemsReady(const char* callerFunctionName)
    {
      bool liftReady = false;
      bool driveTrainReady = false;
      bool clawReady = false;
      
      if (lift != nullptr)
      {
        if (lift->isReady(callerFunctionName))
        {
          liftReady = true;
        }
      }
      if (driveTrain != nullptr)
      {
        driveTrainReady = true;
      }
      if (claw != nullptr)
      {
        clawReady = true;
      }
      return liftReady && driveTrainReady && clawReady;
    }
};

#endif