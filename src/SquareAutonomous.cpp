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
void SquareAutonomous::control(Robot* robot)
{
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    if (turnSensor == nullptr)
    {
      Logger::log(ErrorLevel::WARNING, "turnSensor is nullptr in %s, autonomous disabled\n", __PRETTY_FUNCTION__);
      return;
    }

    targetTurnDegrees = 0;
    for (int x = 0; x < 4; x++)
    {
      robot->getDriveTrain()->driveForwardInches(10);
      targetTurnDegrees += 90;
      robot->getDriveTrain()->pidTurn(TurningDirection::LEFT, SquareAutonomous::getError);
    }
  }
}