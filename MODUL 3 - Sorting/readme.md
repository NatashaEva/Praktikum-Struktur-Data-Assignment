# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Sorting adalah proses pengurutan data yang sebelumnya disusun secara acak atau tidak teratur menjadi urut dan teratur menurut aturan tertentu. Sorting dibagi menjadi dua yaitu[1]; 

Ascending : Pengurutan karakter atau angka kecil ke karakter atau angka yang lebih besar[1].

Descending : Pengurutan karakter atau angka yang besar ke karakter atau angka yang lebih kecil[1].

1. Selection Sorting

Metode   selection   sort   adalah   melakukan pemilihan  dari  suatu  nilai  yang  terkecil  dan kemudian    menukarnya    dengan    elemen paling  awal,  lalu  membandingkan  dengan elemen    yang    sekarang    dengan    elemen berikutnya  sampai  dengan  elemen  terakhir, perbandingan  dilakukan  terus  sampai  tidak ada lagi pertukaran data [1].

2. Bubble Sorting

Bubble  Sort merupakan  metode yang mana akan  mengulang  proses  pembandingan  antara tiap-tiap  elemen  array  dan  menukarnya  apabila  urutannya  salah.  Pembandingan  elemen-elemen  ini  akan  terus  diulang hingga tidak perlu dilakukan penukaran lagi [2].

3. Insertion Sort

Algoritma insertion sort, adalah metode pengurutan dengan cara menyisipkan elemen data pada posisi yang tepat Pencarian posisi yang tepat dilakukan dengan melakukan
pencarian berurutan didalam barisan elemen, selama pencarian posisi yang tepat dilakukan pergeseran elemen [3].


## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan algoritma bubble sort

```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){ //void = function bukan utama yg gada return nya
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; j++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i]; //temporary variable
                arr[i]= arr[i + 1]; 
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/e9fc967c-6ea7-4671-8b4a-b7e7c683a265)


Kode di atas merupakan program pengurutan bubble sorting bilangan desimal bertipe double secara ascending yang berjumlah 5 elemen. Program diatas terdiri 3 variabel yaitu variabel bool untuk menandai apakah pengurutan sudah selesai, variabel int untuk melacak looping, dan variabel double yang merupakan variabel sementara untuk menyimpan nilai saat melakukan penukaran. Program ini akan terus menerus melakukan perulangan hingga urutan yang dihasilkan telah sesuai.

### 2.  Mengurutkan karakter secara descending menggunakan algoritma insertion sort

```C++
#include <iostream>
 // Quadratic time complexity
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;
        
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }// end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {
    
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
    }
```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4a0665a9-88b0-492a-a9b7-4b872402d4ee)


 Kode diatas digunakan untuk mengurutkan data bertipe karakter secara descending menggunakan algoritma insertion sort. Program ini akan melakukan looping untuk memindahkan elemen kedalam urutan yang benar, jika elemen saat ini lebih kecil dari elemen sebelumnya maka akan melakukan proses penukaran hingga semua elemen telah berurutan.



## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!


```C++
#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int n = 5; // Jumlah mahasiswa
  float ips[n] = {3.8, 2.9, 3.3, 4.0, 2.4}; // Array IPS
  int i, j, min, temp;

  // Looping untuk mengurutkan IPS
  for (i = 0; i < n - 1; i++) {
    min = i; // Indeks minimum saat ini
    for (j = i + 1; j < n; j++) {
      // Mencari nilai minimum dalam array
      if (ips[j] > ips[min]) {
        min = j;
      }
    }

    // Menukar nilai minimum dengan nilai di indeks i
    if (min != i) {
      temp = ips[i];
      ips[i] = ips[min];
      ips[min] = temp;
    }
  }

  // Menampilkan hasil pengurutan
  cout << "IPS mahasiswa dari terbesar hingga terkecil: " << endl;
  for (i = 0; i < n; i++) {
    cout << ips[i] << " ";
  }

  cout << endl;

  return 0;
}
```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/9013fd79-c442-4d5e-93e5-e9032f08e2fa)



#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5bdda1fe-eb76-4c94-82b9-bd1ab52020a0)

Program diatas menggunakan algoritma selection sort untuk mengurutkan nilai IPS mahasiswa. Algoritma ini bekerja dengan cara mencari nilai terkecil dalam array kemudian menukarnya dengan nilai di indeks awal, proses penukaran ini dilakukan secara berulang ulang hingga elemen array telah berurutan. Program ini memiliki variabel ips yang digunakan untuk menyimpan nilai IPS mahasiswa sebanyak n elemen, variabel temp digunakan sebagai penyimpan sementara, variabel min sebagai indeks minimum saat ini, dan variabel i dan j sebagai variabel loop. Proses looping for pertama mengulang dari 0 hingga n-1, disini min akan diinisialisasi dengan nilai i. Kemudia
 looping for kedua akan mengulang i+1 hingga n, disini nilai paling kecil dalam array akan dicari dengan membandingkan ips[j] dengan ips[min]. Jika ips[j] lebih besar dari ips[min] maka min akan diperbarui dengan nilai j.


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!


```C++
#include <iostream>
#include <string>

using namespace std;

void bubble_sort(string nama[], int n) {
  bool not_sorted = true;
  int j = 0;
  string tmp;

  while (not_sorted) {
    not_sorted = false;
    j++;
    for (int i = 0; i < n - j; i++) {
      if (nama[i] > nama[i + 1]) {
        tmp = nama[i];
        nama[i] = nama[i + 1];
        nama[i + 1] = tmp;
        not_sorted = true;
      }
    }
  }
}

void print_array(string nama[], int n) {
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;
}

int main() {
  // Deklarasi variabel
  int n = 10; // Jumlah warga
  string nama[n] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Menampilkan nama warga sebelum sorting
  cout << "Urutan nama warga Pak RT sebelum sorting: " << endl;
  print_array(nama, n);

  // Mengurutkan nama warga
  bubble_sort(nama, n);

  // Menampilkan nama warga setelah sorting
  cout << "Urutan nama warga Pak RT setelah sorting: " << endl;
  print_array(nama, n);

  return 0;
}

```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/de47b33f-8f6c-4fd2-82dd-8bacb40c52fe)


### Full code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/16e4a1f1-c0f3-4aec-b19b-01bdf0a37756)


Program diatas digunakan untuk mengurutkan nama warga Pak RT sesuai alfabet A-Z menggunakan bubble sorting. Algoritma bublle sort dilakukan berulang kali dengan membandingkan elemen elemen yang berdekatan dan menukarnya jika tidak sesuai. Program ini memiliki variabel boolean not_sorted yang diinisialisasi dengan true yang menandakan bahwa pengurutan belum selesai, variabel integer j diinisialisasi dengan 0 untuk melacak perulangan loop, dan variabel string tmp digunakan untuk menyimpan data sementara ketika melakukan perulangan elemen. Proses looping pada program ini dimulai pada looping for dijalankan dengan mengulang indeks 0 hingga n-j-1, proses ini untuk membandingkan elemen elemen yang berdekatan, kecuali elemen yang sudah terurut. Selanjutnya memeriksa apakah elemen nama[i] lebih besar secara alfabet daripada elemen berikutnya nama[i+1]. Jika elemen tidak berurutan maka elemen akan ditukar dengan menggunakan variabel tmp = nama[i] untuk menyimpan elemen, kemudian nama[i] = nama[i+1] untuk memindahkan elemen berikutnya ke elemen saat ini.




### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/7858a494-5bdf-4519-84d8-11b1a851c7ca)


```C++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  // Deklarasi variabel
  int n;
  vector<char> karakter;

  // Meminta user untuk memasukkan jumlah karakter
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Meminta user untuk memasukkan n karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    karakter.push_back(c);
  }

  // Sorting ascending
  sort(karakter.begin(), karakter.end());

  // Menampilkan hasil sorting ascending
  cout << "Urutan karakter setelah ascending sort: ";
  for (char c : karakter) {
    cout << c << " ";
  }
  cout << endl;

  // Sorting descending
  sort(karakter.rbegin(), karakter.rend());

  // Menampilkan hasil sorting descending
  cout << "Urutan karakter setelah descending sort: ";
  for (char c : karakter) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}

```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/150c153d-67dc-411e-8a13-56b2b602378c)


### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4988091a-1dc6-435e-8b76-6335ee9fd223)



Program diatas digunakan untuk mengurutkan data karakter secara ascending dan descending. Algoritma program ini berkerja dengan membandingkan elemen yang berdekatan dan menukarnya jika tidak berurutan, dan proses ini dilakukan secara terus menerus hingga mendapatkan data yang diinputkan terurut. Program ini akan meminta user untuk memasukan jumlah karakter n dan memasukannya satu persatu kemudian disimpan dalam karakter. 



## Kesimpulan
Kesimpulan dari materi ini Sorting adalah proses pengurutan data yang sebelumnya disusun secara acak atau tidak teratur menjadi urut dan teratur menurut aturan tertentu. Sorting dibagi menjadi dua yaitu ascending adalah pengurutan karakter atau angka kecil ke karakter atau angka yang lebih besar, dan descending yaitu pengurutan karakter atau angka yang besar ke karakter atau angka yang lebih kecil. Metode dalam pengurutan yaitu metode   selection   sort   adalah   melakukan pemilihan  dari  suatu  nilai  yang  terkecil  dan kemudian    menukarnya    dengan    elemen paling  awal,  lalu  membandingkan  dengan elemen    yang    sekarang    dengan    elemen berikutnya, bubble  Sort merupakan  metode yang mana akan  mengulang  proses  pembandingan  antara tiap-tiap  elemen  array  dan  menukarnya  apabila  urutannya  salah, insertion sort adalah metode pengurutan dengan cara menyisipkan elemen data pada posisi yang tepat Pencarian posisi yang tepat dilakukan dengan melakukan
pencarian berurutan didalam barisan elemen, selama pencarian posisi yang tepat dilakukan pergeseran elemen.

## Referensi

[1] Syahputra, A. 2022. IMPLEMENTASI ALGORITMA SELECTION SORT UNTUK PENGURUTAN NILAI IPK MAHASISWA UNIVERSITAS POTENSI UTAMA. JTIK (Jurnal Teknik Informatika Kaputama). 6, 2 (Jul. 2022), 390–396.
‌

[2] A. B. Panggabean, R. R. Htb, I. Perina, Y. L. Toro, and A. Syahputra, “Implementasi Algoritma Bubble Sort pada Sistem Pelayanan Perpustakaan Menggunakan Laravel”, sudo j. Teknik inform., vol. 2, no. 1, pp. 19–27, Jan. 2023. 

[3] Retnoningsih E. 2018. Algoritma Pengurutan Data (Sorting) Dengan Metode Insertion Sort dan Selection Sort. Information Management For Educators And Professionals. 3 (1): 95 - 106. 

 