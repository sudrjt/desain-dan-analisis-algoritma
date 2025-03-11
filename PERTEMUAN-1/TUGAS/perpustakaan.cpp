#include <iostream>
#include <string>

using namespace std;

void insertionSort(string buku[], int n) {
    for (int i = 1; i < n; i++) {
        string key = buku[i];
        int j = i - 1;

        while (j >= 0 && buku[j] > key) {
            buku[j + 1] = buku[j];
            j--;
        }
        buku[j + 1] = key;

        cout << "proses sorting" << ": \n";
        for (int k = 0; k < n; k++) {
            cout << buku[k] << " | ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah buku: ";
    cin >> n;
    cin.ignore();

    string buku[n];

    cout << "Masukkan judul buku:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Buku ke-" << i + 1 << ": ";
        getline(cin, buku[i]);
    }

    cout << "\nData sebelum sorting: ";
    for (int i = 0; i < n; i++) {
        cout << buku[i] << " | ";
    }
    cout << endl << endl;

    insertionSort(buku, n);

    cout << "\nData setelah sorting: \n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << buku[i] << endl;
    }
    cout << endl;

    return 0;
}

