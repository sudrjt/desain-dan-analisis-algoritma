#include <iostream>
#include <string>
using namespace std;

class Kontak {
private:
    string nama;
    string nomor;

public:
    Kontak(string n = "", string no = "") {
        nama = n;
        nomor = no;
    }

    void setKontak(string n, string no) {
        nama = n;
        nomor = no;
    }

    void tampilkan() const {
        cout << "Nama: " << nama << ", Nomor: " << nomor << endl;
    }
};

int main() {
    const int MAKS_KONTAK = 10;
    Kontak daftarKontak[MAKS_KONTAK];
    int jumlahKontak = 0;
    int pilihan;

    do {
        cout << "\n=== MENU KONTAK ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Semua Kontak\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlahKontak < MAKS_KONTAK) {
                    string nama, nomor;
                    cout << "Masukkan nama: ";
                    getline(cin, nama);
                    cout << "Masukkan nomor: ";
                    getline(cin, nomor);

                    daftarKontak[jumlahKontak] = Kontak(nama, nomor);
                    jumlahKontak++;

                    cout << "Kontak berhasil ditambahkan.\n";
                } else {
                    cout << "Batas maksimum kontak (10) telah tercapai!\n";
                }
                break;

            case 2:
                if (jumlahKontak == 0) {
                    cout << "Belum ada kontak.\n";
                } else {
                    cout << "\nDaftar Kontak:\n";
                    for (int i = 0; i < jumlahKontak; i++) {
                        cout << i + 1 << ". ";
                        daftarKontak[i].tampilkan();
                    }
                }
                break;

            case 3:
                cout << "Keluar dari program.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 3);

    return 0;
}

