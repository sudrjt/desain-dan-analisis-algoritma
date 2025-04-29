#include <iostream>
using namespace std;

class Buku {
private:
    string judul;
    string pengarang;
    bool statusDipinjam;

public:
    void setData(string j, string p) {
        judul = j;
        pengarang = p;
        statusDipinjam = false;
    }

    void tampilkanData() {
        cout << "\nJudul     : " << judul << endl;
        cout << "Pengarang : " << pengarang << endl;
        cout << "Status    : " << (statusDipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    void pinjamBuku() {
        if (!statusDipinjam) {
            statusDipinjam = true;
            cout << "\nBuku berhasil dipinjam." << endl;
        } else {
            cout << "\nBuku sedang dipinjam." << endl;
        }
    }

    void kembalikanBuku() {
        if (statusDipinjam) {
            statusDipinjam = false;
            cout << "Buku berhasil dikembalikan." << endl;
        } else {
            cout << "Buku belum dipinjam." << endl;
        }
    }
};

int main() {
    Buku buku1;

    buku1.setData("Harry Potter", "Jk. Rowling");

    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Kembalikan Buku\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                buku1.tampilkanData();
                break;
            case 2:
                buku1.pinjamBuku();
                break;
            case 3:
                buku1.kembalikanBuku();
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}

