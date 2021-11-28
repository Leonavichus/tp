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
    Circle() {}                  // Конструктор без параметров
    Circle(double R) : radius(R) // Конструктор с параметрами
    {
        if (R <= 0)
        {
            cout << "radius < 0" << endl;
            exit(0);
        }
    }
    double area(void) { return 3.14 * radius * radius; } // Вычисление площади
    void show(void)                                      // Вывод информации
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
    Rectangle() {}                                 // Конструктор без параметров
    Rectangle(double a1, double b1) : a(a1), b(b1) // Конструктор с параметрами
    {
        if (a < 0 || b < 0)
        {
            cout << "сторона < 0" << endl;
            exit(0);
        }
    }
    double area(void) { return a * b; } // Вычисление площади
    void show(void)                     // Вывод информации
    {
        if (a == b) // Проверка на квадрат или прямоугольник
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
    Figure **figure = new Figure *[1]; // Создание произвольного количества фигур
    figure[0] = new Circle(5);         // Круг
    figure[1] = new Rectangle(-1, 2);  // Прямоугольник
    for (int i = 0; i < 2; i++)        // Массив вывода информации
    {
        cout << "Адрес &figure[" << i << "] = " << &(figure[i]) << endl;
        figure[i]->show();
    }
}