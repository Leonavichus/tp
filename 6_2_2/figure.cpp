#include "includers.cpp"
#include "figure.h"

Circle::Circle(double R)
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
double Circle::area()
{
    return 3.14 * radius * radius;
}
void Circle::show()
{
    cout << "Фигура: Круг" << endl
         << "R: " << radius << endl
         << "Площадь: " << area() << endl;
}

double Rectangle::area()
{
    return a * b;
}

void Rectangle::show()
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