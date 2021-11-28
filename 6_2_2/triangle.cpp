#include "includers.cpp"
#include "triangle.h"

Triangle::Triangle(double a1, double b1, double c1) // Конструктор с параметрами
{
  if (a1 > 0 || b1 > 0 || c1 > 0) // Проверка сторон треугольника
  {
    if (a1 + b1 > c1 && a1 + c1 > b1 && b1 + c1 > a1)
    {
      a = a1;
      b = b1;
      c = c1;
    }
    else
    {
      cout << "Неудача! Две малые стороны меньше или равны большей стороне";
      exit(0);
    }
  }
  else
  {
    cout << "Неудача! Стороны не могут быть 0-ми или меньше 0";
    exit(0);
  }
}
double Triangle::area() // Вычисление площади
{
  double p;
  p = a + b + c;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
void Triangle::show() // Вывод информации
{
  cout << "Фигура: Треугольник" << endl
       << "A = " << a << endl
       << "B = " << b << endl
       << "C = " << c << endl
       << "Площадь = " << area();
}