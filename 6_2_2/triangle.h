#include "figure.h"
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
class Triangle : public Figure
{
private:
  double a, b, c;

public:
  Triangle(double a1, double b1, double c1);
  double area();
  void show();
};
#endif