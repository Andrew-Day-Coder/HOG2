#ifndef CLAW_H
#define CLAW_H
#include "vex.h"

/**
 * The claw subsystem, abstracts away the two claw motors
 */
class Claw
{
  private:
    vex::motor* leftMotor;
    vex::motor* rightMotor;
    bool isClawOpen;

    int8_t openingPower;
    int openingDegrees;
    int8_t squeezePower;
  public:
    /** 
     * Creates a new claw using a left and right motor
     *
     * @param leftMtr the left motor of the lift
     * @param rightMtr the right motor of the lift
     */
    Claw(vex::motor*, vex::motor*);
    /**
     * Tests if the claw is open, usefulf or ensureing the claw does not double-open, forcing the claw bars into the steel frame
     *
     * @return true if the claw is open, else false
     */
    bool isOpen();
    /**
     * Tests if the claw is closed, usefulf or ensureing the claw does not double-close, forcing the claw bars into the steel frame
     *
     * @return true if the claw is closed, else false
     */
    bool isClosed();

    /**
     * Opens the claw to the set opening location
     */
    void open();
    /**
     * Turns off all power to the claw giving them a sort of `coast` braketype
     */
    void release();
    /**
     * Makes the claw close with force, aka squeeze, onto an object
     */
    void squeeze();
    
    /**
     * Updates the claw, stuff to be done every tick
     */
    void update();

    /**
     * Ensure the lift is ready to use, makes sure the motors are
     * not nullptr, it also warns if any motor is uninstalled
     *
     * @param callerName the name of the function this one was called
     * by so that the error can be traced easily
     *
     * @returns true if both motors are not null.
     */
    bool isReady(const char* callerName);



    //-------------------------------------------------------------------------------//
    //-----------------------------                     -----------------------------//
    //----------------------------- GETTERS AND SETTERS -----------------------------//
    //-----------------------------                     -----------------------------//
    //-------------------------------------------------------------------------------//

    /**
     * Gets how much power the claw will open with
     * 
     * @returns the power the claw will open with
     */
    int8_t getOpeningPower() { return openingPower; }
    /**
     * Gets the number of degrees that the claw will open
     *
     * @returns the number of degrees the claw will open
     */
    int getOpeningDegrees() { return openingDegrees; }
    /**
     * Gets the power the claw will forcefully close with
     *
     * @returns the power in percent the claw will close with
     */
    int8_t getSqueezePower() { return squeezePower; }

    /**
     * Sets how much power the claw will attempt to open with
     *
     * @param value the power, in percent, the claw will attempt to close
     * with
     */
    void setOpeningPower(int8_t value) { openingPower = value;}
    /**
     * Sets how many degrees the claw will open to, doesn't translate to the real 
     * world as the claw is geared
     *
     * @param value the number of degrees the claw will attempt to open to
     */
    void setOpeningDegrees(int value) { openingDegrees = value; }
    /**
     * Sets how powerfully the claw will attempt to squeeze
     *
     * @param value the power in percent the claw will attempt to squeeze with
     */
    void setSqueezePower(int8_t value) {squeezePower = value; }
};

#endif