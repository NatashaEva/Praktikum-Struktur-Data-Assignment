# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Searching adalah suatu metode untuk menemukan hal tertentu dalam suatu data[1]. Algortima searching memungkinkan user untuk mencari nilai berdasarkan suatu kriteria[2]. Algoritma searching dibagi menjadi dua metode: 

#### 1. Sequential Search
Algoritma searching paling sederhana, dengan membandingkan setiap elemen satu persatu secara berurutan, dari elemen pertama sampai elemen yang dicari ditemukan atau semua elemen telah diperiksa. Algoritma sequential search adalah sebagai berikut :
- Melakukan perbandingan tiap elemen dalam pada suatu data satu persatu secara berurutan.
- Proses pencarian ini akan melakukan perulangan dari elemen ke-1 hingga elemen ke-n, dan akan dibandingkan dengan elemen yang dicari.
- Apabila elemen sama dengan elemen yang dicari maka elemen berhasil ditemukan, sebaliknya apabila sampai elemen terakhir tidak ada elemen yang sama dengan elemen yang dicari, maka elemen tidak berhasil ditemukan[3].

#### 2. Binary Search
Binary search dapat dilakukan apabila data sudah dalam keadaan terurut. Binary search dilakukan untuk memperkecil jumlah operasi pembandingan yang harus dilakukan antar data yang dicari dengan data yang ada dalam array. Algoritma binary search adalah sebagai berikut: 
- Ambil posisi awal yaitu 1 dan posisi akhir yaitu N
- Kemudian cari data yang berada ditengah dengan membagi jumlah data dibagi dua.
- Bandingkan data yang dicari dengan data yang ditengah, jika lebih kecil, proses perulangan dilakukan kembali dengan menggangap posisi tengah menjadi posisi akhir. Namun jika lebih besar, posisi tengah akan dianggap menjadi posisi awal. 
- Proses ini dilakukan berulang ulang hingga data tengah sama dengan data yang dicari[4].




## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10; //Mendeklarasikan variabel n 
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; // Mendeklarasikan data dengan panjang n(10)
    int cari = 10; //Mendeklarasikan variabel cari
    bool ketemu = false; //Mendeklarasikan variabel ketemu dengan tipe boolean
    int i;

    //algoritma sequential seacrh
    for (i = 0; i < n; i++) {
        if(data[i] == cari) { //Membandingkan nilai data [i] dengan nilai cari
            ketemu = true; //Jika sama mengubah varibel ketemu menjadi true
            break;
        }
    }
    cout << "\t Program Sequential Search sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;

    if(ketemu) {
        cout << "\nAngka "<< cari <<  "ditemukan di indeks ke-" << i << endl;
    } else {
        cout << cari << "tidak dapat ditemukan pada data" << endl;
    }
    return 0;
}
```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ff1c0487-27af-4306-a5c5-36db2036e593)

Kode diatas merupakan program algoritma sequential search untuk mencari nilai tertentu dalam array. Kode ini membandingkan secara berulang hingga elemen yang dicari ditemukan atau hingga elemen terakhir. Dalam kode ini terdapat 10 elemen, user akan diminta memasukan elemen apa yang akan dicari kemudia kode ini akan melakukan perulangan dengan metode sequential search.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (Data[j] < Data[min]) {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (Data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if (Data[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main () {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";

    //tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/112db5e4-8dc1-4b8f-a5ef-ab12f8f05e81)


 Kode diatas digunakan untuk mencari data dengan metode binary search, program ini menggunakan selection sort yang akan mengurutkan data terlebih dahulu kemudian membagi array menjadi dua bagian, kemudia mencari elemen yang dicari. Proses ini akan terus berulang hingga data yang dicari ditemukan atau seluruh elemen telah dicari. 



## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!


```C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  char cari;
  int awal, akhir, tengah;
  bool b_flag = false;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Input huruf yang dicari
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> cari;

  // Mengubah semua huruf dalam kalimat menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Mengurutkan huruf dalam kalimat
  sort(kalimat.begin(), kalimat.end());

  // Menentukan batas awal dan akhir pencarian
  awal = 0;
  akhir = kalimat.length() - 1;

  // Melakukan binary search
  while (b_flag == 0 && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (kalimat[tengah] == cari) {
      b_flag = true;
      break;
    } else if (kalimat[tengah] < cari) {
      awal = tengah + 1;
    } else {
      akhir = tengah - 1;
    }
  }

  // Menampilkan hasil pencarian
  if (b_flag) {
    cout << "Huruf " << cari << " ditemukan pada kalimat " << endl;
  } else {
    cout << "Huruf " << cari << " tidak ditemukan pada kalimat" << endl;
  }

  return 0;
}

```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/e3772a68-cc96-4174-aead-bc4b4918a754)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/15effc92-8c43-4e6d-9ca9-e6ae1c78ba5b)

Program ini digunakan untuk mencari huruf yang akan diinputkan user dalam suatu kalimat yang juga telah diinput user kemudian program ini akan memberitahu apaka huruf tersebut terdapat dalam kalimat tersebut dan dalam indeks keberapa. Pada program ini menggunakan tipe data string yang digunakan untuk menyimpan kalimat berbentuk karakter, untuk menyimpan huruf yang akan dicari program ini menggunakan variabel char, kemudian untuk menentukan batas awal, akhir, dan tengah digunakan variabel int awal, akhir, tengah. Program ini akan menghitung indeks tengah pada kalimat dengan cara tengah = (awal +akhir) / 2, apabila huruf pada indeks tengah sama dengan huruf yang dicari maka program ini akan mengubah variabel b_flag menjadi true. Jika huruf pada indeks tengah lebih kecil dari huruf yang dicari maka program ini akan memperbaharui batas awal pencarian menjadi indeks setelah tengah dengan cara awal = tengah + 1, namun jika huruf pada indeks tengah lebih besar dari huruf yang dicari maka program ini akan memperbaharui batas akhir pencarian menjadi indeks sebelum tengah dengan cara akhir = tengah - 1. Proses ini akan terus berulang hingga huruf yang dicari telah ditemukan.

 
### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!


```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
  string kalimat;
  int hurufVokal = 0;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Menghitung jumlah huruf vokal
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' ||
        kalimat[i] == 'e' || kalimat[i] == 'o') {
      hurufVokal++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah huruf vokal di kalimat: " << hurufVokal << endl;

  return 0;
}


```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/65864bfa-3a80-4127-8e0d-1ba6a368838f)


### Full code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4ffeca81-dcc5-4003-9a15-7ce296c12f53)


Program ini digunakan untuk menghitung jumlah huruf vokal yaitu a, i, u, e, o dalam suatu kalimat. Pada program ini menggunakan tipe data string dengan variabel kalimat untuk menyimpan kalimat yang akan diinputkan oleh user, kemudian tipe data int dengan variabel hurufVokal untuk menyimpan jumlah huruf vokal pada kalimat tersebut. Kemudian program ini akan melakukan looping memerikasa setiap karakter dalam kalimat yang telah diinput user, kemudian akan memeriksa karakter tersebut pada indeks i apakah termasuk dalam huruf vokal. 




### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!


```C++
#include <iostream>

using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int jumlah = 0;

    for (int i = 0; i < n; ++i) {
        if (data[i] == 4) {
            jumlah++;
        }
    }

    cout << "Jumlah angka 4 dalam data: " << jumlah << endl;

    return 0;
}

```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/fc99d3b9-e99c-403b-a3fc-75d6a2316187)


### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/f0e6407f-9f12-44f5-9040-f4177cf0e87c)


Program ini digunakan untuk mencari berapa banyak angka 4 dalam data yang telah ditentukan dengan metode sequential search. Program ini memakai variabel array bernama data untuk memasukan elemen elemen nilai yang telah ditentukan. Fungsi menghitung jumlah elemen dalam array data dengan int n = sizeof(data) / sizeof(data[0]). Kemudian looping sequential search dengan membandingkan semua elemen satu persatu dari indeks 0 hingga indeks n. Jika menemukan elemen bernilai 4, dengan cara data[i] == 4 dan jumlah incremented akan bertambah 1. Proses ini akan terus berulang hingga elemen akhir. 



## Kesimpulan
Kesimpulan dari materi ini, searching adalah suatu metode untuk menemukan hal tertentu dalam suatu data. Algortima ini  memungkinkan user untuk mencari nilai berdasarkan suatu kriteria. Algoritma searching dibagi menjadi dua metode yaitu sequential search dengan membandingkan setiap elemen satu persatu secara berurutan, dari elemen pertama sampai elemen yang dicari ditemukan atau semua elemen telah diperiksa dan binary search yang mengharuskan data sudah dalam keadaan terurut. Binary search dilakukan untuk memperkecil jumlah operasi pembandingan yang harus dilakukan antar data yang dicari dengan data yang ada dalam array.

## Referensi

[1] Search Algorithm: Essence of Optimization. (2023). Britania Raya: IntechOpen.

[2] Botwright, Rob. Algorithms: Computer Science Unveiled. N.p., Rob Botwright, 2024.

‌
[3] C. INFORMATIKA and Nurul Imamah, “PERBANDINGAN ALGORITMA SEQUENTIAL SEARCH DAN ALGORITMA BINARY SEARCH PADA APLIKASI KAMUS BAHASA INDONESIA MENGGUNAKAN PHP DAN JQUERY ”, COMPUTING, vol. 8, no. 01, pp. 1–6, Jun. 2021.
 
[4] Wijaya, A., Maulana, M., & Danil, M. (2021). APLIKASI PENCARIAN RESEP MASAKAN KHAS BENGKULU MENGGUNAKAN ALGORITMA BINARY SEARCH BERBASIS ANDROID. JURNAL MEDIA INFOTAMA, 17(1). https://doi.org/10.37676/jmi.v17i1.1310

 