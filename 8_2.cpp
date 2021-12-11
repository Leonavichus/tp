#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Введите числа a, b, c >> ";
    cin >> a >> b >> c;

    cout.fill('0'); // заполнитель
    cout.width(1);  // ширина заполнения
    cout << a << endl;
    cout.width(2);
    cout << b << endl;
    cout.width(3);
    cout << c << endl;

    float d;
    cout << "Введите число d >> ";
    cin >> d;
    cout.setf(ios::fixed); // устанавливаем флаг фиксированного числа цифр после запятой
    cout.precision(1);     // устанавливаем число цифр после запятой 1
    cout << "f.(1) = " << d << endl;
    cout.precision(2); // устанавливаем число цифр после запятой 2
    cout << "f.(2) = " << d << endl;
}