#include <iostream>
#include <string>
using namespace std;

class Goods
{ // Переменные
    int id;
    string name;
    string date;
    int price;
    int kol;

public:
    Goods() // Конструктор
    {
        cout << "Вызван конструктор" << endl;
        id = 0;
        name = "Unknown";
        date = "00.00.0000";
        price = 0;
        kol = 0;
    }
    Goods(const Goods &obj);            // Конструктор копирования
    void Show();                        // Вывод данных
    void Chage();                       // Изменение данных
    double Total_Price();               // Функция вычисления стоимости товара
    Goods &operator=(const Goods &obj2) // Перегрузка операции присваивания
    {
        if (this == &obj2) // Проверка на самоприсваивание
        {
            return *this;
        }

        id = obj2.id;
        name = obj2.name;
        date = obj2.date;
        price = obj2.price;
        kol = obj2.kol;

        return *this;
    }
    ~Goods() // Деконструктор
    {
        cout << "Вызван деструктор" << endl;
    }
};

Goods::Goods(const Goods &obj)
{
    id = obj.id;
    name = obj.name;
    date = obj.date;
    price = obj.price;
    kol = obj.kol;
}

void Goods::Show()
{
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Date: " << date << endl;
    cout << "Price: " << price << endl;
    cout << "Kol: " << kol << endl;
}

void Goods::Chage()
{
    cout << "Введите id: ";
    cin >> id;
    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите дату: ";
    cin >> date;
    cout << "Введите цену: ";
    cin >> price;
    cout << "Введите количество: ";
    cin >> kol;
}

double Goods::Total_Price()
{
    return kol * price;
}

Goods tovar(Goods s) { return s; }            // Передача и возврат без ссылок
Goods tovar_G_link(Goods &s) { return s; }    // Передача по ссылке и возврат без ссылки
Goods *tovar_R_link(Goods s) { return &s; }   // Передача без ссылки и возврат по ссылке
Goods *tovar_GR_link(Goods &s) { return &s; } // Передача и возврат по ссылкам

int main()
{
    cout << "Вход в функцию main()" << endl;

    Goods tov; // Вызов конструктора
    cout << "\nВывод tov: \n";
    tov.Show();

    cout << "\nИзменение tov: \n";
    tov.Chage();

    cout << "\nВывод измененного tov: \n";
    tov.Show();

    cout << "\nКопирование tov=>tov3\n";
    Goods tov3(tov);
    cout << "\nВывод tov3: \n";
    tov3.Show();

    cout << "\nПередача и возврат без ссылок (tov2=tov): \n";
    cout << "Инициализация tov2: \n";
    Goods tov2;
    tov2 = tovar(tov);
    cout << "\nВывод tov2: \n";
    tov2.Show();

    cout << "\nПередача по ссылке и возврат без ссылки (tov2=tov3): \n";
    tov2 = tovar_G_link(tov3);
    cout << "\nВывод tov2: \n";
    tov2.Show();

    cout << "\nПередача без ссылки и возврат по ссылке (tov): \n";
    tovar_R_link(tov);

    cout << "\nПередача и возврат по ссылкам (tov): \n";
    tovar_GR_link(tov);

    cout << "\ntov3=tov\n";
    tov3 = tov;
    cout << "\nВывод tov3: \n";
    tov3.Show();

    cout << "Выход из функции main()" << endl;
}