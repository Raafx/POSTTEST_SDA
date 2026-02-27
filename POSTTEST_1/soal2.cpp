#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
};

Mahasiswa findMaxIpk(Mahasiswa data_mahasiswa[5])
{
    Mahasiswa max = data_mahasiswa[0];
    for (int i = 1; i < 8; i++)
    {
        if (data_mahasiswa[i].ipk > max.ipk)
        {
            max = data_mahasiswa[i];
        }
    }

    return max;
}

int main()
{

    Mahasiswa data_mahasiswa[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Input Nama: ";
        getline(cin, data_mahasiswa[i].nama);
        cout << "Input NIM: ";
        getline(cin, data_mahasiswa[i].nim);
        cout << "Input IPK: ";
        cin >> data_mahasiswa[i].ipk;

        cout << "Data Berhasil ditambahkan!\n"
             << endl;
        cin.ignore();
    }

    Mahasiswa mahasiswa_ipk_tertinggi = findMaxIpk(data_mahasiswa);

    cout << "\n==================================================\n"
         << "Mahasiswa Dengan IPK tertinggi adalah:\n"
         << "Nama: " << mahasiswa_ipk_tertinggi.nama
         << "\nNIM : " << mahasiswa_ipk_tertinggi.nim
         << "\nIPK : " << mahasiswa_ipk_tertinggi.ipk
         << endl;

    return 0;
}