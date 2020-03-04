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
    Claw(vex::motor*, vex::motor*);
    bool isOpen();
    bool isClosed();
    void open();
    void release();
    void squeeze();
    void update();

    int8_t getOpeningPower() { return openingPower; }
    int getOpeningDegrees() { return openingDegrees; }
    int8_t getSqueezePower() { return squeezePower; }

    void setOpeningPower(int8_t value) { openingPower = value;}
    void setOpeningDegrees(int value) { openingDegrees = value; }
    void setSqueezePower(int8_t value) {squeezePower = value; }
};

#endif