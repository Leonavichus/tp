#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>

using namespace std;

class Test
{
    friend void fun(Test *); // Дружественная функция
    int W;
    void Z() { cout << "Это закрытая функция класса Test"; }

public:
    Test() { W = 1; } // Конструктор
};

void fun(Test *z)
{
    cout << z->W;
    cout << "\n";
    z->Z();
}

int main()
{
    Test x;  // Вызов конструктора
    fun(&x); // Вызов функции с ссылкой на иницилиализирующий объект конструктора
}