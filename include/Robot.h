#ifndef ROBOT_H
#define ROBOT_H

#include "DriveTrain.h"
#include "ControlScheme.h"
#include "Lift.h"
#include "Claw.h"

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
     *
     * @deprecated
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
};

#endif