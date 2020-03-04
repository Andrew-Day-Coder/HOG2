#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <vector>
#include "vex.h"

enum class TurningDirection
{
  RIGHT,
  LEFT,
};
class DriveTrain
{
  private:
    std::vector<vex::motor*> leftMotors;
    std::vector<vex::motor*> rightMotors;
    bool deleteMotorsOnDestruction;
    void deleteMotors();
    static void addMotorToList(std::vector<vex::motor*>* list, vex::motor* motor);
  public:
    DriveTrain(void);
    ~DriveTrain();
    void addLeftMotor(vex::motor* mtr);
    void addRightMotor(vex::motor* mtr);
    void powerBase(int leftPower, int rightPower);
    void powerBase(int drivingPower);
    void deleteMotorsOnDestruct(bool value);
    void turnLeft(int turningPower);
    void turnRight(int turningPower);
    void driveForwardRevs(double);
    void driveForwardInches(double);
    void clamp(int* value, int min, int max);
    void pidTurn(TurningDirection td, double(*errorFunction)(void));
};

#endif