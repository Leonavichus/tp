#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
#define pages 2 // количество страниц для манипулятор endp без параметров

// манипулятор endp без параметров
ostream &endp(ostream &os)
{
    static int num = 0; // счетчик вызовов
    os << endl;
    num++;
    // если достигли перехода на новую страницу
    if (num == pages)
    {
        os << "--------------" << endl; // печатаем разделитель
        num = 0;                        // обнуляем счетчик
    }
    return os; // возвращаем поток
}
// манипулятор endp с параметром количества записей на странице
ostream &endp(ostream &os, int n)
{
    static int num1 = 0; // счетчик вызовов
    os << endl;
    num1++;
    // если достигли перехода на новую страницу
    if (num1 == n)
    {
        os << "--------------" << endl; // печатаем разделитель
        num1 = 0;                       // обнуляем счетчик
    }
    return os; // возвращаем поток
}
// манипулятор endp с параметром количества записей на странице и строкой разделителем
ostream &fendp(ostream &os, int n, char *s)
{
    static int num2 = 0; // счетчик вызовов
    os << endl;
    num2++;
    // если достигли перехода на новую страницу
    if (num2 == n)
    {
        os << s << endl; // печатаем разделитель
        num2 = 0;        // обнуляем счетчик
    }
    return os; // возвращаем поток
}
int main()
{
    cout << "Базовый манипулятор" << endl; // манипулятор без параметров
    for (int i = 0; i < 6; i++)            // выводим последовательность от 1 до 6
        cout << i + 1 << endp;

    cout << "Манипулятор количества страниц" << endl; // манипулятор с параметром количества
    for (int i = 0; i < 6; i++)                       // выводим последовательность от 0 до 5
    {
        endp(cout << i, 3); // указываем количество страниц
    }

    cout << "Манипулятор количества страниц и разделителей" << endl; // манипулятор с параметром количества и разделителя
    for (int i = 0; i < 6; i++)                                      // выводим последовательность от 0 до 5
    {
        fendp(cout << i, 3, "**********"); // указываем количество страниц и разделитель
    }
}