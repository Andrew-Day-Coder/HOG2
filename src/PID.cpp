#include "PID.h"
#include "Logger.h"

PID::PID(double proportionConstant, double integralConstant, double derivativeConstant, double (*errorFunction)(void))
{
  Kp = proportionConstant;
  Ki = integralConstant;
  Kd = derivativeConstant;
  integral = 0;
  lastError = 0;
  acceptableError = 0;
  this->errorFunction = errorFunction;
}
double PID::getError()
{
  return errorFunction();
}
double PID::getValue()
{
  if (errorFunction == nullptr)
  {

    Logger::log(ErrorLevel::WARNING, "PID Error function is undefined in function \"%s\", disabling\n", __PRETTY_FUNCTION__);
    return 0;
  }
  double error = errorFunction();
  double adjustment = calculateProportion(error) + calculateIntegral(error) + calculateDerivative(error); 
  lastError = error;
  return adjustment;
}

double PID::calculateProportion(double error)
{
  return error * Ki;
}
double PID::calculateIntegral(double error)
{
  integral += error;
  return integral * Ki;
}
double PID::calculateDerivative(double error)
{
  return (error - lastError) * Kd;
}
void PID::resetIntegral()
{
  integral = 0;
}