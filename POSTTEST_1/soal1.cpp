#include <iostream>
using namespace std;

int findMin(int A[], int n)
{
    int indexMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[indexMin])
        {
            indexMin = i;
        }
    }

    return indexMin;
}

int main()
{
    int fibonacci[8] = {0, 0, 2, 3, 5, 8, 13, 21};
    int n = sizeof(fibonacci) / sizeof(fibonacci[0]);

    int index = findMin(fibonacci, n);
    int min = fibonacci[index];

    cout << "Nilai min: " << min << endl
         << "Indeks min: " << index << endl;

    return 0;
}

/*

Analisis Kompleksitias waktu pada findMin

=====================================
Pseudocode          Cost  Tmin Tmax
-------------------------------------
procedure FindMin    C1     1    1
min <- A[0]          C2     1    1
for i <- 1 to n − 1  C3     n    n
if A[i] < min        C4     n-1  n-1
min <- A[i]          C5     0    n-1
end if               C6     n-1  n-1
end for              C7     n    n
return min           C8     1    1
end procedure        C9     1    1
-------------------------------------
Total waktu (Tn)           O(n) O(n)
=====================================

WORST CASE :
    Worst Case terjadi ketika elemen terkecil yang dicari berada pada akhir Array, yang mengakibatkan kode min = A[i]; selalu dieksekusi

    Tmax(n) = C1(1) + C2(1) + C3(n) + C4(n-1) + C5(n-1) + C6(n-1) + C7(n) + C8(1) + C9(1)
    => O(n)



BEST CASE:
    Best Case terjadi ketika elemen terkecil yang dicari langsung berada pada awal Array, sehingga kode min = A[i]; tidak pernah dieksekusi

    Tmin(n) = C1(1) + C2(1) + C3(n) + C4(n-1) + 0 + C6(n-1) + C7(n) + C8(1) + C9(1)
    => O(n)

Dari hasil perhitungan, dapat disimpulkan bahwa kompleksitas waktu baik dari worst case maupun best case adalah O(n)


*/