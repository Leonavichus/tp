#include <iostream>
using namespace std;

class Date
{
    // Переменнные
    int day, month, year;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Date() {}
    Date(int d, int m, int y) // Конструктор с параметрами
    {
        day = d;
        month = m;
        year = y;
    }
    Date operator=(Date ob);                                 // Перегрузка оператора "date=date"
    Date operator+(Date ob);                                 // Перегрузка оператора "date+date"
    Date operator-(Date ob);                                 // Перегрузка оператора "date-date"
    Date operator+(int idays);                               // Перегрузка оператора "date+int"
    Date operator-(int idays);                               // Перегрузка оператора "date-int"
    Date operator++();                                       // Перегрузка оператора "date++"
    Date operator--();                                       // Перегрузка оператора "date--"
    friend ostream &operator<<(ostream &os, const Date &dt); // Перегрузка оператора "<<"
    friend Date &operator+(int idays, Date idate);           // Перегрузка оператора "int+date"
    ~Date(){};                                               // Деконструктор
};

ostream &operator<<(ostream &os, const Date &dt)
{
    // Поскольку operator << является другом класса Date, то мы имеем прямой доступ к членам Date
    os << dt.day << '.' << dt.month << '.' << dt.year;
    return os;
}

Date Date::operator=(Date ob)
{
    day = ob.day;
    month = ob.month;
    year = ob.year;
    return *this;
}

Date Date::operator+(Date ob)
{
    Date temp;
    temp.day = ob.day + day;
    temp.month = ob.month + month;
    temp.year = ob.year + year;
    while (temp.day > temp.days[temp.month] || temp.month > 12) // Вычисление даты с помощью массива, если дата превосходит заданное число указанное в нем
    {
        if (temp.day > temp.days[temp.month])
        {
            temp.day = temp.day - temp.days[temp.month];
            temp.month += 1;
        }
        if (temp.month > 12)
        {
            temp.month -= 12;
            temp.year += 1;
        }
    }
    return temp;
}

Date Date::operator-(Date ob)
{
    Date temp;
    temp.day = ob.day - day;
    temp.month = ob.month - month;
    temp.year = ob.year - year;
    while (temp.day < 1 || temp.month < 1) // Вычисление даты с помощью массива, если дата превосходит заданное число указанное в нем
    {
        if (temp.day < 1)
        {
            temp.day = temp.day + temp.days[temp.month];
            temp.month -= 1;
        }
        if (temp.month < 1)
        {
            temp.month += 12;
            temp.year -= 1;
        }
    }
    return temp;
}

Date Date::operator+(int idays)
{
    Date temp;
    temp.day = day + idays;
    temp.month = month;
    temp.year = year;
    while (temp.day > temp.days[temp.month] || temp.month > 12) // Вычисление даты с помощью массива, если дата превосходит заданное число указанное в нем
    {
        if (temp.day > temp.days[temp.month])
        {
            temp.day = temp.day - temp.days[temp.month];
            temp.month += 1;
        }
        if (temp.month > 12)
        {
            temp.month -= 12;
            temp.year += 1;
        }
    }
    return temp;
}

Date &operator+(int idays, Date idate)
{
    Date temp;
    temp = idate;
    temp.day = idate.day + idays;
    while (temp.day > temp.days[temp.month] || temp.month > 12) // Вычисление даты с помощью массива, если дата превосходит заданное число указанное в нем
    {
        if (temp.day > temp.days[temp.month])
        {
            temp.day = temp.day - temp.days[temp.month];
            temp.month += 1;
        }
        if (temp.month > 12)
        {
            temp.month -= 12;
            temp.year += 1;
        }
    }
    return temp;
}

Date Date::operator-(int idays)
{
    Date temp;
    temp = *this;
    temp.day -= idays;
    while (temp.day < 1 || temp.month < 1) // Вычисление даты с помощью массива, если дата превосходит заданное число указанное в нем
    {
        if (temp.day < 1)
        {
            temp.day = temp.day + temp.days[temp.month];
            temp.month -= 1;
        }
        if (temp.month < 1)
        {
            temp.month += 12;
            temp.year -= 1;
        }
    }
    return temp;
}

Date Date::operator++()
{
    day++;
    return *this;
}

Date Date::operator--()
{
    day--;
    return *this;
}

int main()
{
    int d1, d2, d3, m1, m2, m3, y1, y2, y3, dj; // Задаем переменные для ввода дат или количества дней
    cout << "1 Определить срок сдачи объекта (date + date)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Дата начала строительства) -> ";
    cin >> d1 >> m1 >> y1;
    cout << "Введите d3 m3 y3 (Период строительства) -> ";
    cin >> d3 >> m3 >> y3;
    Date dt1(d1, m1, y1), dt2(d2, m2, y2), dt3(d3, m3, y3); // Инициализируем конструктор
    cout << "Дата сдачи объекта (date + date): ";
    dt2 = dt1 + dt3; // Используя перегруженные операторы вывода потока данных и (date + date) выводим дату сдачи объекта
    cout << dt2 << "\n";

    cout << "2 Определить срок начала строительства (date - date)"
         << endl;
    // Вводим данные
    cout << "Введите d2 m2 y2 (Дата сдачи объекта) -> ";
    cin >> d2 >> m2 >> y2;
    cout << "Введите d3 m3 y3 (Период строительства) -> ";
    cin >> d3 >> m3 >> y3;
    Date dt1_0(d1, m1, y1), dt2_0(d2, m2, y2), dt3_0(d3, m3, y3); // Инициализируем конструктор
    cout << "Дата начала строительства (date - date): ";
    dt1_0 = dt3_0 - dt2_0; // Используя перегруженные операторы вывода потока данных и (date - date) выводим дату начала стоительства
    cout << dt1_0 << "\n";

    cout << "3 Определелить дату поставки строительных материалов (date + int)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Дата начала строительства) -> ";
    cin >> d1 >> m1 >> y1;
    cout << "Введите cколько дней надо ждать -> ";
    cin >> dj;
    Date dt1_1(d1, m1, y1), dt3_1(d3, m3, y3); // Инициализируем конструктор
    cout << "Дата поставки (date + int): ";
    dt3_1 = dt1_1 + dj; // Используя перегруженные операторы вывода потока данных и (date + int) выводим дату поставки
    cout << dt3_1 << "\n";

    cout << "4 Определелить дату поставки строительных материалов (int + date)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Дата начала строительства) -> ";
    cin >> d1 >> m1 >> y1;
    cout << "Введите cколько дней надо ждать -> ";
    cin >> dj;
    Date dt1_2(d1, m1, y1), dt3_2(d3, m3, y3); // Инициализируем конструктор
    cout << "Дата поставки (int + date): ";
    dt3_2 = dj + dt1_2; // Используя перегруженные операторы вывода потока данных и (int + date) выводим дату поставки
    cout << dt3_2 << "\n";

    cout << "5 Определение исходной даты оформления заработной платы рабочим (date - int)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Исходная дата) -> ";
    cin >> d1 >> m1 >> y1;
    cout << "Введите cколько дней отработано -> ";
    cin >> dj;
    Date dt1_3(d1, m1, y1), dt3_3(d3, m3, y3); // Инициализируем конструктор
    cout << "Дата зарплаты (date - int): ";
    dt3_3 = dt1_3 - dj; // Используя перегруженные операторы вывода потока данных и (date - int) выводим дату зарплаты
    cout << dt3_3 << "\n";

    cout << "6 Переход к следующей дате (date++)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Дата) -> ";
    cin >> d1 >> m1 >> y1;
    Date dt1_4(d1, m1, y1); // Инициализируем конструктор
    cout << "Следующа дата (date++): ";
    ++dt1_4; // Используя перегруженные операторы вывода потока данных и (date++) выводим следующую дату
    cout << dt1_4 << "\n";

    cout << "7 Переход к прошлой дате (date--)"
         << endl;
    // Вводим данные
    cout << "Введите d1 m1 y1 (Дата) -> ";
    cin >> d1 >> m1 >> y1;
    Date dt1_5(d1, m1, y1); // Инициализируем конструктор
    cout << "Прошлая дата (date--): ";
    --dt1_5; // Используя перегруженные операторы вывода потока данных и (date--) выводим предыдущую дату
    cout << dt1_5 << "\n";
}