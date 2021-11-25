#include <iostream>
#include <cstring>
using namespace std;

class Base1
{
    int i;

public:
    Base1()
    {
        cout << "Конструктор Base1 без параметров" << endl;
        i = 0;
    }
    Base1(int it) : i(it) { cout << "Конструктор Base1 с параметрами" << endl; }
    void put(int it) { i = it; };
    int get(void) { return i; };
};

class Base2
{
    char name[20];

public:
    Base2()
    {
        cout << "Конструктор Base2 без параметров" << endl;
        const char *defolt = "NULL";
        strncpy(name, defolt, 19);
        name[19] = '\0';
    }
    Base2(char *n)
    {
        cout << "Конструктор Base2 с параметрами" << endl;
        strncpy(name, n, 19);
        name[19] = '\0';
    }
    void put(char *n)
    {
        strncpy(name, n, 19);
        name[19] = '\0';
    };
    char *get(void) { return name; };
};

class Derived : public Base1, public Base2
{
    char ch;

public:
    Derived()
    {
        cout << "Конструктор Derived без параметров" << endl;
        ch = 'V';
    }
    Derived(int it, char *n, char c) : Base1(it), Base2(n), ch(c) { cout << "Конструктор Derived с параметрами" << endl; }
    void put(char c) { ch = c; };
    char get(void) { return ch; };
    friend ostream &operator<<(ostream &os, Derived &tip);
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
    Derived dir;
    cout << dir;
    Derived dir1(1, "hai", 'N');
    cout << dir1;
}