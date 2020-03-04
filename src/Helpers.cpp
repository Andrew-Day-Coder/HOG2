#include "Helpers.h"

#include <math.h>
#include <stdlib.h>

double Helpers::clamp(double val, double min, double max)
{
  if (val < min) val = min;
  if (val > max) val = max;
  return val;
}
double Helpers::curve(double x, double degree, double max)
{
  return pow(max, 1 - degree) * pow(fabs(x), degree) * Helpers::signum(x);
}
int8_t Helpers::signum(double val)
{
  if (val > 0) return 1; 
  if (val < 0) return -1;
  return 0;
}
double Helpers::clampReturnCoeffient(double* x, double min, double max)
{
  double coeff = 0;
  if (*x < min)
  {
    // x + n = min, solve for n
    // n = min - x
    coeff = min - *x;
    *x = min;
  }
  if (*x > max)
  {
     // x - n = max, solve for n
     // n = -(max - *x)
     // n = -max + *x
     coeff = -max + *x;
     *x = max;
  }
  return coeff;
}