#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct KoleksiBarangAntik {
    int kode;
    string namaBarang;
    int tahunProduksi;
    double nilai;
    string pembeli;
    KoleksiBarangAntik* berikut; 
};

KoleksiBarangAntik* kepala = nullptr;

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
    cout << "Nilai Barang: ";
    cin >> barangBaru->nilai;
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
            cout << "\nNilai Barang: " << temp->nilai;
            cout << "\nNama Pembeli: " << temp->pembeli;
            cout << "\n--------------------\n";
            temp = temp->berikut; 
        }
    }
    system("pause");
}

void ubahKoleksi() {
    system("cls");
    int kode;
    cout << "\nMasukkan Kode Barang yang ingin diubah: ";
    cin >> kode;

    KoleksiBarangAntik* temp = kepala;
    while (temp != nullptr) {
        if (temp->kode == kode) {
            cout << "Nama Baru: ";
            cin.ignore();
            getline(cin, temp->namaBarang);
            cout << "Tahun Produksi Baru: ";
            cin >> temp->tahunProduksi;
            cout << "Nilai Baru: ";
            cin >> temp->nilai;
            cout << "Nama Pembeli Baru: ";
            cin.ignore();
            getline(cin, temp->pembeli);

            cout << "Barang berhasil diperbarui!\n";
            system("pause");
            return;
        }
        temp = temp->berikut; 
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

void hapusKoleksi() {
    system("cls");
    int kode;
    cout << "\nMasukkan Kode Barang yang akan dihapus: ";
    cin >> kode;

    KoleksiBarangAntik* temp = kepala;
    KoleksiBarangAntik* sebelumnya = nullptr;

    while (temp != nullptr) {
        if (temp->kode == kode) {
            if (sebelumnya == nullptr) {
                kepala = temp->berikut; 
            } else {
                sebelumnya->berikut = temp->berikut; 
            }
            delete temp; 
            cout << "Barang berhasil dihapus!\n";
            system("pause");
            return;
        }
        sebelumnya = temp;
        temp = temp->berikut;
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

int main() {
    int opsi;

    do {
        system("cls");
        cout << "\nMenu Utama\n";
        cout << "1. Tambah Koleksi\n";
        cout << "2. Tampilkan Koleksi\n";
        cout << "3. Ubah Koleksi\n";
        cout << "4. Hapus Koleksi\n";
        cout << "5. Keluar\n";
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
            ubahKoleksi();
            break;
        case 4:
            hapusKoleksi();
            break;
        case 5:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
        }
    } while (opsi != 5);

    return 0;
}
