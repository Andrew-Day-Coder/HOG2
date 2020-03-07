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
    /**
     * creates a new drivetrain object
     */
    DriveTrain(void);
    /**
     * Code to cleanup the drivetrain when destroyed
     */
    ~DriveTrain();

    /**
     * Adds a motor to the left side of the drive train.
     * @param mtr - the motor to be added
     */
    void addLeftMotor(vex::motor* mtr);
    /**
     * Adds a motor to the right side of the drive train.
     * @param mtr - the motor to be added
     */
    void addRightMotor(vex::motor* mtr);

    /**
     * The power the each base side should be set to
     *
     * @param leftPower - the power to the left side of the base
     * @param rightPower - the power to the right side of the base
     */
    void powerBase(int leftPower, int rightPower);

    /**
     * The power to the entire base, useful for driving directly forward-ish
     *
     * @param drivingPower - the speed of the motors, with which to move
     */
    void powerBase(int drivingPower);
    /**
     * sets whether the motors should be deleted after the drivetrain is deleted
     */
    void deleteMotorsOnDestruct(bool value);
    /**
     * Turns the robot left with a certain power, positive on the left side of the base, negative power to the right side of the base
     * The number does not determine how far the robot will turn, but instead how fast it will turn. Makes a point turn centered
     * at the base of the robot.
     *
     * @param turningPower - the power with which to turn
     */
    void turnLeft(int turningPower);
    /**
     * Turns the robot right with a certain power, positive on teh rigth side of the base, negative power to the left side of the base
     * The argument does not determine how far the robot will turn, but instead how fast it will turn. Makes a point turn centered
     * at the base of the robot
     */
    void turnRight(int turningPower);

    /**
     * Turns the wheels a certain number of revolutions
     *
     * @param revolutions - the number of revolutions to turn the wheel
     */
    void driveForwardRevs(double);
    /**
     * Turns the wheels, such that they will move the robot a certain number
     * of inches forward, this uses PID to control how far the robot will move
     * Must be tuned.
     *
     * @param inches - the number of inches to move forward
     */
    void driveForwardInches(double);
    /**
     * Makes a PID based turn
     * @param td - the turning direction to turn in
     * @param errorFunction - the function that calculates error
     */
    void pidTurn(TurningDirection td, double(*errorFunction)(void));
};

#endif