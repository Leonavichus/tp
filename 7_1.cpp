#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
    T temp(a);
    a = b;
    b = temp;
}

typedef const char *CHAR;
template <CHAR>
CHAR max(CHAR &s1, CHAR &s2)
{
    return (strcmp(s1, s2) > 0 ? s1 : s2);
}

int main()
{
    /*int a, b;
    cout << "Введите значеня(int)" << endl;
    cin >> a >> b;
    cout << a << " " << b << endl;
    cout << "-----" << endl;
    swap<int>(a, b);
    cout << a << " " << b << endl;

    char e, f;
    cout << "Введите значеня(char)" << endl;
    cin >> e >> f;
    cout << e << " " << f << endl;
    cout << "-----" << endl;
    swap<char>(e, f);
    cout << e << " " << f << endl;

    string g, k;
    cout << "Введите значеня(string)" << endl;
    cin >> g >> k;
    cout << g << " " << k << endl;
    cout << "-----" << endl;
    swap<string>(g, k);
    cout << g << " " << k << endl;*/

    int i = max(0, 1);
    cout << i << endl;
    char ch = max('a', '1');
    cout << ch << endl;
    const char *ch1 = max("Hello", "World");
    cout << ch1 << endl;
}