#include "Grapher.h"

Grapher::Grapher(int xMin, int xMax, int yMin, int yMax){
  this->xMin = xMin;
  this->xMax = xMax;
  this->yMin = yMin;
  this->yMax = yMax;
}

void Grapher::convertPoint(double* x, double* y)
{
  double actualX = map(*x, xMin, xMax, graphDimensions[0], graphDimensions[1]);
  double actualY = map(*y, yMin, yMax, graphDimensions[1], graphDimensions[3]);

  // invert y-axis as computer graphs from top left, and humans from bottom right
  actualY = invertY(actualY);

  *x = actualX;
  *y = actualY;
}

void Grapher::addPoint(int x, int y)
{
  xCoords.push_back(x);
  yCoords.push_back(y);
}

void Grapher::graph(vex::brain::lcd* lcd)
{
  if (xCoords.size() != yCoords.size())
  {
    printf("[Warning]: mismatch length between xCoords, and yCoords in Grapher, graphing disabled\n");
    return;
  }
  if (lcd == nullptr)
  {
    printf("[Warning]: lcd is nullptr in grapher, graphing disabled\n");
    return;
  }
  
  lcd->clearScreen("#444444");
  lcd->setPenColor("#2244CC");
  lcd->setFillColor("#2244CC");

  lcd->setPenWidth(1);

  lcd->printAt(30, 30, "INFO: {MIN_X: %d, MAX_X: %d, MIN_Y: %d, MAX_Y: %d}", xMin, xMax, yMin, yMax);
  // draw the rectange the graph will display in
  lcd->drawRectangle(graphDimensions[0], graphDimensions[1], graphDimensions[2], graphDimensions[3]);
  for (int i = 0; i < xCoords.size(); i++)
  {
    // get the point
    double x = xCoords[i];
    double y = yCoords[i];

    //make sure the point is in the window
    if (x >= xMin && x <= xMax && y >= yMin && y <= yMax)
    {
      // map the points onto the graphing rectangle
      convertPoint(&x, &y);

      // draw a circle of radius 2 for the point
      lcd->drawCircle(x, y, 2);
    }
  }
  lcd->render();
}
void Grapher::graphWithAxis(vex::brain::lcd* lcd)
{
  if (lcd == nullptr)
  {
    printf("[WARNING]: lcd is nullptr when passed to Grapher::graphWithAxis, graphing disabled\n");
    return;
  }
  lcd->setPenColor("#22CC22");

  double startX = xMin;
  double startY = yMin;

  double endX = xMax;
  double endY = yMax;

  double originX = 0;
  double originY = 0;
  convertPoint(&startX, &startY);
  convertPoint(&endX, &endY);
  convertPoint(&originX, &originY);
  lcd->drawLine(startX, originY, endX, originY);
  lcd->drawLine(originX, startY, originX, endY);
  
  graph(lcd);
}
void Grapher::clear()
{
  xCoords.clear();
  yCoords.clear();
}