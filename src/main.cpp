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
    The variable __PRETTY_FUNCTION__ is replaced by the gcc preprocessor with the name of the signature of the function.
*/
DriveTrain* driveTrain = new DriveTrain();
Robot* robot;
vex::controller* mainController = new vex::controller();
vex::competition Competition;


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

  Logger::setLogLevel(ErrorLevel::WARNING);
  Logger::setOutputFile(stdout);

  // keep below line as the first line in program execution except for robot-config
  robot = new Robot(new DriveTrain(), new Lift(&leftLiftMotor, &rightLiftMotor), new Claw(&leftClawMotor, &rightClawMotor));
  
  //add all of the motors to the drivetrain
  robot->getDriveTrain()->addLeftMotor(&leftBackMotor);
  robot->getDriveTrain()->addLeftMotor(&leftFrontMotor);
  robot->getDriveTrain()->addRightMotor(&rightBackMotor);
  robot->getDriveTrain()->addRightMotor(&rightFrontMotor);

  // define the claw
  robot->getClaw()->setOpeningDegrees(225);
  robot->getClaw()->setSqueezePower(50);
  robot->getClaw()->setOpeningPower(100);

  //configure the lift
  robot->getLift()->setUserSpeed(50);
  // to prevent the last two game malfunctions at Cape Qualifier 1st tournament, simply ***REMOVE** this line if the switch breaks
  // this line will be removed soon
  robot->getLift()->attachIsAtBottomFunction(isLiftAtBottom);
}
void drivercontrol(void)
{
  // ensure null pointer error's don't happen
  if (robot == nullptr)
  {
    printf("[CRITICAL]: drivercontrol has malfunctioned, `robot` is nullptr, in main.cpp!drivercontrol, exiting");
    return;
  }
  // define the control standard for the robot
  robot->attachControlScheme(new AggressiveArcadeControl(mainController));
  robot->getControlScheme()->setLiftSmoothing(false);

  // register callbacks
  controllerConfig();
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
    printf("[CRITICAL]: Autonomous Game Mode has malfunctioned, `robot` is nullptr, in function main.cpp!auton, will probably be evident in drivercontrol\n");
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
  if (mainController == nullptr)
  {
    printf("[CRITCIAL]: the main controller is `nullptr` robotic controls are disabled!!!\n");
    return;
  }
  if (robot == nullptr)
  {
    printf("[CRITICAL]: `robot` is nullptr in main.cpp!controllerConfig, aborted config, robot uncontrollable");
  }
  if (robot->getLift() == nullptr)
  {
    printf("[CRITICAL]: robot->getLift() returns `nullptr` in main.cpp!controllerConfig, aborted config, robot uncontrollable");
    return;
  }
  if (robot->getClaw() == nullptr)
  {
    printf("[CRITICAL]: robot->getClaw() returns `nullptr` in main.cpp!controllerConfig, aborted config, robot uncontrollable");
    return;
  }
  // register all of the callbacks for the robot
  // register the claw callbacks
  mainController->ButtonA.pressed([](){robot->getClaw()->open();});
  mainController->ButtonB.pressed([](){robot->getClaw()->release();});
  mainController->ButtonX.pressed([](){robot->getClaw()->squeeze();});

  // register the lift callbacks
  mainController->ButtonUp.pressed([](){robot->getLift()->setTargetLocation(TARGET::LOW_TOWER);});
  mainController->ButtonLeft.pressed([](){robot->getLift()->setTargetLocation(TARGET::MEDIUM_TOWER);});
  mainController->ButtonDown.pressed([](){robot->getLift()->setTargetLocation(TARGET::BOTTOM);});
  mainController->ButtonRight.pressed([](){robot->getLift()->setTargetLocation(TARGET::ALLIANCE_TOWER);});

  // if the simple control system must be used then remove this line
  mainController->ButtonR1.pressed([](){robot->getLift()->resetTargetLocation();});
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit(); // ADD NO CODE ABOVE THIS LINE!!!!
  
  Competition.autonomous(auton);
  Competition.drivercontrol(drivercontrol);

  // pre-setup
  pre_auton();

  // keep the code alive, don't exit before program before competition interupts
  while(true)
  {
    vex::this_thread::sleep_for(20);
  }
}
