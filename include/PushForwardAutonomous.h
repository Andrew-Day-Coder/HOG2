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
     * @param robot the robot to be controlled during autonomous
     */
    void control(Robot* robot);
};

#endif