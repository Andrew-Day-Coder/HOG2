using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftBackMotor;
extern motor leftFrontMotor;
extern motor rightBackMotor;
extern motor rightFrontMotor;
extern motor leftClawMotor;
extern motor leftLiftMotor;
extern motor rightLiftMotor;
extern gyro TurningGyro;
extern motor rightClawMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );