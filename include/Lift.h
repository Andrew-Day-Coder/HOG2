#ifndef LIFT_H
#define LIFT_H
#include "vex.h"

enum class TARGET
{
  BOTTOM,
  ALLIANCE_TOWER,
  LOW_TOWER,
  MEDIUM_TOWER,
};
class Lift
{
  private:
    vex::motor* leftMotor;
    vex::motor* rightMotor;
    bool (*isAtBottom)(void);

    // target locationing
    TARGET target;
    bool isGoingToTarget;
    double targetLocation;

    int userSpeed = 100;


    const double maxEncoderValue = 120 * 5;
    double targetLocationIncrement = 0.05;
    const double liftTolerance = 0.5;



    void setPower(int);
    void setEncoderTargetPoint(double);
    void release();
  public:
    Lift(vex::motor*, vex::motor*);
    void attachIsAtBottomFunction(bool (*bottomLimit)(void));
    void update();
    bool hasBottomFunction() { return isAtBottom != nullptr; }
    void zero();
    void findBottom();
    void hold();
    void up();
    void down();

    void smoothUp();
    void smoothDown();
    void resetTargetLocation();
    
    void setTargetLocation(TARGET);
    void cancelTarget();
    void upTarget();
    void downTarget();
    void setUserSpeed(int value) {userSpeed = value;}
    int getUserSpeed() { return userSpeed; }
    std::string getTargetAsString();
};

#endif