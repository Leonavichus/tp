#include <iostream>
#include <cmath>
using namespace std;

double Length2(double x1, double y1, double x2, double y2) // расчет длины стороны в двумерном пространстве
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
double Length3(double x1, double y1, double z1, double x2, double y2, double z2) // расчет длины стороны в трехмерном пространстве
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
}

int main()
{
    double x1, x2, x3, y1, y2, y3, z1, z2, z3, a, b, c, P;
    while (1)
    {
        cout << "1 -> двумерное пространство\n2 -> трехмерное пространство" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            // Вводим переменные
            cout << "Введите x1 y1 -> ";
            cin >> x1 >> y1;
            cout << "Введите x2 y2 -> ";
            cin >> x2 >> y2;
            cout << "Введите x3 y3 -> ";
            cin >> x3 >> y3;
            // Подсчет длины стророн(перегрузка функций)
            a = Length2(x1, y1, x2, y2);
            b = Length2(x1, y1, x3, y3);
            c = Length2(x2, y2, x3, y3);

            cout << "1-я боковая сторона -> " << a << "\n";
            cout << "2-я боковая сторона -> " << b << "\n";
            cout << "3-я боковая сторона -> " << c << "\n";
            // Периметр треугольника
            P = a + b + c;
            cout << "Периметр треугольника(2) -> " << P << "\n";
            break;
        case 2:
            // Вводим переменные
            cout << "Введите x1 y1 z1 -> ";
            cin >> x1 >> y1 >> z1;
            cout << "Введите x2 y2 z2 -> ";
            cin >> x2 >> y2 >> z2;
            cout << "Введите x3 y3 z3 -> ";
            cin >> x3 >> y3 >> z3;
            // Подсчет длины стророн(перегрузка функций)
            a = Length3(x1, y1, x2, y2, z1, z2);
            b = Length3(x1, y1, x3, y3, z1, z3);
            c = Length3(x2, y2, x3, y3, z2, z3);

            cout << "1-я боковая сторона -> " << a << "\n";
            cout << "2-я боковая сторона -> " << b << "\n";
            cout << "3-я боковая сторона -> " << c << "\n";
            // Периметр треугольника
            P = a + b + c;
            cout << "Периметр треугольника(3) -> " << P << "\n";
            break;
        case 0:
            cout << "\nПока!\n";
            break;
        }
    }
}