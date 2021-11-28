#include "figure.h"
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
class Triangle : public Figure
{
private:
  double a, b, c;

public:
  Triangle(double a1, double b1, double c1); // Конструктор с параметрами
  double area();                             // Вычисление площади
  void show();                               // Вывод информации
};
#endif