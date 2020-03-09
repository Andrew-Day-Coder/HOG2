// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         16              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         17              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Andrew                                           */
/*    Created:      Tue Feb 25 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftBackMotor        motor         6               
// leftFrontMotor       motor         19              
// rightBackMotor       motor         5               
// rightFrontMotor      motor         18              
// leftClawMotor        motor         17              
// leftLiftMotor        motor         8               
// rightLiftMotor       motor         20              
// TurningGyro          gyro          B               
// rightClawMotor       motor         11              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "DriveTrain.h"
#include "AggressiveArcadeControl.h"
#include "Robot.h"
#include "Claw.h"
#include "PushForwardAutonomous.h"
#include "SquareAutonomous.h"
#include "Logger.h"

/*
  JUST BECAUSE THIS TEXT IS HERE DOES NOT MEAN THAT I AM NOT COMING TO THE COMPETITION, I AM coming,
  but if I can't, here's this:

  Emergency Bug fixes:
    if the limit switch breaks, go to the pre_auton function;
    if something goes wrong at competition, run the code with the controller plugged into the 
      laptop, and view the terminal tab at the bottom, and see if the code tells you it's own error,
      it won't catch everything, I made every error that shows up, and I'm human, not a computer, but
      the vast majority should display.  As far as I know the code should never just end, but no promises,
      I'm human, and keeping all the errors out is difficult, even though I've done this for over a year.
    if a port for a device needs to be changed, view the devices dialog up in the upper right corner
      for the fix, do NOT go digging around the code for port numbers.  They are saved in the code
      but protected by the VEXCODE V5 IDE, so they are unchangable without digging into the settings,
      just please use the dialog.

  For the java-dev's on the teams:
    The line `#pragma once` is added to many files.  This is for ensuring
        that no file is included more than once.
    When a `*` character follow a Type (such as Lift Claw, vex::motor, etc) it means it stores the 
      memory location of an object, instead of storing the actual object.  This is the only kind of objects 
      storage, you will most commonly see in my classes. In c++, this variable or field is called a pointer.
    When a class-method is called on a pointer(see above paragraph), it uses the `->` syntax instead
      of the `.` syntax used in java.
    The classes, along with their methods, are DECLARED in the .h files, along the fields.  They are 
      IMPLEMENTED in the .cpp files, if you need to change a method of a class it is named the [TYPE's NAME]::[METHOD's NAME]
    The word virtual means the function, by java's vocab, is abstract.
    Class extension is done with the `:` syntax like 'class CLASSNAME : public PARENTCLASS', instead of java's 
      'class CLASSNAME extends PARENTCLASS' 
    
    If you really want to make or remove a class method, write it's signature in the corresponding .h file.
      It's laid out like:
        class CLASSNAME
        {
            public:
              // all public methods signatures and fields
            private:
              // all private methods signatures and fields
            protected:
              // all protected methods signatures and fields
        };
        Then move into the .cpp file, and define it using it's signature, but instead append 
        the 'ClassName::' to the method's name in the .cpp file.

        the syntax int[someNumber]_t, such as (int8_t, int16_t, int32_t, int64_t), is used to create integers
          of different bit lengths, int8_t is 8 bits, int16_t is 16 bits, and so on, this is used to preserve memory.
        
    Other Info:
      the robot->sendControlPulse updates  the lift, claw, and calls control on the set controlScheme field to control the subsystems.
      I believe VEX FIXED THIS but, if the code does not seem to be updating on each compile, like someone makes
        a change, and the Output dialog says something like "Nothing to be done for 'all'", you must go into the 
        project manually by the file browser, go Documents/vexcode-projects/HOG2 and delete or rename the build
        folder, this will force vex to re-compile.
    Class layout:
      Robot stores the subsytems and manages their control, and the current
        ControlSheme, which is registered with robot->attachControlScheme(scheme)
        like robot->attachControlSheme(new ArcadeControl(mainController))
      ArcadeControl extends DriverControl which extends ControlScheme
      TankControl extends DriverControl which extends ControlSchemes
      Lift, Claw, and DriveTrain, all all subsytems, which are thier
        own base class, which abstracts the code's control of each
      Autonomous extends ControlScheme
    An enum is simply a data-structure that is purely a state, cannot have fields, or have methods, can
      only can be compared to other enum states.  This is used for tower selection.
    The tower height targeting adjustments can be found under Lift.cpp!Lift::setTargetLocation(TARGET*)
    The claw adjustments as far as power, and open width, are in main.cpp!preauton
    A callback is method that is called when some action happens, it interupts program control flow,
      the most common use of these are in the .pressed() methods for the controller buttons, but also can be found for the brain
    The code that is passed to the callback is often times either a method's name, or a lambda, which is a little block
      of code which is unnnamed and just runs basic expressions, they are very limited but they are must shorter then
      writing a method for each button press.  They look like [](){// code in here;}
    Oh, and vex documentation can be found at https://api.vexcode.cloud/v5/html/annotated.html, or VEXCODE V5 TEXT > TOOLS > ADVANCED HELP
    The variable __PRETTY_FUNCTION__ is replaced by the gcc preprocessor with the signature of the function.
*/
/**
 * \mainpage
 *  This is the source code for Fryeburg Academy's "Heart of Gold II" robot or HOG2.  It is a very rough documentation of all the methods
 * and their usage.
 * 
 * This code base is going to be used at the Maine VEX Robotics State Championship. It has some basic functionality that can be easily 
 * generalized to other games.  
 * <ul>
 * <li> A Lift that can be used to precisely control many kinds of two motor DR4B, six bar, etc</li>
 * <li> A Claw that can be used to precisely control many kinds of two motor claws</li>
 * <li> A DriveTrain, which may be reinvented, I'm not sure, if the VEX API already has one, but it probably does,</li>
 * <li> Four Autonomous Classes that make different autonomous's for different field locations.</li>
 * <li> A Logger class that makes logging nearly as simple as printing</li>
 * <li> A PID class that allows for precise movements, such as turning, without user intervention</li>
 * <li> A limited Helpers class that contains methods that could be used in other years</li>
 * <li> An experimental AggressiveArcadeControl class that could allow for center-point turns while at full throttle</li>
 * <li> a Robot class that manages the subsystems, such as DriveTrain, Lift, and Claw, which could be generalized to other subsystems</li>
 *</ul>
 *
 */

Robot* robot;
vex::controller* mainController = new vex::controller();
vex::competition Competition;


bool setup = false;

void controllerConfig(void);
void auton(void);
void drivercontrol(void);
bool isLiftAtBottom(void);
void pre_auton(void);

bool isLiftAtBottom(void)
{
  /* 
    This function exists, because it means that a downward ultraosonic could be used for zeroing, or detecting power draw.
    It just gives the bottom of the lift a bit more functionality, than storing a limit switch

    I do realize it does destory some readability, and also organization, but I think it's a sacrifice for the flexibility it gives
  */
  // if the limit switch broke, this is not the method you really want to be in.  go to [CTRL]+[F] `***REMOVE***`...
  return false;
}
void pre_auton(void)
{
  Logger::setLogLevel(ErrorLevel::INFO);
  Logger::setOutputFile(stdout);


  // keep below line as the first line in program execution except for robot-config
  robot = new Robot(mainController, new DriveTrain(), new Lift(&leftLiftMotor, &rightLiftMotor), new Claw(&leftClawMotor, &rightClawMotor));
  
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    //add all of the motors to the drivetrain
    robot->getDriveTrain()->addLeftMotor(&leftBackMotor);
    robot->getDriveTrain()->addLeftMotor(&leftFrontMotor);
    robot->getDriveTrain()->addRightMotor(&rightBackMotor);
    robot->getDriveTrain()->addRightMotor(&rightFrontMotor);

    // define the claw
    robot->getClaw()->setOpeningDegrees(190);
    robot->getClaw()->setSqueezePower(50);
    robot->getClaw()->setOpeningPower(100);
    // zero the claw
    robot->getClaw()->zero();

    //configure the lift
    robot->getLift()->setUserSpeed(50);
    Logger::log(ErrorLevel::INFO, "Robot Subsystems Ready!!!\n");
  }
  setup = true;
}
void drivercontrol(void)
{
  // ensure null pointer error's don't happen
  if (robot == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "driver control has malfunctioned, `robot` is nullptr, in %s, exiting\n", __PRETTY_FUNCTION__);
    return;
  }
  // define the control standard for the robot
  robot->attachControlScheme(new AggressiveArcadeControl());
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    robot->getLift()->findBottomByImpact();
  }

  Logger::log(ErrorLevel::INFO, "Successfully attached a control scheme!!!\n");
  // register callbacks
  controllerConfig();

  Logger::log(ErrorLevel::INFO, "Successfully set up controller callbacks\n");
  while (true)
  {
    // send the control pulse to the subsystems
    robot->sendControlPulse();
    vex::this_thread::sleep_for(20);
  }
}
void auton(void)
{
  /* autonomous code */
  // ensure robot is not null
  if (robot == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "Autonomous Game Mode has malfunctioned, `robot` is nullptr in %s\n", __PRETTY_FUNCTION__);
    return;
  }
  robot->attachControlScheme(new SquareAutonomous(&TurningGyro));
  robot->sendControlPulse();
}
void controllerConfig(void)
{
  /*
    This method sets the `instant` callbacks, callbacks that interupt program flow
    If you don't see what your looking for here go into DriverControl.cpp
  */
  if (robot == nullptr)
  {
    Logger::log(ErrorLevel::CRITICAL, "`robot` is nullptr in main.cpp, %s\n", __PRETTY_FUNCTION__);
    return;
  }
  if (robot->areSubsystemsReady(__PRETTY_FUNCTION__))
  {
    // register all of the callbacks for the robot
    // register the claw callbacks
    robot->getController()->ButtonA.pressed([](){robot->getClaw()->open();});
    robot->getController()->ButtonB.pressed([](){robot->getClaw()->release();});
    robot->getController()->ButtonX.pressed([](){robot->getClaw()->squeeze();});
    robot->getController()->ButtonX.released([](){robot->getClaw()->release();});

    // register the lift callbacks
    robot->getController()->ButtonUp.pressed([](){robot->getLift()->setTargetLocation(TARGET::MEDIUM_TOWER);});
    robot->getController()->ButtonRight.pressed([](){robot->getLift()->setTargetLocation(TARGET::LOW_TOWER);});
    robot->getController()->ButtonDown.pressed([](){robot->getLift()->setTargetLocation(TARGET::BOTTOM);});
    robot->getController()->ButtonLeft.pressed([](){robot->getLift()->setTargetLocation(TARGET::ALLIANCE_TOWER);});

    robot->getController()->ButtonR1.pressed([](){robot->getLift()->up();});
    robot->getController()->ButtonR2.pressed([](){robot->getLift()->down();});
    robot->getController()->ButtonR1.released([](){robot->getLift()->hold();});
    robot->getController()->ButtonR2.released([](){robot->getLift()->hold();});
  }
}

int main() {
  printf("The program has called: \"%s\"\n", __PRETTY_FUNCTION__);
  vex::this_thread::sleep_for(100);
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit(); // ADD NO CODE ABOVE THIS LINE!!!!
  
  
  // pre-setup
  pre_auton();

  Competition.autonomous(auton);
  Competition.drivercontrol(drivercontrol);

  // keep the code alive, don't exit before program before competition interupts
  while(true)
  {
    vex::this_thread::sleep_for(20);
  }
}
