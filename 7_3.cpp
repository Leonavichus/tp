#include <iostream>
using namespace std;

template <typename T> // Шаблон класса
class Stack
{
private:
    T *stack; // Указатель на стэк
    int size; // Размер стэка
    T top;    // Вершина стэка

public:
    Stack(int = 1);     // Размер стэка по умолчанию
    ~Stack();           // Деконструктор
    bool push(const T); // Добавление элемента в стэк
    void show();        // Вывод информации
};

template <typename T> // Конструктор
Stack<T>::Stack(int s)
{
    size = s > 0 ? s : 1; // Инизиализация размера стэка
    stack = new T[size];  // Выделение памяти для стэка
    top = -1;             // Стэк пуст
}

template <typename T> // Деконструктор
Stack<T>::~Stack()
{
    delete[] stack;
}

template <typename T> // Добавление элемента в стэк
bool Stack<T>::push(const T value)
{
    if (top == size - 1) // Проверка на заполнение
        return false;
    top++;
    stack[top] = value; // Помещение элемента в стэк
    return true;
}

template <typename T> // Вывод информации
void Stack<T>::show()
{
    for (int i = size - 1; i >= 0; i--)
        cout << stack[i] << endl;
}

int main()
{
    int n, c = 0;
    cout << "Введите размер стэка: ";
    cin >> n;
    Stack<int> myStack(n);
    cout << "Записываем элементы в стэк: ";
    while (c++ != n) // Заполнение стэка
    {
        int temp;
        cin >> temp;
        myStack.push(temp);
    }
    myStack.show();
}