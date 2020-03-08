#pragma once

#include <vector>
#include "vex.h"

/**
 * Makes the brain screen into a basic graph display
 */
class Grapher
{
  /*
    This class exists because of pid tuning
  */
  private:
    std::vector<double> xCoords;
    std::vector<double> yCoords;

    int xMin;
    int yMin;
    int xMax;
    int yMax;

    int graphDimensions[4] = {20, 20, 400, 200};

    /**
     * Makes a correlation between one set of numbers and another, ripped directly 
     * from Java's processing environment.
     * 
     * @param value the actual value between [istart, ostop]
     * @param istart the min value of the starting range of values
     * @param istop the max value of the starting range of values
     * @param ostart the min value of the destination range of values
     * @param ostop the max value of the destination range of values
     *
     * @returns the value projected from the range of [istart, istop] to the range of [ostart, ostop]
     */
    static double map(double value, double istart, double istop, double ostart, double ostop) {
      /* this function is stolen directly fromt Java's Processing library */
      return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
    }
    /**
     * Translate the point from the math realm onto the brain screen
     * 
     * @param x a pointer to the x-coord of the point
     * @param y a pointer to the y-coord of the point
     */
    void convertPoint(double* x, double* y);

    /**
     * mirrors the graph over the center of the graphing area horizontally,
     * because somebody decided (0,0) is the top-left corner instead of 
     * bottom left corner
     * 
     * @param y the value of the y coordinate
     */
    double invertY(int y)
    {
      return graphDimensions[3] - y;
    }
  public:
    /**
     * Constructor for the graphing classs
     *
     * @param xMin the minimum x value passed to the function
     * @param xMax the maximum x value passed to the function
     * @param yMin the minimum y value passed to the function
     * @param yMax the maximum y value passed to the function
     */
    Grapher(int xMin, int xMax, int yMin, int yMax);
    /**
     * graphs the function onto the brain screen
     * 
     * @param lcd - the lcd to display the graph on
     */
    void graph(vex::brain::lcd* lcd);
    /**
     * draws the axis onto the brain screen then calls graph
     *
     * @param lcd - the lcd to display the graph on
     */
    void graphWithAxis(vex::brain::lcd* lcd);
    /**
     * adds a point to the graph
     *
     * @param x the x coordinate of the point
     * @param y the y coordinate of the point
     */
    void addPoint(int x, int y);
    /**
     * clears the graphing interface
     */
    void clear();
};