#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    char s[20], s1;
    do
    {
        cin.clear(); // чистим буфер
        cout << "Введите строку >> " << endl;
        cin.ignore(20, '*');         // игнорируем ввод до достижения указанного символа
        s1 = cin.peek();             // извлекает 1 символ из потока
        cin.putback('X');            // вставляем в начало потока указанный символ X
        cin.getline(s, 11);          // вводим строку максимальной длины
    } while (cin.gcount() - 1 > 10); // считаем число символов в потоке, если привысили то начинаем заново
    cout << "s=" << s << endl;       // выводим полученную строку
    cout << "s1= " << s1 << endl;    // выводим считанный символ
}