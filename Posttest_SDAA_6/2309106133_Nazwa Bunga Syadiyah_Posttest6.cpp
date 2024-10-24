#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

struct KoleksiBarangAntik{
    int kode;
    string namaBarang;
    int tahunProduksi;
    double harga;
    string pembeli;
    KoleksiBarangAntik *berikut;
};

KoleksiBarangAntik *kepala = nullptr;
KoleksiBarangAntik *topRak = nullptr;
KoleksiBarangAntik *frontAntrian = nullptr;
KoleksiBarangAntik *rearAntrian = nullptr;

void merge(KoleksiBarangAntik **headRef){
    KoleksiBarangAntik *head = *headRef;
    KoleksiBarangAntik *a;
    KoleksiBarangAntik *b;

    if (head == nullptr || head->berikut == nullptr){
        return;
    }

    KoleksiBarangAntik *slow = head;
    KoleksiBarangAntik *fast = head->berikut;

    while (fast != nullptr){
        fast = fast->berikut;
        if (fast != nullptr){
            slow = slow->berikut;
            fast = fast->berikut;
        }
    }

    a = head;
    b = slow->berikut;
    slow->berikut = nullptr;
    merge(&a);
    merge(&b);

    *headRef = nullptr;
    if (a == nullptr){
        *headRef = b;
    } else if (b == nullptr){
        *headRef = a;
    } else if (a->namaBarang <= b->namaBarang){
        *headRef = a;
        a->berikut = b;
    } else{
        *headRef = b;
        b->berikut = a;
    }
}

void mergeSort(KoleksiBarangAntik **headRef){
    merge(headRef);
}

void swap(KoleksiBarangAntik *a, KoleksiBarangAntik *b){
    KoleksiBarangAntik temp = *a;
    *a = *b;
    *b = temp;
}

KoleksiBarangAntik *partition(KoleksiBarangAntik *low, KoleksiBarangAntik *high){
    double pivot = high->harga;
    KoleksiBarangAntik *i = low;

    for (KoleksiBarangAntik *j = low; j != high; j = j->berikut){
        if (j->harga < pivot){
            swap(i, j);
            i = i->berikut;
        }
    }
    swap(i, high);
    return i;
}

void quickSort(KoleksiBarangAntik *low, KoleksiBarangAntik *high){
    if (high != nullptr && low != high && low != high->berikut){
        KoleksiBarangAntik *pivot = partition(low, high);
        quickSort(low, pivot->berikut);
        quickSort(pivot->berikut, high);
    }
}

void tambahKoleksi(){
    system("cls");
    KoleksiBarangAntik *barangBaru = new KoleksiBarangAntik;
    cout << "\nTambah Koleksi Baru\n";
    cout << "Kode Barang: ";
    cin >> barangBaru->kode;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, barangBaru->namaBarang);
    cout << "Tahun Produksi: ";
    cin >> barangBaru->tahunProduksi;
    cout << "Harga Barang: ";
    cin >> barangBaru->harga;
    cout << "Nama Pembeli: ";
    cin.ignore();
    getline(cin, barangBaru->pembeli);

    barangBaru->berikut = nullptr;

    if (kepala == nullptr){
        kepala = barangBaru;
    } else{
        KoleksiBarangAntik *temp = kepala;
        while (temp->berikut != nullptr)
        {
            temp = temp->berikut;
        }
        temp->berikut = barangBaru;
    }

    cout << "Barang berhasil ditambahkan!\n";
    system("pause");
}

void tampilkanKoleksi(){
    system("cls");
    if (kepala == nullptr){
        cout << "Tidak ada barang dalam koleksi.\n";
    } else{
        KoleksiBarangAntik *temp = kepala;
        while (temp != nullptr)
        {
            cout << "\nKode Barang: " << temp->kode;
            cout << "\nNama Barang: " << temp->namaBarang;
            cout << "\nTahun Produksi: " << temp->tahunProduksi;
            cout << "\nHarga Barang: " << temp->harga;
            cout << "\nNama Pembeli: " << temp->pembeli;
            cout << "\n--------------------\n";
            temp = temp->berikut;
        }
    }
    system("pause");
}

void hapusKoleksi(){
    system("cls");
    if (kepala == nullptr){
        cout << "Tidak ada barang dalam koleksi.\n";
    } else{
        int kodeHapus;
        cout << "Masukkan kode barang yang akan dihapus: ";
        cin >> kodeHapus;

        KoleksiBarangAntik *temp = kepala;
        KoleksiBarangAntik *prev = nullptr;

        while (temp != nullptr && temp->kode != kodeHapus){
            prev = temp;
            temp = temp->berikut;
        }

        if (temp == nullptr){
            cout << "Barang dengan kode " << kodeHapus << " tidak ditemukan.\n";
        } else{
            if (prev == nullptr){
                kepala = temp->berikut;
            } else{
                prev->berikut = temp->berikut;
            }
            delete temp;
            cout << "Barang dengan kode " << kodeHapus << " berhasil dihapus.\n";
        }
    }
    system("pause");
}

int fibonacciSearch(KoleksiBarangAntik *head, int x, int n){
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n){
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    KoleksiBarangAntik *current = head;

    while (fibM > 1){
        int i = min(offset + fibMMm2, n - 1);
        KoleksiBarangAntik *temp = head;
        for (int j = 0; j < i && temp != nullptr; j++){
            temp = temp->berikut;
        }

        if (temp == nullptr)
            return -1;

        if (temp->kode < x){
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (temp->kode > x){
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else{
            return i;
        }
    }

    if (fibMMm1 && current->kode == x)
        return offset + 1;

    return -1;
}

void fibonacciSearchDisplay(KoleksiBarangAntik *head, int x, int n){
    int result = fibonacciSearch(head, x, n);
    if (result != -1){
        cout << "Barang dengan kode " << x << " ditemukan di posisi " << result << ".\n";
    } else{
        cout << "Barang dengan kode " << x << " tidak ditemukan.\n";
    }
}

int jumpSearch(KoleksiBarangAntik *head, int x, int n){
    int step = sqrt(n);
    KoleksiBarangAntik *current = head;
    KoleksiBarangAntik *prev = nullptr;

    for (int i = 0; i < step && current != nullptr; i++){
        prev = current;
        current = current->berikut;
    }

    while (current != nullptr && current->kode < x){
        for (int i = 0; i < step && current != nullptr; i++){
            prev = current;
            current = current->berikut;
        }
    }

    while (prev != nullptr && prev->kode < x){
        prev = prev->berikut;
    }

    if (prev != nullptr && prev->kode == x){
        return 1;
    }

    return -1;
}

void jumpSearchDisplay(KoleksiBarangAntik *head, int x, int n){
    int result = jumpSearch(head, x, n);
    if (result != -1){
        cout << "Barang dengan kode " << x << " ditemukan dengan Jump Search.\n";
    } else{
        cout << "Barang dengan kode " << x << " tidak ditemukan.\n";
    }
}

void badCharHeuristic(string str, int size, int badChar[256]){
    for (int i = 0; i < 256; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

int boyerMooreSearch(KoleksiBarangAntik *head, string pattern){
    int m = pattern.size();
    int badChar[256];

    badCharHeuristic(pattern, m, badChar);

    KoleksiBarangAntik *current = head;
    int s = 0;
    while (current != nullptr){
        string text = current->namaBarang;
        int n = text.size();

        while (s <= (n - m)){
            int j = m - 1;

            while (j >= 0 && pattern[j] == text[s + j])
                j--;

            if (j < 0){
                return s;
                s += (s + m < n) ? m - badChar[text[s + m]] : 1;
            } else{
                s += max(1, j - badChar[text[s + j]]);
            }
        }

        current = current->berikut;
    }
    return -1;
}

void pushRak(){
    system("cls");
    KoleksiBarangAntik *barangBaru = new KoleksiBarangAntik;
    cout << "\nTambah Barang ke Rak\n";
    cout << "Kode Barang: ";
    cin >> barangBaru->kode;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, barangBaru->namaBarang);
    cout << "Tahun Produksi: ";
    cin >> barangBaru->tahunProduksi;
    cout << "Harga Barang: ";
    cin >> barangBaru->harga;
    cout << "Nama Pembeli: ";
    cin.ignore();
    getline(cin, barangBaru->pembeli);

    barangBaru->berikut = topRak;
    topRak = barangBaru;

    cout << "Barang berhasil ditambahkan ke Rak!\n";
    system("pause");
}

void popRak(){
    system("cls");
    if (topRak == nullptr){
        cout << "Rak kosong!\n";
    } else{
        KoleksiBarangAntik *temp = topRak;
        topRak = topRak->berikut;
        delete temp;
        cout << "Barang berhasil dihapus dari Rak!\n";
    }
    system("pause");
}

void tampilkanRak(){
    system("cls");
    if (topRak == nullptr){
        cout << "Rak kosong.\n";
    } else{
        KoleksiBarangAntik *temp = topRak;
        cout << "\nIsi Rak:\n";
        while (temp != nullptr){
            cout << "\nKode Barang: " << temp->kode;
            cout << "\nNama Barang: " << temp->namaBarang;
            cout << "\nTahun Produksi: " << temp->tahunProduksi;
            cout << "\nHarga Barang: " << temp->harga;
            cout << "\nNama Pembeli: " << temp->pembeli;
            cout << "\n--------------------\n";
            temp = temp->berikut;
        }
    }
    system("pause");
}

void enqueueAntrian(){
    system("cls");
    KoleksiBarangAntik *barangBaru = new KoleksiBarangAntik;
    cout << "\nTambah Barang ke Antrian\n";
    cout << "Kode Barang: ";
    cin >> barangBaru->kode;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, barangBaru->namaBarang);
    cout << "Tahun Produksi: ";
    cin >> barangBaru->tahunProduksi;
    cout << "Harga Barang: ";
    cin >> barangBaru->harga;
    cout << "Nama Pembeli: ";
    cin.ignore();
    getline(cin, barangBaru->pembeli);

    barangBaru->berikut = nullptr;

    if (rearAntrian == nullptr){
        frontAntrian = rearAntrian = barangBaru;
    } else{
        rearAntrian->berikut = barangBaru;
        rearAntrian = barangBaru;
    }

    cout << "Barang berhasil ditambahkan ke Antrian!\n";
    system("pause");
}

void dequeueAntrian(){
    system("cls");
    if (frontAntrian == nullptr){
        cout << "Antrian kosong!\n";
    } else{
        KoleksiBarangAntik *temp = frontAntrian;
        frontAntrian = frontAntrian->berikut;
        if (frontAntrian == nullptr){
            rearAntrian = nullptr;
        }
        delete temp;
        cout << "Barang berhasil dihapus dari Antrian!\n";
    }
    system("pause");
}

void tampilkanAntrian(){
    system("cls");
    if (frontAntrian == nullptr){
        cout << "Antrian kosong.\n";
    } else{
        KoleksiBarangAntik *temp = frontAntrian;
        cout << "\nIsi Antrian:\n";
        while (temp != nullptr){
            cout << "\nKode Barang: " << temp->kode;
            cout << "\nNama Barang: " << temp->namaBarang;
            cout << "\nTahun Produksi: " << temp->tahunProduksi;
            cout << "\nHarga Barang: " << temp->harga;
            cout << "\nNama Pembeli: " << temp->pembeli;
            cout << "\n--------------------\n";
            temp = temp->berikut;
        }
    }
    system("pause");
}

int hitungKoleksi(KoleksiBarangAntik *head){
    int count = 0;
    KoleksiBarangAntik *current = head;
    while (current != nullptr){
        count++;
        current = current->berikut;
    }
    return count;
}

void menu(KoleksiBarangAntik *kepala){
    int pilihan;
    do{
        system("cls");
        cout << "======== Menu ========\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Tampilkan Koleksi\n";
        cout << "3. Hapus Koleksi\n";
        cout << "4. Tambahkan barang ke Rak\n";
        cout << "5. Hapus barang dari Rak\n";
        cout << "6. Tampilkan Rak\n";
        cout << "7. Tambahkan barang Antrian\n";
        cout << "8. Hapus barang dari Antrian\n";
        cout << "9. Tampilkan Antrian\n";
        cout << "10. Sort dengan Merge Sort\n";
        cout << "11. Sort dengan Quick Sort\n";
        cout << "12. Cari Barang dengan Fibonacci Search\n";
        cout << "13. Cari Barang dengan Jump Search\n";
        cout << "14. Cari Barang dengan Boyer-Moore Search\n";
        cout << "0. Keluar\n";
        cout << "========================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan){
        case 1:
            tambahKoleksi();
            break;
        case 2:
            tampilkanKoleksi();
            break;
        case 3:
            hapusKoleksi();
            break;
        case 4:
            pushRak();
            break;
        case 5:
            popRak();
            break;
        case 6:
            tampilkanRak();
            break;
        case 7:
            enqueueAntrian();
            break;
        case 8:
            dequeueAntrian();
            break;
        case 9:
            tampilkanAntrian();
            break;
        case 10:
            mergeSort(&kepala);
            cout << "Koleksi berhasil diurutkan dengan Merge Sort.\n";
            tampilkanKoleksi();
            system("pause");
            break;
        case 11:
            quickSort(kepala, nullptr);
            cout << "Koleksi berhasil diurutkan dengan Quick Sort.\n";
            tampilkanKoleksi();
            system("pause");
            break;
        case 12:{
            int kodeCari;
            cout << "Masukkan kode barang yang ingin dicari (Fibonacci Search): ";
            cin >> kodeCari;
            int n = hitungKoleksi(kepala);
            fibonacciSearchDisplay(kepala, kodeCari, n);
            system("pause");
            break;
        }
        case 13:{
            int kodeCari;
            cout << "Masukkan kode barang yang ingin dicari (Jump Search): ";
            cin >> kodeCari;
            int n = hitungKoleksi(kepala);         
            jumpSearchDisplay(kepala, kodeCari, n); 
            system("pause");
            break;
        }
        case 14:{
            string namaCari;
            cout << "Masukkan nama barang yang ingin dicari (Boyer-Moore Search): ";
            cin.ignore();
            getline(cin, namaCari);
            if (boyerMooreSearch(kepala, namaCari) != -1){
                cout << "Barang ditemukan dengan Boyer-Moore Search.\n";
            } else{
                cout << "Barang tidak ditemukan.\n";
            }
            system("pause");
            break;
        }
        case 0:
            cout << "Terima kasih! Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
            system("pause");
            break;
        }
    } while (pilihan != 0);
}

int main(){
    KoleksiBarangAntik *kepala = nullptr; 
    menu(kepala);                         
    return 0;
}
