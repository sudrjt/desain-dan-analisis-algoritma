#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah nama: ";
    cin >> n;

    string nama[100];

    for (int i = 0; i < n; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        cin >> nama[i];
    }

    cout << "\nSebelum diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i < n; i++) {
        string key = nama[i];
        int j = i - 1;
        while (j >= 0 && nama[j].length() > key.length()) {
            nama[j + 1] = nama[j];
            j--;
        }
        nama[j + 1] = key;
    }

    cout << "\nSetelah diurutkan berdasarkan panjang karakter:\n";
    for (int i = 0; i < n; i++) {
        cout << nama[i] << " ";
    }
    cout << endl;

    return 0;
}

