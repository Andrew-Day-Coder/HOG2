#pragma once

#include <inttypes.h>
/**
 * all the defined helper functions, functions used across 
 * the files int the class, also just makes a convient, copy
 * paste files that can be reused next year.
 */
class Helpers{
  public:
    /**
     * Curves the value of x between [-max, max] to a polynomial of a passed degree
     * 
     * @param x the value to be curved
     * @param degree the degree of the polynomial curve
     * @param max the range of values that will be passed to the function
     */
    static double curve(double x, double degree, double max);
    /**
     * A definition of the discontinous function called signum
     *
     * @see <a href="https://en.wikipedia.org/wiki/Sign_function">Sign Function (Wikipedia)</a>
     * @param val the value passed to the signum function
     * @returns -1 if val < 0, or 0 if val equals 0, or 1 if val > 1
     */
    static int8_t signum(double val);
    /**
     * Locks a value to a certain range
     *
     * @param val the value to restrict to [min, max]
     * @param min the minimum value of the range
     * @param max the maximum value of the range
     * 
     * @returns the value restricted to [min, max]
     */
    static double clamp(double val, double min, double max);
    /**
     * Locks a value to a certain range, BUT it returns the distance of the number from the range
     * 
     * @param x a pointer to the value that is to be locked to a certian range
     * @param min the minimum value in the range
     * @param max the maximum value in the range
     *
     * @returns the distance from the value and range
     */
    static double clampReturnCoeffient(double* x, double min, double max);
};