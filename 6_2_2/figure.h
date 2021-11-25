#ifndef __FIGURE_H__
#define __FIGURE_H__
class Figure
{
public:
    virtual double area(void) = 0;
    virtual void show(void) = 0;
};

class Circle : public Figure
{
private:
    double radius;

public:
    Circle(double R);
    double area();
    void show();
};

class Rectangle : public Figure
{
private:
    double a, b;

public:
    Rectangle(double a1, double b1) : a(a1), b(b1) {}
    double area();
    void show();
};

#endif