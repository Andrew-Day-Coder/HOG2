#pragma once

#include <inttypes.h>
class Helpers{
  public:
    static double curve(double, double, double);
    static int8_t signum(double);
    static double clamp(double, double, double);
    static double clampReturnCoeffient(double*, double, double);
};