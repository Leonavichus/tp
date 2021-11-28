#include "includers.cpp"
#include "triangle.h"

void fig_main()
{
    Figure **figure = new Figure *[2]; // Создание произвольного количества фигур
    figure[0] = new Circle(5);         // Круг
    figure[1] = new Rectangle(1, 2);   // Прямоугольник
    figure[2] = new Triangle(5, 2, 6); // Треугольник
    for (int i = 0; i < 3; i++)        // Массив вывода информации
    {
        cout << "Адрес &figure[" << i << "] = " << &(figure[i]) << endl;
        figure[i]->show();
    }
}