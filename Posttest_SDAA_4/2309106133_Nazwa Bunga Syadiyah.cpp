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
        frontAntrian = barangBaru;
        rearAntrian = barangBaru;
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

// Fungsi untuk menampilkan barang ke Antrian (FIFO)
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

int main() {
    int opsi;

    do {
        system("cls");
        cout << "\nMenu Utama\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Tampilkan Koleksi\n";
        cout << "3. Hapus Koleksi\n"; 
        cout << "4. Tambah Barang ke Rak\n";
        cout << "5. Hapus Barang dari Rak\n";
        cout << "6. Tampilkan Rak\n"; 
        cout << "7. Tambah Barang ke Antrian\n";
        cout << "8. Hapus Barang dari Antrian\n";
        cout << "9. Tampilkan Antrian\n"; 
        cout << "10. Keluar\n";
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
            hapusKoleksi();  // Panggil fungsi hapusKoleksi
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
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
        }
    } while (opsi != 10);

    return 0;
}
