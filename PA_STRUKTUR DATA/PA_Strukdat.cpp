#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

struct BarangAntik
{
    int id;
    string nama;
    string jenis;
    int usia; // Usia barang dalam tahun
    double nilai;
    string kondisi;
    BarangAntik *next; // Pointer ke node berikutnya
};

BarangAntik *head = NULL;

void badCharacterHeuristic(std::string pattern, int *badChar);

// Struktur data untuk Rak menggunakan Stack
stack<BarangAntik> rakStack;

// Fungsi untuk menambahkan barang
void tambahBarang()
{
    system("cls");
    BarangAntik *newBarang = new BarangAntik;

    cout << "\nTambah Barang\n";
    cout << "ID Barang: ";
    cin >> newBarang->id;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, newBarang->nama);
    cout << "Jenis Barang (misalnya, Patung, Keramik, Tekstil): ";
    getline(cin, newBarang->jenis);
    cout << "Usia Barang (dalam tahun): ";
    cin >> newBarang->usia;
    cout << "Nilai Barang: ";
    cin >> newBarang->nilai;
    cout << "Kondisi Barang (misalnya, Baik, Sedang, Rusak): ";
    cin.ignore();
    getline(cin, newBarang->kondisi);

    newBarang->next = head; // Menyambungkan node baru ke awal linked list
    head = newBarang;       // Head menunjuk ke node baru

    // Menambahkan barang ke rak menggunakan stack
    rakStack.push(*newBarang);

    cout << "Barang berhasil ditambahkan!\n";
    system("pause");
}

// Fungsi untuk menampilkan semua barang
void tampilkanBarang()
{
    system("cls");
    if (head == NULL)
    {
        cout << "Tidak ada barang.\n";
    }
    else
    {
        BarangAntik *temp = head;
        while (temp != NULL)
        {
            cout << "\nID Barang: " << temp->id;
            cout << "\nNama Barang: " << temp->nama;
            cout << "\nJenis Barang: " << temp->jenis;
            cout << "\nUsia Barang: " << temp->usia << " tahun";
            cout << fixed << setprecision(0);
            cout << "\nNilai Barang: Rp" << temp->nilai;
            cout << "\nKondisi Barang: " << temp->kondisi;
            cout << "\n-------------------\n";
            temp = temp->next;
        }
    }
    system("pause");
}

// Fungsi untuk mengedit barang berdasarkan ID
void editBarang()
{
    system("cls");
    int id;
    cout << "\nMasukkan ID Barang yang akan diedit: ";
    cin >> id;

    BarangAntik *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Nama Baru: ";
            cin.ignore();
            getline(cin, temp->nama);
            cout << "Jenis Baru: ";
            getline(cin, temp->jenis);
            cout << "Usia Baru (dalam tahun): ";
            cin >> temp->usia;
            cout << "Nilai Baru: ";
            cin >> temp->nilai;
            cout << "Kondisi Baru: ";
            cin.ignore();
            getline(cin, temp->kondisi);

            cout << "Barang berhasil diupdate!\n";
            system("pause");
            return;
        }
        temp = temp->next;
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

// Fungsi untuk menghapus barang berdasarkan ID
void hapusBarang()
{
    system("cls");
    int id;
    cout << "\nMasukkan ID Barang yang akan dihapus: ";
    cin >> id;

    BarangAntik *temp = head;
    BarangAntik *prev = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Barang berhasil dihapus!\n";
            system("pause");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

// Fungsi untuk menampilkan barang berdasarkan jenis
void tampilkanBarangBerdasarkanJenis()
{
    system("cls");
    string jenis;
    cout << "\nMasukkan Jenis Barang yang akan ditampilkan: ";
    cin.ignore();
    getline(cin, jenis);

    bool ditemukan = false;
    BarangAntik *temp = head;
    while (temp != NULL)
    {
        if (temp->jenis == jenis)
        {
            cout << "\nID Barang: " << temp->id;
            cout << "\nNama Barang: " << temp->nama;
            cout << "\nJenis Barang: " << temp->jenis;
            cout << "\nUsia Barang: " << temp->usia << " tahun";
            cout << "\nNilai Barang: Rp" << temp->nilai;
            cout << "\nKondisi Barang: " << temp->kondisi;
            cout << "\n-------------------\n";
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan)
    {
        cout << "Tidak ada barang dengan jenis tersebut.\n";
    }

    system("pause");
}

// Fungsi untuk menampilkan detail barang berdasarkan ID
void tampilkanDetailBarang()
{
    system("cls");
    int id;
    cout << "\nMasukkan ID Barang yang akan ditampilkan detailnya: ";
    cin >> id;

    BarangAntik *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nDetail Barang\n";
            cout << "ID Barang: " << temp->id;
            cout << "\nNama Barang: " << temp->nama;
            cout << "\nJenis Barang: " << temp->jenis;
            cout << "\nUsia Barang: " << temp->usia << " tahun";
            cout << "\nNilai Barang: Rp" << temp->nilai;
            cout << "\nKondisi Barang: " << temp->kondisi;
            cout << "\n-------------------\n";
            system("pause");
            return;
        }
        temp = temp->next;
    }

    cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
    system("pause");
}

// Fungsi untuk menambahkan barang (dengan parameter)
void tambahBarangAuto(int id, string nama, string jenis, int usia, double nilai, string kondisi)
{
    BarangAntik *newBarang = new BarangAntik;
    newBarang->id = id;
    newBarang->nama = nama;
    newBarang->jenis = jenis;
    newBarang->usia = usia;
    newBarang->nilai = nilai;
    newBarang->kondisi = kondisi;
    newBarang->next = head;
    head = newBarang;
    rakStack.push(*newBarang);
}

// Fungsi inisialisasi data barang
void initDataBarang()
{
    tambahBarangAuto(1, "Patung Perunggu Yunani", "Patung", 2000, 1000000000, "Baik");
    tambahBarangAuto(2, "Keramik Dinasti Ming", "Keramik", 600, 750000000, "Baik");
    tambahBarangAuto(3, "Lukisan Baroque Belanda", "Lukisan", 300, 900000000, "Sedang");
    tambahBarangAuto(4, "Jam Saku Edwardian", "Logam", 120, 200000000, "Baik");
    tambahBarangAuto(5, "Meja Marmer Romawi", "Furnitur", 1500, 2000000000, "Rusak");
    tambahBarangAuto(6, "Pedang Samurai Edo", "Senjata", 400, 500000000, "Baik");
    tambahBarangAuto(7, "Kain Tenun Kalimantan Kuno", "Tekstil", 150, 100000000, "Sedang");
    tambahBarangAuto(8, "Buku Manuskrip Arab", "Buku", 800, 600000000, "Baik");
    tambahBarangAuto(9, "Piring Keramik Persia", "Keramik", 500, 250000000, "Baik");
    tambahBarangAuto(10, "Guci Tiongkok Qing", "Keramik", 200, 300000000, "Baik");
}

// Struktur data untuk rak kedua menggunakan Stack
stack<BarangAntik> rakStack2;

// Fungsi untuk memindahkan barang antar rak
void pindahkanBarangAntarRak()
{
    system("cls");

    if (rakStack.empty())
    {
        cout << "Rak 1 kosong. Tidak ada barang yang bisa dipindahkan.\n";
    }
    else
    {
        int idBarang;
        cout << "Masukkan ID Barang yang ingin dipindahkan dari Rak 1 ke Rak 2: ";
        cin >> idBarang;

        bool ditemukan = false;
        stack<BarangAntik> tempStack;

        while (!rakStack.empty())
        {
            BarangAntik barang = rakStack.top();
            rakStack.pop();

            if (barang.id == idBarang)
            {
                // Menemukan barang, pindahkan ke rak kedua
                rakStack2.push(barang);
                cout << "Barang dengan ID " << barang.id << " berhasil dipindahkan ke Rak 2.\n";
                ditemukan = true;
                break;
            }
            else
            {
                // Simpan barang yang tidak dipindahkan ke temporary stack
                tempStack.push(barang);
            }
        }

        // Kembalikan barang yang tidak dipindahkan ke rak pertama
        while (!tempStack.empty())
        {
            rakStack.push(tempStack.top());
            tempStack.pop();
        }

        if (!ditemukan)
        {
            cout << "Barang dengan ID " << idBarang << " tidak ditemukan di Rak 1.\n";
        }
    }

    system("pause");
}

// Fungsi untuk menampilkan daftar barang per rak
void tampilkanBarangPerRak()
{
    system("cls");
    cout << "Daftar Barang di Rak 1:\n";
    if (rakStack.empty())
    {
        cout << "Rak 1 kosong.\n";
    }
    else
    {
        stack<BarangAntik> tempStack = rakStack;
        while (!tempStack.empty())
        {
            BarangAntik barang = tempStack.top();
            cout << "\nID Barang: " << barang.id;
            cout << "\nNama Barang: " << barang.nama;
            cout << "\nJenis Barang: " << barang.jenis;
            cout << "\nUsia Barang: " << barang.usia << " tahun";
            cout << "\nNilai Barang: Rp" << barang.nilai;
            cout << "\nKondisi Barang: " << barang.kondisi;
            cout << "\n-------------------\n";
            tempStack.pop();
        }
    }

    cout << "\nDaftar Barang di Rak 2:\n";
    if (rakStack2.empty())
    {
        cout << "Rak 2 kosong.\n";
    }
    else
    {
        stack<BarangAntik> tempStack = rakStack2;
        while (!tempStack.empty())
        {
            BarangAntik barang = tempStack.top();
            cout << "\nID Barang: " << barang.id;
            cout << "\nNama Barang: " << barang.nama;
            cout << "\nJenis Barang: " << barang.jenis;
            cout << "\nUsia Barang: " << barang.usia << " tahun";
            cout << "\nNilai Barang: Rp" << barang.nilai;
            cout << "\nKondisi Barang: " << barang.kondisi;
            cout << "\n-------------------\n";
            tempStack.pop();
        }
    }
    system("pause");
}

// Fungsi untuk mengubah linked list ke array
vector<BarangAntik *> linkedListToArray()
{
    vector<BarangAntik *> array;
    BarangAntik *temp = head;
    while (temp != NULL)
    {
        array.push_back(temp);
        temp = temp->next;
    }
    return array;
}

// Fungsi untuk mengubah array kembali ke linked list
void arrayToLinkedList(vector<BarangAntik *> &array)
{
    head = NULL;
    for (int i = array.size() - 1; i >= 0; i--)
    {
        array[i]->next = head;
        head = array[i];
    }
}

// Quick Sort (helper function untuk partisi)
int partition(vector<BarangAntik *> &array, int low, int high)
{
    int pivot = array[high]->usia;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j]->usia < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

// Quick Sort (fungsi utama)
void quickSort(vector<BarangAntik *> &array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Fungsi untuk Quick Sort linked list berdasarkan usia
void sortUsiaQuickSort()
{
    vector<BarangAntik *> array = linkedListToArray();
    quickSort(array, 0, array.size() - 1);
    arrayToLinkedList(array);
    cout << "Barang berhasil diurutkan berdasarkan usia (ascending).\n";
    tampilkanBarang();
    system("pause");
}

// Shell Sort berdasarkan nilai barang secara descending
void shellSort(vector<BarangAntik *> &array)
{
    int n = array.size();
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            BarangAntik *temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap]->nilai < temp->nilai; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

// Fungsi untuk Shell Sort linked list berdasarkan nilai
void sortNilaiShellSort()
{
    vector<BarangAntik *> array = linkedListToArray();
    shellSort(array);
    arrayToLinkedList(array);
    cout << "Barang berhasil diurutkan berdasarkan nilai (descending).\n";
    tampilkanBarang();
    system("pause");
}

void fibonacciSearch(vector<BarangAntik *> &arr, int n, int x){
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1){
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i]->usia < x){
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i]->usia > x)
        {
            fibM = fibMMm2;
            fibMMm2 = fibMMm1 - fibMMm2;
            fibMMm1 = fibM - fibMMm2;
        }
        else
        {
            cout << "Barang dengan usia " << x << " ditemukan di index " << i << endl;
            return;
        }
    }

    if (arr[offset + 1]->usia == x)
        cout << "Barang dengan usia " << x << " ditemukan di index " << offset + 1 << endl;
    else
        cout << "Barang dengan usia " << x << " tidak ditemukan.\n";
}

void boyerMooreSearch(vector<BarangAntik *> &arr, string pattern){
    int n = arr.size();
    int m = pattern.size();
    int badChar[256];

    badCharacterHeuristic(pattern, badChar);

    int s = 0;
    while (s <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && arr[s + j]->nama[j] == pattern[j])
            j--;
        if (j < 0)
        {
            cout << "Pattern ditemukan di index " << s << endl;
            return;
        }
        else
        {
            s += max(1, j - badChar[(int)arr[s + j]->nama[j]]);
        }
    }
    cout << "Pattern tidak ditemukan\n";
}

void badCharacterHeuristic(string pattern, int *badChar){
    int m = pattern.size();

    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

void jumpSearch(vector<BarangAntik *> &arr, int n, double x){
    int step = sqrt(n);

    int prev = 0;
    while (arr[min(step, n) - 1]->nilai < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            cout << "Barang dengan nilai " << x << " tidak ditemukan.\n";
            return;
        }
    }

    for (int i = prev; i < min(step, n); i++)
    {
        if (arr[i]->nilai == x)
        {
            cout << "Barang dengan nilai " << x << " ditemukan di index " << i << endl;
            return;
        }
    }
    cout << "Barang dengan nilai " << x << " tidak ditemukan.\n";
}

int main() {
    int pilihan;
    initDataBarang();

    do {
        system("cls");
        cout << "\nMenu\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Edit Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Tampilkan Barang Berdasarkan Jenis\n";
        cout << "6. Detail Barang Antik\n";
        cout << "7. Pindahkan Barang Antar Rak\n";
        cout << "8. Tampilkan Barang per Rak\n";
        cout << "9. Urutkan Barang Berdasarkan Usia (Quick Sort)\n";
        cout << "10. Urutkan Barang Berdasarkan Nilai (Shell Sort)\n";
        cout << "11. Cari Barang Berdasarkan Usia Barang\n";
        cout << "12. Cari Barang Berdasarkan Nama Barang\n";
        cout << "13. Cari Barang Berdasarkan Nilai Barang\n";
        cout << "14. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                tambahBarang();
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                editBarang();
                break;
            case 4:
                hapusBarang();
                break;
            case 5:
                tampilkanBarangBerdasarkanJenis();
                break;
            case 6:
                tampilkanDetailBarang();
                break;
            case 7:
                pindahkanBarangAntarRak();
                break;
            case 8:
                tampilkanBarangPerRak();
                break;
            case 9:
                sortUsiaQuickSort();
                break;
            case 10:
                sortNilaiShellSort();
                break;
            case 11:
            {
                int usiaSearch;
                cout << "Masukkan usia yang ingin dicari: ";
                cin >> usiaSearch;

                vector<BarangAntik *> barangArray = linkedListToArray();
                fibonacciSearch(barangArray, barangArray.size(), usiaSearch);
                cout << "Fibonacci Search selesai. Kembali ke menu..." << endl;
                system("pause");
                break;
            }
            case 12:
            {
                string namaSearch;
                cout << "Masukkan nama barang yang ingin dicari: ";
                cin.ignore();
                getline(cin, namaSearch);
                vector<BarangAntik *> barangArray = linkedListToArray();
                boyerMooreSearch(barangArray, namaSearch);
                system("pause");
                break;
            }
            case 13:
            {
                double nilaiSearch;
                cout << "Masukkan nilai barang yang ingin dicari: ";
                cin >> nilaiSearch;
                vector<BarangAntik *> barangArray = linkedListToArray();
                jumpSearch(barangArray, barangArray.size(), nilaiSearch);
                system("pause");
                break;
            }
            case 14:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                system("pause");
        }
    } while (pilihan != 14);

    return 0;
}
