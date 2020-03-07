#ifndef CLAW_H
#define CLAW_H
#include "vex.h"

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
     * Gets how much power the claw will open with
     * 
     * @returns the power the claw will open with
     */
    int8_t getOpeningPower() { return openingPower; }
    int getOpeningDegrees() { return openingDegrees; }
    int8_t getSqueezePower() { return squeezePower; }

    void setOpeningPower(int8_t value) { openingPower = value;}
    void setOpeningDegrees(int value) { openingDegrees = value; }
    void setSqueezePower(int8_t value) {squeezePower = value; }
};

#endif