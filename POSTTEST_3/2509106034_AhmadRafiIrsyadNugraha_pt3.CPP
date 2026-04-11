#include <iostream>
#include <cmath>
#define MAX 100
using namespace std;

struct Kereta
{
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Transaksi
{
    string namaPenumpang;
    string asal;
    string tujuan;
    string namaKereta;
};

Transaksi antrianTiket[MAX];
Transaksi riwayatTranksaksi[MAX];
int front = -1, rear = -1;
int top = -1;

bool isFull()
{
    return rear == MAX - 1;
}
bool isEmpty()
{
    return front == -1 || front > rear;
}

void tampilkanAntrian(Transaksi *antrianTiket)
{
    if (isEmpty())
    {
        cout << "Antrian Masih Kosong" << endl;
        return;
    }

    // Loop mulai dari posisi front sampai ke rear
    cout << "==============================================" << endl;
    for (int i = front; i <= rear; i++)
    {
        cout
            << "Nama Penumpang  : " << (antrianTiket + i)->namaPenumpang << endl
            << "Asal            : " << (antrianTiket + i)->asal << endl
            << "Tujuan          : " << (antrianTiket + i)->tujuan << endl
            << "Nama Kereta     : " << (antrianTiket + i)->namaKereta << endl
            << "----------------------------------------------" << endl;
    }
    cout << endl;
}

void tampilkanRiwayat(Transaksi *riwayatTranksaksi)
{
    if (top == -1)
    {
        cout << "Riwayat Masih Kosong" << endl;
        return;
    }

    // Loop mulai dari posisi front sampai ke rear
    cout << "==============================================" << endl;
    for (int i = top; i >= 0; i--)
    {
        cout
            << "Nama Penumpang  : " << (riwayatTranksaksi + i)->namaPenumpang << endl
            << "Asal            : " << (riwayatTranksaksi + i)->asal << endl
            << "Tujuan          : " << (riwayatTranksaksi + i)->tujuan << endl
            << "Nama Kereta     : " << (riwayatTranksaksi + i)->namaKereta << endl
            << "----------------------------------------------" << endl;
    }
    cout << endl;
}

void enqueueAntrianBaru(Transaksi *value)
{

    if (isFull())
    {
        cout << "==| Mohon Maaf, Antrian sudah penuh |==" << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
    }
    rear++;
    *(antrianTiket + rear) = *value;
    cout << "\n==| Penumpang berhasil memasuki Antrian |==\n"
         << endl;
    tampilkanAntrian(antrianTiket);
}

void beliTiket()
{
    Transaksi *tiketBaru = new Transaksi;

    cout << "Input Nama Penumpang: ";
    getline(cin, tiketBaru->namaPenumpang);
    cout << "Input Asal: ";
    getline(cin, tiketBaru->asal);
    cout << "Input Tujuan: ";
    getline(cin, tiketBaru->tujuan);
    cout << "Input Nama Kereta: ";
    getline(cin, tiketBaru->namaKereta);

    enqueueAntrianBaru(tiketBaru);
}

Transaksi dequeueAntrianLama()
{
    Transaksi kosong;

    if (front == -1 || front > rear)
    {
        cout << "Antrian kosong (Underflow)!\n"
             << endl;
        return kosong;
    }

    Transaksi data = *(antrianTiket + front);
    front++;

    return data;
}

void pushRiwayatBaru(Transaksi *value)
{
    if (top >= MAX - 1)
    {
        cout << "==| Riwayat Tranksaksi Penuh (Overflow)! |==" << endl;
    }
    else
    {
        top++;
        *(riwayatTranksaksi + top) = *value;
    }
}

void popRiwayatTerbaru()
{

    if (top < 0)
    {
        cout << "Riwayat Tranksaksi Kosong (Stack Underflow)" << endl;
    }
    else
    {
        Transaksi value = *(riwayatTranksaksi + top);
        top--;
        cout << "Riwayat Tranksaksi Terbaru Berhasil Dihapus!" << endl;
    }
}

void peekRiwayatTerbaru()
{
    Transaksi kosong;
    if (top < 0)
    {
        cout << "Riwayat Tranksaksi Kosong (Stack Underflow)" << endl;
    }
    else
    {
        cout << "\n                RIWAYAT TERBARU               " << endl;
        cout << "==============================================" << endl;
        cout
            << "Nama Penumpang  : " << (riwayatTranksaksi + top)->namaPenumpang << endl
            << "Asal            : " << (riwayatTranksaksi + top)->asal << endl
            << "Tujuan          : " << (riwayatTranksaksi + top)->tujuan << endl
            << "Nama Kereta     : " << (riwayatTranksaksi + top)->namaKereta << endl
            << "----------------------------------------------\n"
            << endl;
    }
}

void peekAntrianTerdepan()
{

    if (isEmpty())
    {
        cout << "Antrian Penumpang Kosong" << endl;
    }
    else
    {
        cout << "               ANTRIAN TERDEPAN               " << endl;
        cout << "==============================================" << endl;
        cout
            << "Nama Penumpang  : " << (antrianTiket + front)->namaPenumpang << endl
            << "Asal            : " << (antrianTiket + front)->asal << endl
            << "Tujuan          : " << (antrianTiket + front)->tujuan << endl
            << "Nama Kereta     : " << (antrianTiket + front)->namaKereta << endl
            << "----------------------------------------------\n"
            << endl;
    }
}

void prosesTiket()
{
    Transaksi riwayat = dequeueAntrianLama();
    pushRiwayatBaru(&riwayat);
    Transaksi *riwayatPtr = &riwayat;

    cout << "Selamat, Data penumpang berikut berhasil diproses: " << endl;
    cout
        << "==============================================" << endl;
    cout
        << "Nama Penumpang  : " << riwayatPtr->namaPenumpang << endl
        << "Asal            : " << riwayatPtr->asal << endl
        << "Tujuan          : " << riwayatPtr->tujuan << endl
        << "Nama Kereta     : " << riwayatPtr->namaKereta << endl
        << "----------------------------------------------" << endl;
}

Kereta *dataKeberangkatan[MAX];
string namaKeretaAwal[3] = {"Gajayana", "KertaJaya", "Argo Lawu"};
string asalAwal[3] = {"Bandung", "Jakarta", "Semarang"};
string tujuanAwal[3] = {"Banten", "Bandung", "Solo"};
float hargaAwal[3] = {55000, 65000, 70000};

void buatKereta(Kereta *&ptr)
{
    ptr = new Kereta;
}
void tambahData(Kereta *dataKeberangkatan[], int &jumlahData)
{

    buatKereta(dataKeberangkatan[jumlahData]);
    bool isValid;
    isValid = false;
    do
    {

        cout << "Input Nomor: ";
        cin >> (*(dataKeberangkatan + jumlahData))->nomor;
        cin.ignore(1000, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nomor Keberangkatan harus berupa angka!" << endl;
        }
        else
        {
            isValid = true;
        }
    } while (isValid == false);

    cout << "Input Nama Kereta: ";
    getline(cin, (*(dataKeberangkatan + jumlahData))->nama);
    cout << "Input Asal Keberangkatan: ";
    getline(cin, (*(dataKeberangkatan + jumlahData))->asal);
    cout << "Input Tujuan Keberangkatan: ";
    getline(cin, (*(dataKeberangkatan + jumlahData))->tujuan);

    isValid = false;
    do
    {

        cout << "Input Harga Tiket: ";
        cin >> (*(dataKeberangkatan + jumlahData))->harga;
        cin.ignore(1000, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harga Tiket harus berupa angka!" << endl;
        }
        else
        {
            isValid = true;
        }
    } while (isValid == false);

    jumlahData++;
}
void tampilkanData(Kereta *dataKeberangkatan[], int &jumlahData)
{

    cout << "==============================================" << endl;
    for (int i = 0; i < jumlahData; i++)
    {
        cout
            << "Nomor       : " << (*(dataKeberangkatan + i))->nomor << endl
            << "Nama Kereta : " << (*(dataKeberangkatan + i))->nama << endl
            << "Asal        : " << (*(dataKeberangkatan + i))->asal << endl
            << "Tujuan      : " << (*(dataKeberangkatan + i))->tujuan << endl
            << "Harga       : " << (*(dataKeberangkatan + i))->harga << endl
            << "----------------------------------------------" << endl;
    }
}

void merge(Kereta *dataKeberangkatan[], int left, int mid, int right, int mode)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Kereta *L[100], *R[100];

    for (int i = 0; i < n1; i++)
        L[i] = dataKeberangkatan[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = dataKeberangkatan[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        bool kondisi = false;

        if (mode == 1)
            kondisi = L[i]->nama < R[j]->nama;
        else if (mode == 2)
            kondisi = L[i]->harga < R[j]->harga;
        else if (mode == 3)
            kondisi = L[i]->nomor < R[j]->nomor;

        if (kondisi)
        {
            dataKeberangkatan[k] = L[i];
            i++;
        }
        else
        {
            dataKeberangkatan[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        dataKeberangkatan[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        dataKeberangkatan[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Kereta *dataKeberangkatan[], int left, int right, int mode)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(dataKeberangkatan, left, mid, mode);
        mergeSort(dataKeberangkatan, mid + 1, right, mode);

        merge(dataKeberangkatan, left, mid, right, mode);
    }
}

void sortNama(Kereta *dataKeberangkatan[], int &jumlahData)
{
    Kereta *temp[100];

    for (int i = 0; i < jumlahData; i++)
    {
        temp[i] = dataKeberangkatan[i];
    }

    mergeSort(temp, 0, jumlahData - 1, 1);
    cout << "=========| Data Telah diurutkan sesuai Nama Kereta |=========\n"
         << endl;
    tampilkanData(temp, jumlahData);
}

void cariRute(Kereta *dataKeberangkatan[], int jumlahData)
{
    string asalCari, tujuanCari;

    cout << "Masukkan asal: ";
    getline(cin, asalCari);

    cout << "Masukkan tujuan: ";
    getline(cin, tujuanCari);

    bool ketemu = false;

    for (int i = 0; i < jumlahData; i++)
    {
        if (dataKeberangkatan[i]->asal == asalCari &&
            dataKeberangkatan[i]->tujuan == tujuanCari)
        {
            cout << "Data Keberangkatan Ditemukan!\n"
                 << endl
                 << "----------------------------------------------" << endl
                 << "Nomor       : " << (*(dataKeberangkatan + i))->nomor << endl
                 << "Nama Kereta : " << (*(dataKeberangkatan + i))->nama << endl
                 << "Asal        : " << (*(dataKeberangkatan + i))->asal << endl
                 << "Tujuan      : " << (*(dataKeberangkatan + i))->tujuan << endl
                 << "Harga       : " << (*(dataKeberangkatan + i))->harga << endl
                 << "----------------------------------------------" << endl;

            ketemu = true;
        }
    }

    if (!ketemu)
    {
        cout << "===| Mohon Maaf, Data tidak ditemukan |===.\n";
    }
}

int jumpSearch(Kereta *dataKeberangkatan[], int n, int target)
{
    int step = sqrt(n);
    int prev = 0;

    // Iterasi 1 (fase lompatan):
    // Cek elemen dataKeberangkatan di index (step - 1)
    // Jika nilainya < target, maka pindah ke blok berikutnya (prev = step)
    // Ulangi proses sampai menemukan blok dimana nilai >= target

    while (prev < n && dataKeberangkatan[min(step, n) - 1]->nomor < target)
    {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n)
            return -1;
    }

    // Batasi variabel batas agar tidak melewati jumlah index array
    int batas = step;
    if (batas > n)
        batas = n;

    // Iterasi 2 (fase linear):
    // Mulai dari index prev
    // Cek satu per satu sampai batas blok
    // Jika ketemu, maka return index
    // Jika tidak, maka lanjut sampai habis
    while (prev < batas)
    {
        if (dataKeberangkatan[prev]->nomor == target)
            return prev;
        prev++;
    }
    return -1;
}

void cariNomor(Kereta *dataKeberangkatan[], int &jumlahData)
{
    bool isValid = false;
    int target;
    do
    {
        cout << "Input Nomor Keberangkatan yang ingin dicari: ";
        cin >> target;
        cin.ignore(1000, '\n');
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Nomor Keberangkatan harus berupa angka!" << endl;
        }
        else
        {
            isValid = true;
        }
    } while (isValid == false);

    Kereta *temp[100];

    for (int i = 0; i < jumlahData; i++)
    {
        temp[i] = dataKeberangkatan[i];
    }

    mergeSort(temp, 0, jumlahData - 1, 3);

    int indexKetemu = jumpSearch(temp, jumlahData, target);

    if (indexKetemu != -1)
    {
        cout << "Data Keberangkatan Ditemukan!\n"
             << endl
             << "----------------------------------------------" << endl
             << "Nomor       : " << (*(temp + indexKetemu))->nomor << endl
             << "Nama Kereta : " << (*(temp + indexKetemu))->nama << endl
             << "Asal        : " << (*(temp + indexKetemu))->asal << endl
             << "Tujuan      : " << (*(temp + indexKetemu))->tujuan << endl
             << "Harga       : " << (*(temp + indexKetemu))->harga << endl
             << "----------------------------------------------" << endl;
    }

    else
    {
        cout << "===| Mohon Maaf, Data tidak ditemukan |===.\n";
    }
}

void selectionSort(Kereta *dataKeberangkatan[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (dataKeberangkatan[j]->harga < dataKeberangkatan[minIndex]->harga)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            Kereta temp = *dataKeberangkatan[i];
            *dataKeberangkatan[i] = *dataKeberangkatan[minIndex];
            *dataKeberangkatan[minIndex] = temp;
        }
    }
}

void sortHarga(Kereta *dataKeberangkatan[], int &jumlahData)
{
    Kereta *temp[100];

    for (int i = 0; i < jumlahData; i++)
    {
        temp[i] = dataKeberangkatan[i];
    }

    selectionSort(temp, jumlahData);
    cout << "=========| Data Telah diurutkan sesuai Harga Tiket |=========\n"
         << endl;
    tampilkanData(temp, jumlahData);
}

int main()
{
    // Buat Data Dummy Awal
    for (int i = 0; i < 3; i++)
    {
        dataKeberangkatan[i] = new Kereta;
        dataKeberangkatan[i]->nomor = i + 1;
        dataKeberangkatan[i]->nama = namaKeretaAwal[i];
        dataKeberangkatan[i]->asal = asalAwal[i];
        dataKeberangkatan[i]->tujuan = tujuanAwal[i];
        dataKeberangkatan[i]->harga = hargaAwal[i];
    }
    int jumlahData = 3;
    int pilihMenu;
    bool programJalan = true;

    while (programJalan)
    {
        cout << "\n===========| SISTEM MANAJEMEN KEBERANGKATAN KERETA API |===========" << endl
             << "1. Tambah Data Kereta Baru" << endl
             << "2. Tampilkan Semua Keberangkatan" << endl
             << "3. Cari Berdasarkan Rute" << endl
             << "4. Cari Nomor Kereta" << endl
             << "5. Urutkan Berdasarkan nama kereta" << endl
             << "6. Urutkan Berdasarkan Harga Tiket" << endl
             << "7. Beli Tiket (Masuk Antrian)" << endl
             << "8. Proses Tiket" << endl
             << "9. Lihat Antrian" << endl
             << "10. Lihat Riwayat" << endl
             << "11. Peek Antrian & Riwayat" << endl
             << "12. Batalkan Transaksi Terakhir" << endl
             << "13. Keluar" << endl
             << "Pilih Menu: ";

        cin >> pilihMenu;
        cin.ignore();

        switch (pilihMenu)
        {
        case 1:
            tambahData(dataKeberangkatan, jumlahData);
            break;
        case 2:
            tampilkanData(dataKeberangkatan, jumlahData);
            break;
        case 3:
            cariRute(dataKeberangkatan, jumlahData);
            break;
        case 4:
            cariNomor(dataKeberangkatan, jumlahData);
            break;
        case 5:
            sortNama(dataKeberangkatan, jumlahData);
            break;
        case 6:
            sortHarga(dataKeberangkatan, jumlahData);
            break;
        case 7:
            beliTiket();
            break;
        case 8:
            prosesTiket();
            break;
        case 9:
            tampilkanAntrian(antrianTiket);
            break;
        case 10:
            tampilkanRiwayat(riwayatTranksaksi);
            break;
        case 11:
            peekAntrianTerdepan();
            peekRiwayatTerbaru();
            break;
        case 12:
            popRiwayatTerbaru();
            break;
        case 13:
            programJalan = false;
            break;

        default:
            break;
        }
    }

    return 0;
}