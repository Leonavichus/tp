#include <iostream>
#include <cstring>
using namespace std;

/*
Пояснения:
1) Присутствует множественное наследование, для решения этой проблемы нужно виртуально наследовать классы
2) Я не знаю что объяснять в результатах, просто выводятся значения заданные нами в инициализации
*/

class DomesticAnimal
{
protected:
    double weight;
    double price;
    string color;

public:
    DomesticAnimal() {}                                                             // Конструктор без параметров
    DomesticAnimal(double w, double p, string c) : weight(w), price(p), color(c) {} // Конструктор с параметрами
    void print()                                                                    // Вывод значения полей класса
    {
        cout << "DomesticAnimal:" << endl;
        cout << "weight: " << weight << endl
             << "price: " << price << endl
             << "color: " << color << endl;
    }
};

class Cow : virtual public DomesticAnimal // Виртуальное наследование
{
public:
    Cow() {}                                                       // Конструктор без параметров
    Cow(double w, double p, string c) : DomesticAnimal(w, p, c) {} // Конструктор с параметрами
    void print()                                                   // Вывод значения полей класса
    {
        cout << "Cow->";
        DomesticAnimal::print(); // Наследование метода от родительского класса
    }
};

class Buffalo : virtual public DomesticAnimal // Виртуальное наследование
{
public:
    Buffalo() {}                                                       // Конструктор без параметров
    Buffalo(double w, double p, string c) : DomesticAnimal(w, p, c) {} // Конструктор с параметрами
    void print()                                                       // Вывод значения полей класса
    {
        cout << "Buffalo->";
        DomesticAnimal::print(); // Наследование метода от родительского класса
    }
};

class Beefalo : public Cow, public Buffalo
{
public:
    Beefalo() {}                                                       // Конструктор без параметров
    Beefalo(double w, double p, string c) : DomesticAnimal(w, p, c) {} // Конструктор с параметрами
    void print()                                                       // Вывод значения полей класса
    {
        cout << "Beefalo->";
        DomesticAnimal::print(); // Наследование метода от родительского класса
    }
};

int main()
{
    DomesticAnimal dir(1, 100, "red"); // Инициализация объекта класса DomesticAnimal с параметрами
    Cow co(10, 200, "withe");          // Инициализация объекта класса Cow с параметрами
    Buffalo buf(20, 250, "black");     // Инициализация объекта класса Buffalo с параметрами
    Beefalo bef(12, 450, "pink");      // Инициализация объекта класса Beefalo с параметрами
    dir.print();
    co.print();
    buf.print();
    bef.print();
}