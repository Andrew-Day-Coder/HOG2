#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftBackMotor = motor(PORT6, ratio36_1, false);
motor leftFrontMotor = motor(PORT19, ratio18_1, false);
motor rightBackMotor = motor(PORT5, ratio18_1, true);
motor rightFrontMotor = motor(PORT18, ratio18_1, true);
motor leftClawMotor = motor(PORT16, ratio18_1, false);
motor leftLiftMotor = motor(PORT8, ratio18_1, true);
motor rightLiftMotor = motor(PORT20, ratio18_1, false);
gyro TurningGyro = gyro(Brain.ThreeWirePort.B);
motor rightClawMotor = motor(PORT7, ratio18_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}