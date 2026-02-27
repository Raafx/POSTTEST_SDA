#include <iostream>
using namespace std;

void reverseArray(int *arr, int n)
{
    for (int i = 0; i < (n / 2); i++)
    {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}

int main()
{
    int primaArray[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = sizeof(primaArray) / sizeof(primaArray[0]);
    int *primaPtr = primaArray;

    int *reversedArray[n];

    cout << "\nSebelum Dibalik" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(primaArray + i) << " | " << primaPtr + i << endl;
    }

    reverseArray(primaPtr, n);

    cout << "\nSessudah Dibalik" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(primaArray + i) << " | " << primaPtr + i << endl;
    }
    return 0;
}