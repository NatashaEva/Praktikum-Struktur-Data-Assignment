# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Struct adalah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang [1]. Struct memungkinkan para pengembang untuk mengelompokkan data dengan karakteristik serupa ke dalam satu entitas. Setiap elemen pada struct dapat memiliki variasi jenis data yang berbeda, sebuah struktur dinyatakan dengan memanfaatkan keyword yaitu 'struct' atau dalam penulisannya pada bahasa C++ dikenal dengan nama struct [2].




## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/6395eaec-6c12-41eb-a6e9-db73afe44234)


Kode diatas merupakan struktur dengan nama buku yang didalamnya berisi data judul buku, pengarang, penerbit yang bertipe data string sedangkan data tebal halaman dan harga buku yang bertipe data integer. Pada program ini user diharuskan memasukan informasi yang diperlukan pada kode diatas. 

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/11c0fd3e-1be9-4062-a9ea-753c106ab63d)


```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}

```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/6844f0c2-a5ea-4577-93e2-d37bf5713116)


 Kode diatas menggunakan 3 struktur data, data pertama yaitu struktur data hewan yang digunakan untuk mendefinisikan struktur hewan yang berisi nama hewan, jenis kelamin, cara berkembang biak, alat pernapasan, tempat hidup, dan apakah hewan tersebut termasuk hewan karnivora atau tidak. Pada struktur data kedua yaitu data hewanDarat yang memiliki variabel tambahan sendiri yaitu jumlahKaki  yang digunakan untuk menyimpan nilai integer mewakili jumlah kaki hewan darat, menyusui digunakan untuk menyimpan apakah hewan tersebut termasuk hewan menyusui atau tidak yang dinyatakan dengan nilai true or false, dan suara yang menyimpan teks penjelasan suara hewan darat. Pada struktur data ketiga yang bernama hewanLaut yang berisi data bentuk sirip dan bentuk pertahanan diri.



## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.


```C++
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


```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5b7071da-6643-4f83-b410-78d78729ad7a)


#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/fb49f39c-60ef-4d33-8a64-d821a0516302)
Program ini merupakan struktur data bernama buku yang digunakan untuk menyimpan informasi buku yaitu judul, pengarang, penerbit yang bertipe data string dan tebal halaman dan harga yang bertipe intger yang berbentuk array berukuran 5. Pada program ini user harus memasukan informasi buku terlebih dahulu didalam kode yang disimpan dalam variabel favorit. Setelah memasukan informasi yang diperlukan kode ini akan menampilkan informasi tersebut dalam bentuk array yang memungkinkan menyimpan informasi tentang beberapa buku dalam satu variabel. 

 
### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided 1, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?


```C++
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

```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/42bb987a-61f9-4a4b-ad66-876c64fa211a)

### Full code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/b85dc787-fde6-4980-836c-5cec5e08034d)

Program ini digunakan untuk menyimpan informasi beberapa judul buku sesuai yang diinginkan oleh user. Struktur kode ini didefinisikan dengan nama Buku untuk menyimpan informasi satu buku, struktur ini memiliki 5 variabel yaitu judul_buku untuk menyimpan judul buku, pengarang untuk menyimpan nama pengarang buku, penerbit untuk menyimpan nama penerbit buku, tebal_halaman untuk menyimpan jumlah halaman buku, harga_buku untuk menyimpan harga buku. Kemudian program ini akan meminta user untuk menginput jumlah buku yang akan disimpan informasinya, kemudian program ini akan meminta user kembali untuk mengisi informasi tentang buku yang akan disimpan informasinya. 



## Kesimpulan
Kesimpulan dari materi ini, Struct adalah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda. Struct memungkinkan para pengembang untuk mengelompokkan data dengan karakteristik serupa ke dalam satu entitas.

## Referensi

[1] Dwi Putra, Muhammad T., et al. BELAJAR PEMROGRAMAN LANJUT DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA, 2023.

[2] Purbasari, Wika, et al. ALGORITMA PEMROGRAMAN. Edited by Setiya Putra, Yusuf W., and Hanson P. Putro, CV WIDINA MEDIA UTAMA, 2024.



 