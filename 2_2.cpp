#include <iostream>
#include <string>
using namespace std;

class Abonent
{ //
    int number;
    string surname;
    string tel;

public:
    Abonent() // Конструктор
    {
        number = 0;
        surname = "Unknown";
        tel = "0000000000";
    }
    Abonent(int valueNumber, string valueSurname, string valueTel) // Конструктор с параментрами
    {
        cout << "Вызван конструктор" << endl;
        number = valueNumber;
        surname = valueSurname;
        tel = valueTel;
    }
    void start(int i) { number = i; }
    ~Abonent() //
    {
        cout << "Вызван деструктор" << endl;
    }
    friend class Notebook; // Дружественный класс
};

class Notebook
{
public:
    void Change(Abonent &ab, string valueSurname, string valueTel) // Изменение данных в классе Abonent
    {
        ab.surname = valueSurname;
        ab.tel = valueTel;
    }
    void show(Abonent &ab); // Вывод данных из класса Abonent
};

void Notebook::show(Abonent &ab)
{
    cout << "Number: " << ab.number << endl;
    cout << "Surname: " << ab.surname << endl;
    cout << "Tel :" << ab.tel << endl;
}

int main()
{
    int x = 1, num, kol;
    cout << "Введите количество абонентов\n";
    cin >> kol;
    Notebook nbook;
    Abonent *ab;
    ab = new Abonent[kol];
    for (int i = 0; i < kol; i++)
        ab[i].start(i + 1);
    while (x)
    {
        cout << "\nChoose one:\n1. Show \n2. Change\n";
        cin >> x;
        switch (x)
        {
        case 0:
            cout << "\nПока!\n";
            break;
        case 1:
            cout << "\n";
            for (int i = 0; i < kol; i++)
                nbook.show(ab[i]);
            cout << "\n";
            break;
        case 2:
            cout << "Введите номер: ";
            cin >> num;
            string sur;
            string tele;
            cout << "Введите новую фамилию: ";
            cin >> sur;
            cout << "Введите новый телефон: ";
            cin >> tele;
            nbook.Change(ab[num - 1], sur, tele);
            break;
        }
    };
}