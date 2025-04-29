#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = low - 1;

        cout << "Pivot: " << pivot << " | ";
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                cout << "Swapped " << arr[i] << " and " << arr[j] << ": ";
                printArray(arr);
            }
        }

        swap(arr[i + 1], arr[high]);
        cout << "Swapped pivot " << arr[i + 1] << " and " << arr[high] << ": ";
        printArray(arr);

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    cout << "Merging: ";
    printArray(arr);

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    cout << "After merge: ";
    printArray(arr);
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr;
    int n, temp;

    cout << "=== QuickSort and MergeSort Flowchart ===" << endl;
    cout << "Masukkan Jumlah Array: ";
    cin >> n;

    cout << "Masukkan nilai: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Unsorted array: ";
    printArray(arr);

    vector<int> quickArr = arr;
    vector<int> mergeArr = arr;

    cout << "\n=== Langkah Quick Sort ===" << endl;
    quickSort(quickArr, 0, n - 1);
    cout << "Sorted array menggunakkan Quick Sort: ";
    printArray(quickArr);

    cout << "\n=== Langkah Merge Sort ===" << endl;
    mergeSort(mergeArr, 0, n - 1);
    cout << "Sorted array menggunakkan Merge Sort: ";
    printArray(mergeArr);

    return 0;
}

