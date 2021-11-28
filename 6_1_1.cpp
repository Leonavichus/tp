#include <iostream>
#include <cstring>
using namespace std;

/*
Пояснения:
1) Конструкторы вызываются в порядке очереди(родительский класс первый, родительский класс второй, дочерний класс)
2) При изменении пордяка вызова родительских классов в конструкторе дочернего класса ничего не изменится, так как это зависит от порядка наследования
3) При изменении наследования порядок вызова конструкторов изменится, так как первым будет вызываться другой класс
*/

class Base1
{
    int i;

public:
    Base1() // Конструктор без параметров
    {
        cout << "Конструктор Base1 без параметров" << endl;
        i = 0;
    }
    Base1(int it) : i(it) { cout << "Конструктор Base1 с параметрами" << endl; } // Конструктор с параметрами
    void put(int it) { i = it; };                                                // Изменение данных
    int get(void) { return i; };                                                 // Прочитать данные
};

class Base2
{
    char name[20];

public:
    Base2() // Конструктор без параметров
    {
        cout << "Конструктор Base2 без параметров" << endl;
        const char *defolt = "NULL";
        strncpy(name, defolt, 19);
        name[19] = '\0';
    }
    Base2(char *n) // Конструктор с параметрами
    {
        cout << "Конструктор Base2 с параметрами" << endl;
        strncpy(name, n, 19);
        name[19] = '\0';
    }
    void put(char *n) // Изменение данных
    {
        strncpy(name, n, 19);
        name[19] = '\0';
    };
    char *get(void) { return name; }; // Прочитать данные
};

class Derived : public Base1, public Base2
{
    char ch;

public:
    Derived() // Конструктор без параметров
    {
        cout << "Конструктор Derived без параметров" << endl;
        ch = 'V';
    }
    Derived(int it, char *n, char c) : Base1(it), Base2(n), ch(c) { cout << "Конструктор Derived с параметрами" << endl; } // Конструктор с параметрами
    void put(char c) { ch = c; };                                                                                          // Изменение данных
    char get(void) { return ch; };                                                                                         // Прочитать данные
    friend ostream &operator<<(ostream &os, Derived &tip);                                                                 // Перегрузка оператора "<<"
};

ostream &operator<<(ostream &os, Derived &tip)
{
    // Поскольку operator << является другом класса Derived, то мы имеем прямой доступ к членам Derived
    os << "i = " << tip.Base1::get() << endl
       << "n = " << tip.Base2::get() << endl
       << "c = " << tip.ch << endl;
    return os;
}

int main()
{
    Derived dir; // Инициализация объекта без параметров
    cout << dir;
    Derived dir1(1, "hai", 'N'); // Инициализация объекта с параметрами
    cout << dir1;
}