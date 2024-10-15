#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct KoleksiBarangAntik {
    int kode;
    string namaBarang;
    int tahunProduksi;
    double harga; 
    string pembeli;
    KoleksiBarangAntik* berikut; 
};

KoleksiBarangAntik* kepala = nullptr;   
KoleksiBarangAntik* topRak = nullptr; 
KoleksiBarangAntik* frontAntrian = nullptr; 
KoleksiBarangAntik* rearAntrian = nullptr; 

// Fungsi untuk mengurutkan menggunakan Merge Sort
void merge(KoleksiBarangAntik** headRef) {
    KoleksiBarangAntik* head = *headRef;
    KoleksiBarangAntik* a;
    KoleksiBarangAntik* b;

    if (head == nullptr || head->berikut == nullptr) {
        return; 
    }

    // Membisahkan linked list menjadi dua
    KoleksiBarangAntik* slow = head;
    KoleksiBarangAntik* fast = head->berikut;

    while (fast != nullptr) {
        fast = fast->berikut;
        if (fast != nullptr) {
            slow = slow->berikut;
            fast = fast->berikut;
        }
    }

    a = head;
    b = slow->berikut;
    slow->berikut = nullptr;

    // Rekursif untuk mengurutkan dua bagian
    merge(&a);
    merge(&b);

    // Menggabungkan dua bagian yang sudah diurutkan
    *headRef = nullptr;
    if (a == nullptr) {
        *headRef = b;
    } else if (b == nullptr) {
        *headRef = a;
    } else if (a->namaBarang <= b->namaBarang) {
        *headRef = a;
        a->berikut = b;
    } else {
        *headRef = b;
        b->berikut = a;
    }
}

void mergeSort(KoleksiBarangAntik** headRef) {
    merge(headRef);
}

// Fungsi untuk mengurutkan menggunakan Quick Sort
void swap(KoleksiBarangAntik* a, KoleksiBarangAntik* b) {
    KoleksiBarangAntik temp = *a;
    *a = *b;
    *b = temp;
}

KoleksiBarangAntik* partition(KoleksiBarangAntik* low, KoleksiBarangAntik* high) {
    double pivot = high->harga; 
    KoleksiBarangAntik* i = low; 

    for (KoleksiBarangAntik* j = low; j != high; j = j->berikut) {
        if (j->harga < pivot) { 
            swap(i, j);
            i = i->berikut;
        }
    }
    swap(i, high);
    return i; 
}

void quickSort(KoleksiBarangAntik* low, KoleksiBarangAntik* high) {
    if (high != nullptr && low != high && low != high->berikut) {
        KoleksiBarangAntik* pivot = partition(low, high);
        quickSort(low, pivot->berikut);
        quickSort(pivot->berikut, high);
    }
}

// Fungsi untuk menambah barang ke dalam linked list
void tambahKoleksi() {
    system("cls");
    KoleksiBarangAntik* barangBaru = new KoleksiBarangAntik;
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

    if (kepala == nullptr) {
        kepala = barangBaru; 
    } else {
        KoleksiBarangAntik* temp = kepala;
        while (temp->berikut != nullptr) {
            temp = temp->berikut; 
        }
        temp->berikut = barangBaru; 
    }

    cout << "Barang berhasil ditambahkan!\n";
    system("pause");
}

// Fungsi untuk menampilkan semua barang di dalam linked list
void tampilkanKoleksi() {
    system("cls");
    if (kepala == nullptr) {
        cout << "Tidak ada barang dalam koleksi.\n";
    } else {
        KoleksiBarangAntik* temp = kepala;
        while (temp != nullptr) {
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

// Fungsi untuk menghapus barang dari linked list
void hapusKoleksi() {
    system("cls");
    if (kepala == nullptr) {
        cout << "Tidak ada barang dalam koleksi.\n";
    } else {
        int kodeHapus;
        cout << "Masukkan kode barang yang akan dihapus: ";
        cin >> kodeHapus;

        KoleksiBarangAntik* temp = kepala;
        KoleksiBarangAntik* prev = nullptr;

        while (temp != nullptr && temp->kode != kodeHapus) {
            prev = temp;
            temp = temp->berikut;
        }

        if (temp == nullptr) {
            cout << "Barang dengan kode " << kodeHapus << " tidak ditemukan.\n";
        } else {
            if (prev == nullptr) {
                kepala = temp->berikut; 
            } else {
                prev->berikut = temp->berikut;
            }
            delete temp;
            cout << "Barang dengan kode " << kodeHapus << " berhasil dihapus.\n";
        }
    }
    system("pause");
}

// Fungsi untuk menambah barang ke Rak
void pushRak() {
    system("cls");
    KoleksiBarangAntik* barangBaru = new KoleksiBarangAntik;
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

// Fungsi untuk menghapus barang dari Rak (LIFO)
void popRak() {
    system("cls");
    if (topRak == nullptr) {
        cout << "Rak kosong!\n";
    } else {
        KoleksiBarangAntik* temp = topRak;
        topRak = topRak->berikut;
        delete temp;
        cout << "Barang berhasil dihapus dari Rak!\n";
    }
    system("pause");
}

// Fungsi untuk menampilkan barang dari Rak (LIFO)
void tampilkanRak() {
    system("cls");
    if (topRak == nullptr) {
        cout << "Rak kosong.\n";
    } else {
        KoleksiBarangAntik* temp = topRak;
        cout << "\nIsi Rak:\n";
        while (temp != nullptr) {
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

// Fungsi untuk menambah barang ke Antrian (FIFO)
void enqueueAntrian() {
    system("cls");
    KoleksiBarangAntik* barangBaru = new KoleksiBarangAntik;
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

    if (rearAntrian == nullptr) {
        frontAntrian = rearAntrian = barangBaru;
    } else {
        rearAntrian->berikut = barangBaru; 
        rearAntrian = barangBaru; 
    }

    cout << "Barang berhasil ditambahkan ke Antrian!\n";
    system("pause");
}

// Fungsi untuk menghapus barang dari Antrian (FIFO)
void dequeueAntrian() {
    system("cls");
    if (frontAntrian == nullptr) {
        cout << "Antrian kosong!\n";
    } else {
        KoleksiBarangAntik* temp = frontAntrian;
        frontAntrian = frontAntrian->berikut;
        if (frontAntrian == nullptr) {
            rearAntrian = nullptr; 
        }
        delete temp;
        cout << "Barang berhasil dihapus dari Antrian!\n";
    }
    system("pause");
}

// Fungsi untuk menampilkan barang dari Antrian (FIFO)
void tampilkanAntrian() {
    system("cls");
    if (frontAntrian == nullptr) {
        cout << "Antrian kosong.\n";
    } else {
        KoleksiBarangAntik* temp = frontAntrian;
        cout << "\nIsi Antrian:\n";
        while (temp != nullptr) {
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

// Fungsi untuk menampilkan menu
void menu() {
    int pilihan;
    do {
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
        cout << "0. Keluar\n";
        cout << "========================\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
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

int main() {
    menu();
    return 0;
}
