#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *stack;
    int size;
    T top;

public:
    Stack(int = 1);
    ~Stack();
    bool push(const T);
    void show();
};

template <typename T>
Stack<T>::Stack(int s)
{
    size = s > 0 ? s : 1;
    stack = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stack;
}

template <typename T>
bool Stack<T>::push(const T value)
{
    if (top == size - 1)
        return false;
    top++;
    stack[top] = value;
    return true;
}

template <typename T>
void Stack<T>::show()
{
    for (int i = size - 1; i >= 0; i--)
        cout << stack[i] << endl;
}

int main()
{
    int i, c = 0;
    cout << "Введите размер стэка: ";
    cin >> i;
    Stack<int> myStack(i);
    cout << "Записываем элементы в стэк: ";
    while (c++ != i)
    {
        int temp;
        cin >> temp;
        myStack.push(temp);
    }
    myStack.show();
}