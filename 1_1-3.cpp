#include <iostream>
#include <cstring>
using namespace std;

class Stock
{
private: //переменные
    string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; } //подсчет общей стоимости всех акций

public:
    Stock() //конструктор
    {
        company = "Unnamed";
        shares = 0;
        share_val = 0;
        total_val = 0;
    }
    Stock(string co, int num, double price) //конструктор с параметрами
    {
        company = co;
        shares = num;
        share_val = price;
        total_val = num * price;
    }
    void acquire(); //Функция acquire выполняет обработку первоначального вклада конкретной компании, запоминая информацию о наименовании компании, количестве акций в пакете, цене каждой акции данного пакета и вычисляя общую стоимость пакета акций с помощью функции set_tot()
    void buy();     //Функция buy() предназначена для приобретения дополнительных акций
    void sell();    //Функция sell() предназначена для продажи акций
    void update();  //Функция update() корректирует стоимость одной акции и пересчитывает общую стоимость акций
    void show();    //Функция show() отображает данные о пакете акций
    ~Stock();       //деконструктор
};

void Stock::acquire()
{
    cout << "\nВведите название компании: ";
    cin >> company;
    cout << "Введите количество акций: ";
    cin >> shares;
    if (shares <= 0)
    {
        cerr << "Количество пакетов не может быть отрицательным; для "
             << company << " установлено в 0.\n";
        shares = 0;
    }
    cout << "Введите цену за акцию: ";
    cin >> share_val;
    set_tot();
}
void Stock::buy()
{
    int num;
    cout << "Введите сколько акций хотите купить: ";
    cin >> num;
    if (num > 0)
    {
        shares += num;
        set_tot();
    }
    else
        cerr << "Количество приобретаемых пакетов не может быть отрицательным. "
             << "Транзакция прервана.\n";
}
void Stock::sell()
{
    int num;
    cout << "Введите сколько акций хотите продать: ";
    cin >> num;
    if (num > 0 && num <= shares)
    {
        shares -= num;
        set_tot();
    }
    else if (num < 0)
    {
        cerr << "Количество продаваемых пакетов не может быть отрицательным. "
             << "Транзакция прервана.\n";
    }
    else if (num > shares)
    {
        cerr << "Вы не можете продать больше того, чем владеете! "
             << "Транзакция прервана.\n";
    }
}
void Stock::update()
{
    float upd;
    cout << "Введите стоимость одной акци для обновления: ";
    cin >> upd;
    if (upd > 0)
    {
        share_val = upd;
        set_tot();
    }
    else
        cerr << "Транзакция прервана";
}
void Stock::show()
{
    cout << "Компания: " << company
         << "\nПакетов: " << shares << endl
         << "\nЦена пакета: $" << share_val
         << "\nОбщая стоимость: $" << total_val << endl;
}

Stock::~Stock()
{
    cout << "Удаление.... \n";
}

int main()
{
    int k = 5;
    Stock yoshi[k]; //вызов конструктора
    int c = 0, x = 1, q;
    while (c >= 0 && c <= 4)
    {
        cout << "Выберете номер компании: ";
        cin >> c;
        c -= 1;
        if (c < 0 || c > 4)
            break;
        cout << "вы хотите ввести данные?(0(нет)/1(да)): ";
        cin >> q;
        if (q == 1)
            yoshi[c].acquire();
        x = 1;
        while (x)
        {
            cout << "\nКомпания #" << c + 1 << "\n1. Покупка \n2. Продажа\n3. Изменение\n4. Вывод\n0. Выход\n\n";
            cin >> x;
            switch (x)
            {
            case 1:
                yoshi[c].buy();
                break;
            case 2:
                yoshi[c].sell();
                break;
            case 3:
                yoshi[c].update();
                break;
            case 4:
                yoshi[c].show();
                break;
            case 0:
                cout << "\nПока!\n";
                break;
            }
        };
    }
}