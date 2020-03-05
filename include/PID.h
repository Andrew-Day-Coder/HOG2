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

    /**
     * Calculates the proportion section of the PID
     * 
     * @param error - the current error
     * @returns Kp * error, which is the proportional part of PID
     */
    double calculateProportion(double error);
    /**
     *  Calculates the integral section of PID
     * 
     * @param error - the current error
     * @returns Ki*integral, which is the integral part of PID
     */
    double calculateIntegral(double);
    /**
     * Calculates the derivative section of PID
     *
     * @param error - the current error
     * @returns Kd*(error - lastError), which is the derivative part of PID
     */
    double calculateDerivative(double);

    double acceptableError;
  public:
    /**
     * Creates a PID
     *
     * @param Kp - the constant with which to multiply error
     * @param Ki - the constant to multiply with the sum of all errors
     * @param Kd - the constant to multiply with the difference of this error and the last error
     * @param errorFunction - a pointer to the function used to calculate error
     */ 
    PID(double Kp, double Ki, double Kd, double (*errorFunction)(void));

    /**
     * Gets the result of the PID calculation (Kp * error) + (Ki * integral) + (Kd * derivative)
     * 
     * @returns the result of the pid calculation
     */
    double getValue();
    /**
     * Resets the integral section of PID
     */
    void resetIntegral();
    /**
     * safely calls the error function passed to the constructor
     */
    double getError();
    
    /**
     * Calculates if the error is within an acceptable range
     * 
     * @returns true if the error is in the range of acceptable error
     */
    bool isTargetReached()
    {
      return acceptableError < fabs(getError());
    }
    /**
     * Sets the acceptable error
     * 
     * @param value - the value for the acceptable error
     */
    void setAcceptableError(int value) { acceptableError = value; }

};

#endif