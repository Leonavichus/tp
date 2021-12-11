#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a = 1000;
    cout.setf(ios::showbase); // включаем флаг вывода основания системы счисления

    cout.setf(ios::oct); // флаг вывода в восьмеричной системе счисления
    cout << "oct << " << a << endl;
    cout.unsetf(ios::oct); // выключаем флаг

    cout.setf(ios::dec); // включаем флаг вывода в десятеричной системе счисления
    cout << "dec << " << a << endl;
    cout.unsetf(ios::dec); // выключаем флаг

    cout.setf(ios::hex); // включаем флаг вывода в шестнадцатеричной системе счисления
    cout << "hex << " << a << endl;
    cout.setf(ios::uppercase); // включаем  флаг uppercase - заглавные буквы
    cout << "hex << " << a << endl;
    cout.unsetf(ios::hex); // выключаем флаг

    cout.setf(ios::dec);     //включаем флаг вывода в десятеричной системе счисления
    cout.setf(ios::showpos); // выводит + перед положительным числом
    cout << "dec << " << a << endl;
    cout.unsetf(ios::showpos); // выключаем флаг

    bool b = 1;
    bool c = 0;
    cout << "Bool << " << b << endl;
    cout.setf(ios::boolalpha); // включаем флаг вывода значения true, false вместо 1, 0
    cout << "Bool 1 << " << b << endl;
    cout << "Bool 0 << " << c << endl;

    float f = 1123.21321;
    cout << "Стандартный f << " << f << endl;
    cout.setf(ios::scientific); // включаем флаг научной нотации
    cout << "Научный f << " << f << endl;
    cout.unsetf(ios::scientific); // выключаем флаг научной нотации

    cout.setf(ios::fixed); //включаем флаг фиксированного числа цифр после запятой
    cout << "Фиксированное число восле запятой f << " << f << endl;

    cout.fill('*');        // заполнитель для демонстрации выравнивания
    cout.setf(ios::right); // выравниваем по правой стороне
    cout.width(10);        // устанавливаем ширину для демонстрации
    cout << "hi" << endl;
    cout.unsetf(ios::right); // убираем флаг выравнивания вправо

    cout.setf(ios::left); // выравниваем по левой стороне
    cout.width(10);       // устанавливаем ширину для демонстрации
    cout << "buy" << endl;
}