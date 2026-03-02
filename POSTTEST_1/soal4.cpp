#include <iostream>
using namespace std;

void swapVar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a;
    int b;

    cout << "Input nilai pertama: ";
    cin >> a;
    cout << "Input nilai kedua: ";
    cin >> b;

    cout << "Sebelum Ditukar: " << a << "|" << b << endl;

    swapVar(&a, &b);

    cout
        << "Sesudah Ditukar: " << a << "|" << b << endl;

    return 0;
}