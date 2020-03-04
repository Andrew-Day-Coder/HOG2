#ifndef PID_H
#define PID_H

class PID{
  private:
    double Kp;
    long double Ki;
    double Kd;
    double (*errorFunction)(void);

    double lastError;
    double integral;

    double calculateProportion(double);
    double calculateIntegral(double);
    double calculateDerivative(double);

    double acceptableError;
  public:
    PID(double, double, double, double (*errorFunction)(void));

    double getValue();
    void resetIntegral();
    double getError();
    
    bool isTargetReached()
    {
      return acceptableError < getError();
    }
    void setAcceptableError(int value) { acceptableError = value; }

};

#endif