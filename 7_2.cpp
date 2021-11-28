#include <iostream>
#include <string.h>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int c = 0, int d = 0) : a(c), b(d) {}
    Complex &operator+(Complex &ob);
    Complex &operator-(Complex &ob);
    Complex &operator=(Complex &ob);
    friend ostream &operator<<(ostream &out_stream, const Complex &dt);
    friend istream &operator>>(istream &in_stream, Complex &dt);
};

Complex &Complex::operator+(Complex &ob)
{
    a = a + ob.a;
    b = b + ob.b;
    return (*this);
}

Complex &Complex::operator-(Complex &ob)
{
    a = a - ob.a;
    b = b - ob.b;
    return (*this);
}

Complex &Complex::operator=(Complex &ob)
{
    a = ob.a;
    b = ob.b;
    return (*this);
}

ostream &operator<<(ostream &out_stream, const Complex &dt)
{
    out_stream << dt.a << "/" << dt.b << endl;
    return out_stream;
}

istream &operator>>(istream &in_stream, Complex &dt)
{
    cout << " a = ";
    in_stream >> dt.a;
    cout << " b = ";
    in_stream >> dt.b;
    return in_stream;
}

/*---------------------------------------------------------*/

template <typename T>
class Matrix
{
    T **m;
    int strn;
    int column;

public:
    Matrix(int strn, int column);
    Matrix<T> &operator+(Matrix<T> &mtr);
    Matrix<T> &operator-(Matrix<T> &mtr);
    Matrix<T> &operator=(Matrix<T> &mtr);
    friend ostream &operator<<<>(ostream &out_stream, const Matrix<T> &matr);
    friend istream &operator>><>(istream &in_stream, Matrix<T> &matr);
};

template <typename T>
Matrix<T>::Matrix(int str, int col)
{
    int i, j;
    strn = str;
    column = col;
    m = new T *[strn];
    for (i = 0; i < strn; i++)
    {
        m[i] = new T[column];
    }
}

template <typename T>
istream &operator>>(istream &in_stream, Matrix<T> &matr)
{
    int i, j;
    for (i = 0; i < matr.strn; i++)
    {
        for (j = 0; j < matr.column; j++)
        {
            cout << "M[" << i << "][" << j << "]=";
            in_stream >> matr.m[i][j];
        }
    }
    return in_stream;
}

template <typename T>
ostream &operator<<(ostream &out_stream, const Matrix<T> &matr)
{
    int i, j;
    for (i = 0; i < matr.strn; i++)
    {
        for (j = 0; j < matr.column; j++)
        {
            out_stream << "\t" << matr.m[i][j];
        }
        cout << "\n";
    }
    return out_stream;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+(Matrix<T> &mtr)
{
    int i, j;
    for (i = 0; i < strn; i++)
        for (j = 0; j < column; j++)
            m[i][j] = m[i][j] + mtr.m[i][j];
    return (*this);
}

template <typename T>
Matrix<T> &Matrix<T>::operator-(Matrix<T> &mtr)
{
    int i, j;
    for (i = 0; i < strn; i++)
        for (j = 0; j < column; j++)
            m[i][j] = m[i][j] - mtr.m[i][j];
    return (*this);
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &mtr)
{
    int i, j;
    for (i = 0; i < strn; i++)
        for (j = 0; j < column; j++)
            m[i][j] = mtr.m[i][j];
    return (*this);
}

int main()
{
    Matrix<int> matr_0(3, 3), matr_1(3, 3);
    cout << "Введите значения(int) : " << endl;
    cin >> matr_0;
    cin >> matr_1;
    cout << "int + int: " << endl
         << (matr_0 + matr_1);
    cout << "int - int: " << endl
         << (matr_0 - matr_1);

    Matrix<float> matr_2(3, 3), matr_3(3, 3);
    cout << "Введите значения(float) : " << endl;
    cin >> matr_2;
    cin >> matr_3;
    cout << "float + float : \n"
         << (matr_2 + matr_3);
    cout << "float - float : \n"
         << (matr_2 - matr_3);

    Matrix<Complex> complex_1(3, 3), complex_2(3, 3);
    cout << "Введите значения(complex) : " << endl;
    cin >> complex_1;
    cin >> complex_2;
    cout << "complex + complex : \n"
         << (complex_1 + complex_2);
    cout << "complex - complex : \n"
         << (complex_1 - complex_2);
}