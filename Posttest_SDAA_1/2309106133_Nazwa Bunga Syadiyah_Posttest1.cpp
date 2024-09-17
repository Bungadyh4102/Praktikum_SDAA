#include <iostream>
using namespace std;

void pindahkanMenaraHanoi(int jumlahPiringan, char menaraAsal, char menaraTujuan, char menaraSementara);

int main() {
    int jumlahPiringan = 3; 
    char menaraAsal = 'A';  
    char menaraTujuan = 'C'; 
    char menaraSementara = 'B';

    cout << "Solusi dari Menara Hanoi untuk " << jumlahPiringan << " piringan:" << endl;
    pindahkanMenaraHanoi(jumlahPiringan, menaraAsal, menaraTujuan, menaraSementara);

    return 0;
}

void pindahkanMenaraHanoi(int jumlahPiringan, char menaraAsal, char menaraTujuan, char menaraSementara) {
    if (jumlahPiringan == 1) {
        cout << "Pindahkan piringan 1 dari menara " << menaraAsal << " ke menara " << menaraTujuan << endl;
        return;
    }

    pindahkanMenaraHanoi(jumlahPiringan - 1, menaraAsal, menaraSementara, menaraTujuan);
    cout << "Pindahkan piringan " << jumlahPiringan << " dari menara " << menaraAsal << " ke menara " << menaraTujuan << endl;
    pindahkanMenaraHanoi(jumlahPiringan - 1, menaraSementara, menaraTujuan, menaraAsal);
}
