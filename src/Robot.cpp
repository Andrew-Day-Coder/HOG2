#include "Robot.h"
#include <iostream>
#include "Logger.h"

Robot::Robot(vex::controller* robotController, DriveTrain* driveTrain, Lift* lift, Claw* claw){
  this->driveTrain = driveTrain;
  this->lift = lift;
  this->claw = claw;
  this->robotController = robotController;
}

void Robot::attachControlScheme(ControlScheme* scheme)
{
  controlScheme = scheme;
}


ControlScheme* Robot::getControlScheme()
{
  if (controlScheme == nullptr)
  {
    //printf("[WARNING]: Control Scheme returned is nullptr in Robot::getControlScheme\n");
    Logger::log(ErrorLevel::WARNING, "Control Scheme is nullptr in %s\n", __PRETTY_FUNCTION__);
  }
  return controlScheme;
}

void Robot::sendControlPulse()
{
  if (controlScheme != nullptr)
  {
    controlScheme->control(this);
    if (areSubsystemsReady(__PRETTY_FUNCTION__))
    {
      lift->update();
    }
  }
  else
  {
    Logger::log(ErrorLevel::WARNING, "No control scheme defined in Robot::sendControlPulse\n");
  }
}



bool Robot::areSubsystemsReady(const char *callerFunctionName)
{
  bool liftReady = false;
  bool driveTrainReady = false;
  bool clawReady = false;
  bool controllerReady = false;
  
  // lift error checks
  if (lift != nullptr)
  {
    if (lift->isReady(callerFunctionName))
    {
      liftReady = true;
    }
  }else
  {
    Logger::log(ErrorLevel::CRITICAL, "The Robot's lift is either nullptr in method %s when called by method %s\n", __PRETTY_FUNCTION__, callerFunctionName);
  }

  // drivetrain error checks
  if (driveTrain != nullptr)
  {
    driveTrainReady = true;
  }else
  {
    Logger::log(ErrorLevel::CRITICAL, "The Robot's driveTrain is nullptr in method %s when called by method %s\n", __PRETTY_FUNCTION__, callerFunctionName);
  }
  

  // claw error checks
  if (claw != nullptr)
  {
    clawReady = true;
  }else
  {
    Logger::log(ErrorLevel::CRITICAL, "The Robot's claw is nullptr in method %s when called by method %s\n", __PRETTY_FUNCTION__, callerFunctionName);
  }

  if (getController() != nullptr)
  {
    if (getController()->installed())
    {
      controllerReady = true;
    }
  } else
  {
    Logger::log(ErrorLevel::INFO, "The Robot's controller is nullptr in method %s when called by method %s\n", __PRETTY_FUNCTION__, callerFunctionName);
  }
  // return success of failure
  return liftReady && driveTrainReady && clawReady && controllerReady;
}
