#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Задание 1
    int a = 1000;
    int b = 1000;
    cout << "Стандартное a = " << a << endl; // вывод a до применения манипуляторов
    cout << "Стандартное b = " << b << endl; // вывод b до применения манипуляторов

    cout << "С манипулятором oct a = " << oct << a << endl;   //восьмеричной форме
    cout << "С манипулятором oct b = " << oct << b << endl;   //восьмеричной форме
    cout << "Без задания манипулятора oct b = " << b << endl; //восьмеричной форме без манипулятора

    cout << "С манипулятором hex a = " << hex << a << endl;   //шестнадцатеричной форме
    cout << "С манипулятором hex b = " << hex << b << endl;   //шестнадцатеричной форме
    cout << "Без задания манипулятора hex b = " << b << endl; //шестнадцатеричной форме без манипулятора

    cout << "С манипулятором dec a = " << dec << a << endl;   //десятеричной форме
    cout << "С манипулятором dec b = " << dec << b << endl;   //десятеричной форме
    cout << "Без задания манипулятора dec b = " << b << endl; //десятеричный без манипулятора
    // манипуляторы hex, oct, dec распространяются до явной отмены

    cout << "С манипулятором setfill('*') a = " << setfill('*') << a << endl; // устанавливает символ заполнения
    // не работает без setw, который устанавливает ширину поля
    cout << "Без задания манипулятора a = " << a << endl;
    // действует до явной отмены

    cout << "С манипулятором setw(16) a = " << setw(16) << a << endl; // устанавливает ширину поля вывода
    cout << "Без задания манипулятора a = " << a << endl;
    // отменяется после вывода endl,распространяются на ближайший операнд

    cout << "-------------------" << endl;

    // Задание 2
    double d = 121.1234291541;
    cout << "Стандартное d = " << d << endl;                                        // вывод d
    cout << "С манипулятором setprecision(4) d = " << setprecision(4) << d << "\n"; // устанавливает число значащих цифр
    cout << "Без задания манипулятора d = " << d << endl;                           // setprecision работает до его явной отмены

    cout.setf(ios::fixed);                                          // установка флага, позволяющего манипулировать числом цифр после запятой
    cout << "setprecision(5) d = " << setprecision(5) << d << endl; // устанавливаем число цифр после запятой
    // в setprecision происходит округление

    cout << "-------------------" << endl;

    // Задание 3
    cout << setprecision(3); // сброс к параметру по умолчанию (3 знака после запятой)
    float f = 121.1234291541;
    cout << "Стандартное f (" << f << ") = " << setw(12) << f << endl;              // вывод в обычной нотации
    cout << "Научное f (" << f << ") = " << setw(12) << scientific << f << endl;    // вывод в научной нотации
    cout.unsetf(ios::scientific);                                                   // сброс флага scientific
    cout.setf(ios::fixed);                                                          // установка флага фиксированной длины после заптой
    cout << "f (" << f << ") = " << right << setw(12) << setfill('-') << f << endl; // сдвигаем вправо и заполняем '-'
    cout << "f (" << f << ") = " << left << setw(12) << f << endl;                  // сдвигаем влево и заполняем '-'
}