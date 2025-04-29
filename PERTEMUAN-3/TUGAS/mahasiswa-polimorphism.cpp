#include <iostream>
using namespace std;

class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;
    string status;

public:
    Mahasiswa(string n, int u, string j, string f, string s) {
        nama = n;
        umur = u;
        jurusan = j;
        fakultas = f;
        status = s;
    }

    virtual void tampilkanData() {
        cout << "Nama     : " << nama << endl;
        cout << "Umur     : " << umur << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "Fakultas : " << fakultas << endl;
        cout << "Status   : " << status << endl << endl;
    }
};

class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string n, int u, string j, string f)
        : Mahasiswa(n, u, j, f, "Mahasiswa Aktif") {}

    void tampilkanData() override {
        cout << "[Mahasiswa Aktif]" << endl;
        Mahasiswa::tampilkanData();
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string n, int u, string j, string f)
        : Mahasiswa(n, u, j, f, "Alumni") {}

    void tampilkanData() override {
        cout << "[Alumni]" << endl;
        Mahasiswa::tampilkanData();
    }
};

int main() {
    Mahasiswa* mahasiswa1 = new MahasiswaAktif("Sudrajat", 20, "Teknologi Informasi", "Informatika dan Pariwisata");
    Mahasiswa* mahasiswa2 = new Alumni("Alucard", 26, "Akuntansi", "Bisnis");

    mahasiswa1->tampilkanData();
    mahasiswa2->tampilkanData();

    return 0;
}

