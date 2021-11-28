#ifndef __FIGURE_H__
#define __FIGURE_H__
class Figure
{
public:
    virtual double area(void) = 0; // Площадь
    virtual void show(void) = 0;   // Вывод информации
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double R); // Конструктор с параметрами
    double area();    // Вычисление площади
    void show();      // Вывод информации
};

class Rectangle : public Figure
{
private:
    double a, b;

public:
    Rectangle(double a1, double b1); // Конструктор с параметрами
    double area();                   // Вычисление площади
    void show();                     // Вывод информации
};

#endif