#include "includers.cpp"
#include "figure.h"

Circle::Circle(double R) // Конструктор с параметрами
{
    if (R <= 0)
    {
        cout << "radius < 0" << endl;
        exit(0);
    }
    else
    {
        radius = R;
    }
}
double Circle::area() // Вычисление площади
{
    return 3.14 * radius * radius;
}
void Circle::show() // Вывод информации
{
    cout << "Фигура: Круг" << endl
         << "R: " << radius << endl
         << "Площадь: " << area() << endl;
}

Rectangle::Rectangle(double a1, double b1) // Конструктор с параметрами
{
    if (a < 0 || b < 0)
    {
        cout << "сторона < 0" << endl;
        exit(0);
    }
    else
    {
        a = a1;
        b = b1;
    }
}

double Rectangle::area() // Вычисление площади
{
    return a * b;
}

void Rectangle::show() // Вывод информации
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