#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Figure
{
public:
    virtual double area(void) = 0; // Площадь
    virtual void show(void) = 0;   // Вывод информации
};

class Circle : public Figure
{
protected:
    double radius;

public:
    Circle() {}
    Circle(double R) : radius(R)
    {
        if (R <= 0)
        {
            cout << "radius < 0" << endl;
            exit(0);
        }
    }
    double area(void) { return 3.14 * radius * radius; }
    void show(void)
    {
        cout << "Фигура: Круг" << endl
             << "R: " << radius << endl
             << "Площадь: " << area() << endl;
    }
};

class Rectangle : public Figure
{
protected:
    double a;
    double b;

public:
    Rectangle() {}
    Rectangle(double a1, double b1) : a(a1), b(b1) {}
    double area(void) { return a * b; }
    void show(void)
    {
        if (a == b)
        {
            cout << "Фигура: Квадрат" << endl;
        }
        else
        {
            cout << "Фигура: Прямоугольник" << endl;
        }
        cout << "Высота: " << a << endl
             << "Ширина: " << b << endl
             << "Площадь: " << area() << endl;
    }
};

int main()
{
    Figure **figure = new Figure *[1];
    figure[0] = new Circle(5);
    figure[1] = new Rectangle(1, 2);
    for (int i = 0; i < 2; i++)
    {
        cout << "Адрес &figure[" << i << "] = " << &(figure[i]) << endl;
        figure[i]->show();
    }
}