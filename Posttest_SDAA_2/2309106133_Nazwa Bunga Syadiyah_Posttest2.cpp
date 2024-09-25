#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct BarangAntik {
    int id;
    string nama;
    int tahun;
    double harga;
    string pembeli; 
};

void tambahBarang(BarangAntik* barangList, int* jumlahBarang) {
    system("cls");
    cout << "\nTambah Barang\n";
    cout << "ID Barang: ";
    cin >> barangList[*jumlahBarang].id;
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, barangList[*jumlahBarang].nama);
    cout << "Tahun Pembuatan: ";
    cin >> barangList[*jumlahBarang].tahun;
    cout << "Harga Barang: ";
    cin >> barangList[*jumlahBarang].harga;
    cout << "Nama Pembeli: ";
    cin.ignore();
    getline(cin, barangList[*jumlahBarang].pembeli);

    (*jumlahBarang)++;
    cout << "Barang berhasil ditambahkan!\n";
    system("pause");
}

void tampilkanBarang(BarangAntik* barangList, int jumlahBarang) {
    system("cls");
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang.\n";
    } else {
        for (int i = 0; i < jumlahBarang; i++) {
            cout << "\nID Barang: " << barangList[i].id;
            cout << "\nNama Barang: " << barangList[i].nama;
            cout << "\nTahun Pembuatan: " << barangList[i].tahun;
            cout << "\nHarga: " << barangList[i].harga;
            cout << "\nNama Pembeli: " << barangList[i].pembeli;
            cout << "\n-------------------\n";
        }
    }
    system("pause");
}

void editBarang(BarangAntik* barangList, int jumlahBarang) {
    system("cls");
    int id;
    cout << "\nMasukkan ID Barang yang akan diedit: ";
    cin >> id;

    for (int i = 0; i < jumlahBarang; i++) {
        if (barangList[i].id == id) {
            cout << "Nama Baru: ";
            cin.ignore();
            getline(cin, barangList[i].nama);
            cout << "Tahun Baru: ";
            cin >> barangList[i].tahun;
            cout << "Harga Baru: ";
            cin >> barangList[i].harga;
            cout << "Nama Pembeli Baru: ";
            cin.ignore();
            getline(cin, barangList[i].pembeli);

            cout << "Barang berhasil diupdate!\n";
            system("pause");
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

void hapusBarang(BarangAntik* barangList, int* jumlahBarang) {
    system("cls");
    int id;
    cout << "\nMasukkan ID Barang yang akan dihapus: ";
    cin >> id;

    for (int i = 0; i < *jumlahBarang; i++) {
        if (barangList[i].id == id) {
            for (int j = i; j < *jumlahBarang - 1; j++) {
                barangList[j] = barangList[j + 1];
            }
            (*jumlahBarang)--;
            cout << "Barang berhasil dihapus!\n";
            system("pause");
            return;
        }
    }

    cout << "Barang tidak ditemukan.\n";
    system("pause");
}

int main() {
    const int MAX_BARANG = 100;
    BarangAntik barangList[MAX_BARANG];
    int jumlahBarang = 0;
    int pilihan;

    do {
        system("cls");
        cout << "\nMenu\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Edit Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang(barangList, &jumlahBarang);
            break;
        case 2:
            tampilkanBarang(barangList, jumlahBarang);
            break;
        case 3:
            editBarang(barangList, jumlahBarang);
            break;
        case 4:
            hapusBarang(barangList, &jumlahBarang);
            break;
        case 5:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            system("pause");
        }
    } while (pilihan != 5);

    return 0;
}
