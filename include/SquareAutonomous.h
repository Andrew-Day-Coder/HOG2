#ifndef SQUAREAUTONOMOUS_H
#define SQUAREAUTONOMOUS_H


#include "vex.h"
#include "DriveTrain.h"
#include "Lift.h"
#include "Claw.h"
#include "Autonomous.h"

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
    SquareAutonomous(vex::gyro*);
    void control(DriveTrain*, Lift*, Claw*);
};

#endif