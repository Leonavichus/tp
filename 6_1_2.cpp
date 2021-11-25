#include <iostream>
#include <cstring>
using namespace std;

class DomesticAnimal
{
protected:
    double weight;
    double price;
    string color;

public:
    DomesticAnimal() {}
    DomesticAnimal(double w, double p, string c) : weight(w), price(p), color(c) {}
    void print()
    {
        cout << "DomesticAnimal:" << endl;
        cout << "weight: " << weight << endl
             << "price: " << price << endl
             << "color: " << color << endl;
    }
};

class Cow : virtual public DomesticAnimal
{
public:
    Cow() {}
    Cow(double w, double p, string c) : DomesticAnimal(w, p, c) {}
    void print()
    {
        cout << "Cow->";
        DomesticAnimal::print();
    }
};

class Buffalo : virtual public DomesticAnimal
{
public:
    Buffalo() {}
    Buffalo(double w, double p, string c) : DomesticAnimal(w, p, c) {}
    void print()
    {
        cout << "Buffalo->";
        DomesticAnimal::print();
    }
};

class Beefalo : public Cow, public Buffalo
{
public:
    Beefalo() {}
    Beefalo(double w, double p, string c) : DomesticAnimal(w, p, c) {}
    void print()
    {
        cout << "Beefalo->";
        DomesticAnimal::print();
    }
};

int main()
{
    DomesticAnimal dir(1, 100, "red");
    Cow co(10, 200, "withe");
    Buffalo buf(20, 250, "black");
    Beefalo bef(12, 450, "pink");
    dir.print();
    co.print();
    buf.print();
    bef.print();
}