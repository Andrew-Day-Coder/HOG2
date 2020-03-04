#pragma once

#include <vector>
#include "vex.h"

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

    static double map(double value, double istart, double istop, double ostart, double ostop) {
      /* this function is stolen directly fromt Java's Processing library */
      return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
    }
    void convertPoint(double*, double*);

    double invertY(int y)
    {
      return graphDimensions[3] - y;
    }
  public:
    Grapher(int xMin, int xMax, int yMin, int yMax);
    void graph(vex::brain::lcd*);
    void graphWithAxis(vex::brain::lcd*);
    void addPoint(int, int);
    void clear();
};