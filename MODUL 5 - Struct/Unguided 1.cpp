#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku dengan array
struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    int harga_buku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam array di variabel favorit
    favorit.judul_buku[0] = "The Alpha Girl's Guide";
    favorit.judul_buku[1] = "You Do You: Discovering Life through Experiments & Self-Awareness";
    favorit.judul_buku[2] = "Siapa Yang Datang Ke Pemakamanku Saat Aku Mati Nanti?";
    favorit.judul_buku[3] = "Funiculi Funicula";
    favorit.judul_buku[4] = "Keajaiban Toko Kelontong Namiya";

    favorit.pengarang[0] = "Henry Manampiring";
    favorit.pengarang[1] = "Fellexandro Ruby";
    favorit.pengarang[2] = "Kim Sang-Hyun";
    favorit.pengarang[3] = "Toshikazu Kawaguchi";
    favorit.pengarang[4] = "Keigo Higashino";

    favorit.penerbit[0] = "Gagas Media";
    favorit.penerbit[1] = "Gramedia Pustaka Utama";
    favorit.penerbit[2] = "Haru";
    favorit.penerbit[3] = "Gramedia Pustaka Utama";
    favorit.penerbit[4] = "Gramedia Pustaka Utama";

    favorit.tebal_halaman[0] = 253;
    favorit.tebal_halaman[1] = 252;
    favorit.tebal_halaman[2] = 168;
    favorit.tebal_halaman[3] = 224;
    favorit.tebal_halaman[4] = 400;

    favorit.harga_buku[0] = 79000;
    favorit.harga_buku[1] = 96000;
    favorit.harga_buku[2] = 74250;
    favorit.harga_buku[3] = 52500;
    favorit.harga_buku[4] = 97500;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku ke-" << i + 1 << endl;
        cout << "\tJudul Buku : " << favorit.judul_buku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebal_halaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.harga_buku[i] << endl << endl;
    }

    return 0;
}
