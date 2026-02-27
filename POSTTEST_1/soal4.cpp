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
    int a = 10;
    int b = 20;

    cout << "Sebelum Ditukar: " << a << "|" << b << endl;

    swapVar(&a, &b);

    cout
        << "Sesudah Ditukar: " << a << "|" << b << endl;

    return 0;
}