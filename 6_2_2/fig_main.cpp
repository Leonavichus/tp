#include "includers.cpp"
#include "triangle.h"

void fig_main()
{
    Figure **figure = new Figure *[2];
    figure[0] = new Circle(5);
    figure[1] = new Rectangle(1, 2);
    figure[2] = new Triangle(5, 2, 6);
    for (int i = 0; i < 3; i++)
    {
        cout << "Адрес &figure[" << i << "] = " << &(figure[i]) << endl;
        figure[i]->show();
    }
}