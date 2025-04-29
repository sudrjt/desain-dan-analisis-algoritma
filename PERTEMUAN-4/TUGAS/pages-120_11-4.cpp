#include <iostream>  // Mengimpor library untuk input/output standar
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std::

// Program ini merupakan constructor

// Deklarasi kelas bernama 'contoh'
class contoh {
	private:
		int nilai; // Atribut private yang menyimpan nilai

	public:
		// Constructor: metode khusus yang dipanggil saat objek dibuat
		contoh (int n) {
			nilai = n; // Menginisialisasi nilai dengan parameter yang diberikan
		}

		// Fungsi anggota untuk mengambil nilai atribut 'nilai'
		int getNum() {
			return nilai;
		}
};

int main() {
	// Membuat objek 'obj' dari kelas 'contoh', dan memberikan nilai 10 lewat constructor
	contoh obj (10);

	// Menampilkan nilai yang diinput menggunakan fungsi getNum()
	cout << "nilai yang diinput: " << obj.getNum() << endl;

	return 0; // Selesai.
}

