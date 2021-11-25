#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>

using namespace std;

class Product
{ //переменные
    string name;
    string manufacturer;
    int price;
    int shelf_life;
    int kol;

public:
    Product() {}                     // Конструктор
    void Set();                      // Ввод данных
    void Show();                     // Вывод данных
    void NameList(string n);         // Список товаров для заданного наименования
    void PriceList(int p, string n); // Список товаров для заданного наименования, цена которых не превышает указанной
    void Shelf_lifeList(int s);      // Список товаров, срок хранения которых больше заданного
};

void Product::Set()
{
    cout << "Введите наименование: ";
    cin >> name;
    cout << "Введите производителя: ";
    cin >> manufacturer;
    cout << "Введите цену: ";
    cin >> price;
    cout << "Введите срок хранения: ";
    cin >> shelf_life;
    cout << "Введите количество: ";
    cin >> kol;
}

void Product::Show()

{
    cout << "Наименование :" << name << endl;
    cout << "Производитель:" << manufacturer << endl;
    cout << "Цена :" << price << endl;
    cout << "Срок хранения:" << shelf_life << endl;
    cout << "Количество:" << kol << endl;
}

void Product::NameList(string n)

{
    if (name == n)
        cout << name << endl;
}

void Product::PriceList(int p, string n)
{
    if (price < p && name == n)
        cout << name << endl;
}

void Product::Shelf_lifeList(int s)
{
    if (shelf_life > s)
        cout << name << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите кол-во товаров: ";
    cin >> n;
    Product *product = new Product[n];
    for (int i = 0; i < n; i++)
        product[i].Set();
    cout << "Список товаров: " << endl;
    for (int i = 0; i < n; i++)
        product[i].Show();
    string name;
    cout << "Введите наименование для поиска: ";
    cin >> name;
    for (int i = 0; i < n; i++)
        product[i].NameList(name);
    int price;
    cout << "Введите наименование для поиска: ";
    cin >> name;
    cout << "Введите цену  для поиска: ";
    cin >> price;
    for (int i = 0; i < n; i++)
        product[i].PriceList(price, name);
    int shelf_life;
    cout << "Введите срок хранения для поиска: ";
    cin >> shelf_life;
    for (int i = 0; i < n; i++)
        product[i].Shelf_lifeList(shelf_life);
    delete[] product; // Деконструктор
}