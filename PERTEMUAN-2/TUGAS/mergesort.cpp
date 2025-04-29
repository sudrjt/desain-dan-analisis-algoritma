#include <iostream>
using namespace std;

void tampilList(int arr[], int start, int end) {
    cout << "[";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ", ";
    }
    cout << "]" << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "Menggabungkan List ";
    tampilList(arr, left, right);

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        cout << "Pemecah List ";
        tampilList(arr, left, right);

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int data[] = {9, 2, 6, 5, 8, 3, 7, 4, 0, 1};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Input 10 data : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    mergeSort(data, 0, n - 1);

    return 0;
}

