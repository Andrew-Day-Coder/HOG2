#pragma once

#include "DriverControl.h"

/**
 * This is an agressive turning arcade control implemenation, instead of insuring the 
 * motors just never go above 100%, it deducts the power from both sides, such that
 * they both stay within the range of [-100, 100] this makes the robot
 * very aggressive at turning, allowing point turns at full throttle,
 * this is an experimental class so it is not gaurenteed to work,
 * or even be easy to drive, so this class exists simply to test
 * really aggressive turning mechanics
 * If the turn seems to snappy up the degree to the turn function
 * it will make the center of the sticks less sensitive
 */
class AggressiveArcadeControl : public DriverControl{
  private:
    /**
     * redistrobutes power from the left side of the drivetrain to the 
     * right side of the drivetrain.
     *
     * @param leftPower - a pointer to the left side power of the robot
     * @param rightPower - a pointer to the right side power of the robot
     */
    void powerRedistribution(int16_t* leftPower, int16_t* rightPower);
  public:
    
    /** 
     * Constructs an AggressiveArcadeControl system using a controller
     * 
     * @param cont a pointer to the controller used to control the drivetrain
     */
    AggressiveArcadeControl();
    /**
     * controls the subsystems
     * 
     * @param robot the robot to be controlled
     */
    void control(Robot* robot);

};
