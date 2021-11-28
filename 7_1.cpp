#include <iostream>
#include <cstring>
using namespace std;

/*
template <class T, class T> T f(T x); - два класса с одинаковыми именами
template <class T1, T2> void f(T1 x); - у второго не присутствует класс
template <class T> T f(int x); - зачем задан тип данных? надо f(T x)
inline template <class T> T f(T x, T y) - зачем inline?
*/

template <typename T> // Шаблон функции swap для перестановки местами
void my_swap(T &a, T &b)
{
    T temp(a);
    a = b;
    b = temp;
}

template <typename T> // Шаблон функции max для поиска максимума
T max(T &x, T &y)
{
    return x > y ? x : y;
}

typedef const char *CHAR; // Шаблон функции max для поиска максимума для строк
template <CHAR>
CHAR max(CHAR &s1, CHAR &s2)
{
    return (strcmp(s1, s2) > 0 ? s1 : s2);
}

int main()
{
    int a, b;
    cout << "Введите значения(int)" << endl;
    cin >> a >> b;
    cout << a << " " << b << endl;
    cout << "-----" << endl;
    swap<int>(a, b); // Запуск шаблона с типом int
    cout << a << " " << b << endl;

    char e, f;
    cout << "Введите значения(char)" << endl;
    cin >> e >> f;
    cout << e << " " << f << endl;
    cout << "-----" << endl;
    swap<char>(e, f); // Запуск шаблона с типом char
    cout << e << " " << f << endl;

    string g, k;
    cout << "Введите значения(string)" << endl;
    cin >> g >> k;
    cout << g << " " << k << endl;
    cout << "-----" << endl;
    swap<string>(g, k); // Запуск шаблона с типом string
    cout << g << " " << k << endl;

    int i = max(0, 1); // Поиск максимума с типом int
    cout << i << endl;
    char ch = max('a', '1'); // Поиск максимума с типом char
    cout << ch << endl;
    const char *ch1 = max("Hello", "World"); // Поиск максимума для строк
    cout << ch1 << endl;
}