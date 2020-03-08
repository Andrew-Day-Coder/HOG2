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
/**
 * This is an abstraction of the robot's lift.  
 * Protects the programmer from accidentally doing
 * something undesireable with the lift
 */
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

    int userSpeed = 50;


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
     * @param right - the right motor 
     */
    Lift(vex::motor*, vex::motor*);
    
    /**
     * This function returns true if the lift is ready to operate
     * it will throw warnings if possible.  The boolean output
     * should not be ignored, as ignoring it will allow
     * for unsafe function calls on pointers.  Pass __PRETTY_FUNCTION__
     * to the function, to trace where the error originated.
     * this allows for the error to be traced to the source way
     * more easily.
     * 
     * @returns true if the motors are non-null else false
     */
    bool isReady(const char* functionName);

    /**
     * Returns true if the motors on the 
     * lift are spinning, else it returns 
     * false.
     * 
     * @returns true if the lift is moving else false
     */
    bool isMoving();
    /**
     * Finds the bottom of the lift, by lowering
     * until the lift stops moving.  This sets
     * the zero point easily, and makes it so
     * that hardware failures will not interfere
     * with the lift's autotargeting ability.
     */
    void findBottomByImpact();
    /**
     * Associates a function that can tell when the lift
     * when it has reached the bottom.
     *
     * @param bottomLimit - a function pointer to a function that can
     * tell the code when it is at the bottom of the lift.
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
     * to the setPower funtion.
     * 
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
    
    /**
     * Sets the robot to target a tower of enum type TARGET.  Doesn't work right now, not sure why, don't use
     * 
     * @param tower - the tower the to target.
     */
    void setTargetLocation(TARGET);

    /**
     * Cancels the current targeting based off of encoder
     */
    void cancelTarget();
    /**
     * Changes the target to one up from the current one
     */
    void upTarget();
    /**
     * Changes the target to one down from the current one
     */
    void downTarget();
    /**
     * Sets the speed used to raise and lower the lift
     *
     * @param value - the power in percent used to raise and lower the lift
     */
    void setUserSpeed(int value) {userSpeed = value;}
    /**
     * Gets the speed used to raise and lower the lift
     *
     * @returns the power in percent used to raise and lower the lift
     */
    int getUserSpeed() { return userSpeed; }
    /**
     * Gets an text-based representation of the current target as a string
     * @returns A string representing the target of the lift
     */
    std::string getTargetAsString();
};

#endif