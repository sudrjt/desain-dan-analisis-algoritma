#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap(int arr[], int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

// Fungsi untuk mempartisi array berdasarkan pivot
int partition(int arr[], int low, int high, int pivot) {
	int i = low; // Penunjuk untuk iterasi
	int j = low; // Penunjuk untuk posisi elemen <= pivot

	while (i <= high) {
		if (arr[i] > pivot) {
			// Jika elemen lebih besar dari pivot, lanjutkan ke elemen berikutnya
			i++;
		} else {
			// Jika elemen lebih kecil atau sama dengan pivot, tukar dengan elemen di posisi j
			swap(arr, i, j);
			i++;
			j++;
		}
	}
	// Mengembalikan posisi akhir dari elemen <= pivot
	return j - 1;
}

// Fungsi utama Quick Sort (rekursif)
int quickSort(int arr[], int low, int high) {
	if (low < high) {
		// Pilih pivot sebagai elemen terakhir
		int pivot = arr[high];

		// Dapatkan posisi partisi (elemen <= pivot di kiri, > pivot di kanan)
		int pos = partition(arr, low, high, pivot);

		// Rekursi untuk bagian kiri dan kanan dari pivot
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
	return 0; // Tambahan agar fungsi mengembalikan nilai
}

// Fungsi utama (main)
int main() {
	int n;

	// Input panjang array
	cout << "Tentukan panjang array : ";
	cin >> n;

	int arr[n];

	// Input elemen-elemen array
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Panggil quickSort
	quickSort(arr, 0, n - 1);

	// Cetak hasil array yang sudah disortir
	cout << "Berikut adalah array yang telah di sortir: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}

