#include <iostream>
using namespace std;

void tampilArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << "]" << endl;
}

void quickSort(int arr[], int left, int right, int n) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            tampilArray(arr, n); // Tampilkan array setiap kali swap terjadi
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j, n);
    if (i < right)
        quickSort(arr, i, right, n);
}

int main() {
    int n = 9;
    int data[] = {3, 4, 9, 2, 6, 5, 1, 7, 0};

    cout << "Data yang akan di sort : " << 8 << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }

    cout << "\nQuick Sort :\n";
    tampilArray(data, n);
    quickSort(data, 0, n - 1, n);

    return 0;
}

