#include <iostream>
using namespace std;

int findMin(int A[8])
{
    int min = A[0];
    for (int i = 1; i < 8; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    return min;
}

int main()
{
    int fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int min = findMin(fibonacci);

    cout << "Nilai min: " << min << endl;

    return 0;
}