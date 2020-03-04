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
  private;
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


    /**
     * Sets the power of the lift, used for when the driver
     * is attempting to use the lift, a lift to fast, will
     * be difficult to control, but too slow, and it wastes time.
     *
     * @param units - the value, in percent, that the motors
     * will be powered with when lifting, and lowering.
     */

    void setPower(int);
    /**
     * Sets a rotation point, in degrees, that the motor
     * will attempt to go to. 
     *
     * @param value - the value, in degrees, that the motors
     * will attempt to go to.
     */
    void setEncoderTargetPoint(double);
    /**
     * Do not spin the motors, at all, don't hold, just let them `vex::brakeType::coast`    
     */
    void release();
  public:
    /**
     * Creates a new lift
     * 
     * @param left - the left motor,
     * @param rigth - the right motor 
     */
    Lift(vex::motor*, vex::motor*);

    /**
     * Associates a function that can tell when the lift
     * when it has reached the bottom.
     *
     * @param bottomLimit - a function pointer to a function that can
     * tell the code when it is at the bottom of the lift.
     * @deprecated
     */
    void attachIsAtBottomFunction(bool (*bottomLimit)(void));
    /**
     * Function to be called on every tick of the lift for the lift
     */
    void update();
    /**
     * A way to request if the lift has a way to tell if it
     * can tell if it is at the bottom
     *
     * @returns true if lift can determine the bottom, else false
     * @deprecated
     */
    bool hasBottomFunction() { return isAtBottom != nullptr; }
    /**
     * Zeroes the motor encoders
     */
    void zero();
    /**
     * Makes the lift attempt to find it's bottom, must
     * have a "bottoming" function associated with it
     */
    void findBottom();
    /**
     * Holds the lift where it is
     */
    void hold();
    /**
     * Makes the lift go up with whatever power is passed
     * to the setPower funtion
     */
    void up();
    /**
     * Makes the lift go down with whatever power is passed
     * to the setPower funtion
     */
    void down();

    /**
     * Makes the lift raise, by setting the encoder target.
     */
    void smoothUp();
    /**
     * Makes the lift lower by setting the encoder target
     */
    void smoothDown();
    /**
     * resets the encoder target location, useful for canceling actions
     */
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