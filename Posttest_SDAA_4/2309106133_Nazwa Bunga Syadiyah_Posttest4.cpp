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
KoleksiBarangAntik* topStack = nullptr; 
KoleksiBarangAntik* frontQueue = nullptr; 
KoleksiBarangAntik* rearQueue = nullptr; 

// Fungsi untuk menambahkan barang ke dalam linked list
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

// Fungsi untuk menambah barang ke Stack
void push() {
    system("cls");
    KoleksiBarangAntik* barangBaru = new KoleksiBarangAntik;
    cout << "\nTambah Barang ke Stack\n";
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

    barangBaru->berikut = topStack;
    topStack = barangBaru;

    cout << "Barang berhasil ditambahkan ke Stack!\n";
    system("pause");
}

// Fungsi untuk menghapus barang dari Stack (LIFO)
void pop() {
    system("cls");
    if (topStack == nullptr) {
        cout << "Stack kosong!\n";
    } else {
        KoleksiBarangAntik* temp = topStack;
        topStack = topStack->berikut;
        delete temp;
        cout << "Barang berhasil dihapus dari Stack!\n";
    }
    system("pause");
}

// Fungsi untuk menampilkan barang dari Stack (LIFO)
void tampilkanStack() {
    system("cls");
    if (topStack == nullptr) {
        cout << "Stack kosong.\n";
    } else {
        KoleksiBarangAntik* temp = topStack;
        cout << "\nIsi Stack:\n";
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

// Fungsi untuk menambah barang ke Queue (FIFO)
void enqueue() {
    system("cls");
    KoleksiBarangAntik* barangBaru = new KoleksiBarangAntik;
    cout << "\nTambah Barang ke Queue\n";
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
    if (rearQueue == nullptr) {
        frontQueue = barangBaru;
        rearQueue = barangBaru;
    } else {
        rearQueue->berikut = barangBaru;
        rearQueue = barangBaru;
    }

    cout << "Barang berhasil ditambahkan ke Queue!\n";
    system("pause");
}

// Fungsi untuk menghapus barang dari Queue (FIFO)
void dequeue() {
    system("cls");
    if (frontQueue == nullptr) {
        cout << "Queue kosong!\n";
    } else {
        KoleksiBarangAntik* temp = frontQueue;
        frontQueue = frontQueue->berikut;
        if (frontQueue == nullptr) {
            rearQueue = nullptr;
        }
        delete temp;
        cout << "Barang berhasil dihapus dari Queue!\n";
    }
    system("pause");
}

// Fungsi untuk menampilkan barang ke Queue (FIFO)
void tampilkanQueue() {
    system("cls");
    if (frontQueue == nullptr) {
        cout << "Queue kosong.\n";
    } else {
        KoleksiBarangAntik* temp = frontQueue;
        cout << "\nIsi Queue:\n";
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

int main() {
    int opsi;

    do {
        system("cls");
        cout << "\nMenu Utama\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Tampilkan Koleksi\n";
        cout << "3. Tambah Barang ke Stack\n";
        cout << "4. Hapus Barang dari Stack\n";
        cout << "5. Tampilkan Stack\n"; 
        cout << "6. Tambah Barang ke Queue\n";
        cout << "7. Hapus Barang dari Queue\n";
        cout << "8. Tampilkan Queue\n"; 
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> opsi;

        switch (opsi) {
        case 1:
            tambahKoleksi();
            break;
        case 2:
            tampilkanKoleksi();
            break;
        case 3:
            push();
            break;
        case 4:
            pop();
            break;
        case 5:
            tampilkanStack(); 
            break;
        case 6:
            enqueue();
            break;
        case 7:
            dequeue();
            break;
        case 8:
            tampilkanQueue(); 
            break;
        case 9:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
        }
    } while (opsi != 9);

    return 0;
}
