#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan data buku
struct Buku {
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() {
    // Deklarasi variabel
    int jumlah_buku;

    // Meminta input jumlah buku
    cout << "Masukkan jumlah buku favorit: ";
    cin >> jumlah_buku;

    // Array variabel buku 
    Buku dataBuku[jumlah_buku];

    // Mengisi data buku
    for (int i = 0; i < jumlah_buku; i++) {
        cout << "\nData Buku ke-" << i + 1 << endl;

        cout << "Judul Buku: ";
        cin.ignore(); // Mengabaikan newline character
        getline(cin, dataBuku[i].judul_buku);

        cout << "Pengarang: ";
        getline(cin, dataBuku[i].pengarang);

        cout << "Penerbit: ";
        getline(cin, dataBuku[i].penerbit);

        cout << "Tebal Halaman: ";
        cin >> dataBuku[i].tebal_halaman;

        cout << "Harga Buku: Rp ";
        cin >> dataBuku[i].harga_buku;
        
    }

    // Menampilkan data buku
    cout << "\n\nBuku Favorit Saya" << endl;
    for (int i = 0; i < jumlah_buku; i++) {
        cout << "\nBuku ke-" << i + 1 << endl;
        cout << "Judul Buku : " << dataBuku[i].judul_buku << endl;
        cout << "Pengarang : " << dataBuku[i].pengarang << endl;
        cout << "Penerbit : " << dataBuku[i].penerbit << endl;
        cout << "Tebal Halaman: " << dataBuku[i].tebal_halaman << " halaman" << endl;
        cout << "Harga Buku : Rp " << dataBuku[i].harga_buku << endl;
    }

    return 0;
}
