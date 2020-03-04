#include "SquareAutonomous.h"
#include "PID.h"
#include "Autonomous.h"

vex::gyro* SquareAutonomous::turnSensor = nullptr;
double SquareAutonomous::targetTurnDegrees = 0;

double SquareAutonomous::getError()
{
  return targetTurnDegrees - turnSensor->rotation(vex::rotationUnits::deg);
}
SquareAutonomous::SquareAutonomous(vex::gyro* turningSensor)
{
  turnSensor = turningSensor;
  targetTurnDegrees = 0;
}
void SquareAutonomous::control(DriveTrain* driveTrain, Lift* lift, Claw* claw)
{
  if (checkErrors(driveTrain, lift, claw))
  {
    printf("[CRITICAL]: a nullptr was passed to SquareAutonomous::control");
  }
  if (turnSensor == nullptr)
  {
    printf("[Warning]: turnSensor is nullptr in SquareAutonomous::control, autonomous disabled\n");
    return;
  }

  targetTurnDegrees = 0;
  for (int x = 0; x < 4; x++)
  {
    driveTrain->driveForwardInches(10);
    targetTurnDegrees += 90;
    driveTrain->pidTurn(TurningDirection::LEFT, SquareAutonomous::getError);
  }

}