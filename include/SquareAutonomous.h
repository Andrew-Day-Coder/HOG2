#ifndef SQUAREAUTONOMOUS_H
#define SQUAREAUTONOMOUS_H


#include "vex.h"
#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"
#include "Autonomous.h"

/**
 * Just drives the robot in a square shape, used to tune the robot
 */
class SquareAutonomous : public Autonomous
{
  /* 
    This class is for testing the PID controllers
  */
  private:
    static vex::gyro* turnSensor;

    static double targetTurnDegrees;
    
    static double getError();
  public:
    /**
     * do all the setup neccessary to make the robot drive in a square
     *
     * @param turningSensor the sensor used to turn the robot
     */
    SquareAutonomous(vex::gyro* turningSensor);
    /**
     * Control the actual robot during autonomous
     *
     * @param robot the robot this control method will be controlling
     */
    void control(Robot* robot);
};

#endif