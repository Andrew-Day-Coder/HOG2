#ifndef PUSHFORWARDAUTONOMOUS_H
#define PUSHFORWARDAUTONOMOUS_H
#include "Autonomous.h"


/**
 * A basic autonomous that pushes a cube into the corner
 */
class PushForwardAutonomous : public Autonomous
{
  public:
    /**
     * Sets up the basic functionality of a push forward autonomous
     */
    PushForwardAutonomous();
    /**
     * Control the actual robot during autonomous
     *
     * @param driveTrain the drivetrain for the robot
     * @param lift the lift of the robot
     * @param claw the claw of the robot
     */
    void control(DriveTrain* driveTrain, Lift* lift, Claw* claw);
};

#endif