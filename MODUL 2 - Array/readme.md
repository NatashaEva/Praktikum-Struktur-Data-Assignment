# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Tipe data adalah sebuah jenis nilai yang akan ditampung oleh sebuah variabel. Tipe data ini wajib ada ketika akan membuat sebuah variabel, agar variabel tersebut memiliki nilai yang spesifik. Dalam C++, tipe data terbagi menjadi tiga biagian, yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi.

### Tipe Data Primitif
Tipe data primmitif adalah tipe data dasar yang tidak diturunkan oleh tipe data lain. Contoh tipe data primiif antara lain :
 1. Int : tipe data ini digunakan untuk menyimpan data berbentuk angka bilangan bulat.
 2. Boolean : tipe data  untuk menyimpan data berbentuk boolean yang hasilnay benar atau salah.
 3. Float : tipe data  untuk menyimpan data berbentuk angka desimal.
 4. Char : tipe data untuk menyimpan berbentuk huruf. 

 ### Tipe Data Abstrak
 Tipe data abstrak adalah tipe data yang digunakan dalam fitur Object Oriented Program (OOP) dan mereferensikan objek 
atau kelas tertentu. 

### Tipe Data Koleksi

Tipe data koleksi adalah tipe data yang memungkinkan untuk menyimpan beberapa objek secara bersamaan. Contoh tipe data koleksi yaitu vector, array dan map.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream> 
using namespace std;
// Main Program
main()
{
    char op;
    float num1, num2;
    //It allows users to enter operator i.e. +, -, *, /
    cout << "Masukan operator: "; 
    cin>>op;
    //It allows user to enter operands
    cout << "Masukan angka 1 dan 2: ";
    cin >> num1 >> num2;
    //switch statement begins
    
    switch(op)
    {
  //if user enter +
  case '+':
     cout << num1 + num2;    break;
  // if user enter -
  case '-':
    cout << num1 - num2;
    break;
  //if user enter *
  case '*':
     cout << num1 * num2;
     break;
  // if user enter /
  case '/':
    cout << num1 / num2;
    break;
  // If the operator is other than +, -, *, /
  //error message will display
  default:
    cout<< "Error! operator is nor correct";
  } // switch statements end
  return 0;
}

```
Kode di atas merupakan sebuah bentuk kalkulator sederhana yang memungkinkan untuk melakukan operasi aritmatika dasar yaitu penjumlahan, pengurangan, perkalian, dan pembagian dengan memasukan angka yang diinginkan kedalam operator.

### 2.  Tipe Data Abstrak

```C++
#include <stdio.h>

struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1,mhs2;
    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
 Kode diatas digunakan untuk menyimpan dan menampilkan informasi mahasiswa seperti nama, alamat, dan umur dengan menggunkan variabel mhs1 dan mhs2. Kode ini menyimpan informasi mahasiswa di dalamnya, serta mengakses dan mencetak data tersebut dengan menggunakan fungsi printf.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
Kode diatas menjelaskan bagaimana mendeklarasikan dan menginisialisasi isi array dengan nilai dengan tipe data integer berjumlah 5 dan mencetak isi array dengan fungsi cout.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!


```C++
#include <iostream>

// Fungsi untuk menghitung BMI dengan menggunakan tipe data integer dan float
double hitungBMI(int berat, double tinggi) {
  // Rumus BMI: berat (kg) / (tinggi (m) * tinggi (m))
  return berat / (tinggi * tinggi);
}

int main() {
  int berat;
  double tinggi;

  // Meminta pengguna memasukkan berat (kg) dan tinggi (m)
  std::cout << "Masukkan berat Anda (kg): ";
  std::cin >> berat;

  std::cout << "Masukkan tinggi Anda (m): ";
  std::cin >> tinggi;

  // Menghitung BMI menggunakan fungsi hitungBMI
  double bmi = hitungBMI(berat, tinggi);

  // Menampilkan hasil BMI
  std::cout << "BMI Anda adalah: " << bmi << std::endl;

  // Menampilkan kategori BMI
  if (bmi < 18.5) {
    std::cout << "Anda termasuk ke dalam kategori Kurang Berat Badan" << std::endl;
  } else if (bmi < 25) {
    std::cout << "Anda termasuk ke dalam kategori Normal" << std::endl;
  } else if (bmi > 25) {
    std::cout << "Anda termasuk ke dalam kategori Kelebihan Berat Badan" << std::endl;
  } else {
    std::cout << "Anda termasuk ke dalam kategori Obesitas" << std::endl;
  }

  return 0;
}
```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/525a46a1-5ff8-4c21-a9dc-9f63f079f831)



Program diatas digunakan untuk menghitung indeks masa tubuh (BMI) dengan menggunakan tipe data primitif yaitu integer dan double, kemudian akan dikategorikan menurut hasil yang didapat. Tipe data integer digunakan untuk menyimpan data berat badan yang berbentuk bilangan bulat dan double untuk menyimpan data tinggi badan yang berbentuk desimal.  Tipe data primitif ini digunakan untuk menyimpan berbagai jenis data seperti bilangan bulat, bilangan desimal, karakter, dan lain-lain. Program di atas menunjukkan bagaimana tipe data primitif dapat digunakan untuk melakukan operasi aritmatika dan menampilkan hasil perhitungan.


### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya!

```C++
#include <iostream>

using namespace std;

class Grade {
public:
  string name;
  int nim;

  void printInfo() {
    cout << "Nama: " << name << endl;
    cout << "NIM: " << nim << endl;
  }
};

struct Matkul {
  string Matakuliah;
  string Kategorinilai;
};

int main() {
  // Membuat objek dari class nama dan nim
  Grade grade;
  grade.name = "Adi";
  grade.nim = 123456;

  // Membuat objek dari structure Matkul
  Matkul matkul;
  matkul.Matakuliah = "Algoritma dan Struktur Data";
  matkul.Kategorinilai = "A";

  // Mencetak informasi grade dan matkul
  grade.printInfo();
  cout << "Mata Kuliah: " << matkul.Matakuliah << ", " << matkul.Kategorinilai << " " << endl;

  return 0;
}
```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/635f0740-ca04-4714-a79c-b2d8a8469dc6)

Pada struct, secara default bersifat public atau dapat diakses dari mana saja maka kontrol terhdapat data kurang ketat dan digunakan ketika struktur data yang digunakan sederhana. Sedangkan pada class, secara default bersifat private atau hanya dapat diakses dari dalam class saja, class memungkinkan data dan fungsi dioperasikan menjadi satu bagian, dan class juga memungkinkan pengguna untuk membuat subclass dari class lain.



### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map!

```C++
#include <iostream>
#include <map>

using namespace std;

int main() {
  // Mendefinisikan map menggunakan tipe data string dan integer
  map<string, int> m;

  // Menambahkan elemen ke map berisi data berat badan
  m["Wawan"] = 65;
  m["Yani"] = 70;
  m["Jajang"] = 55;
  m["Meilani"] = 65;
  m["Karen"]  = 80;

  // Mencari elemen dalam map
  auto it = m.find("Jajang");
  if (it != m.end()) {
    cout << "Berat Badan Jajang: " << it->second << endl;
  } else {
    cout << "Data tidak ditemukan" << endl;
  }


  // Mencetak semua elemen map
  for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " : " << it->second << endl;
  }

  return 0;
}
```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/98485e13-9fc2-4b7b-93c7-b80c0fac6652)
Pada program diatas menggunakan tipe data int sebagai value dan string sebagai key. Dan ditambahkan 5 elemen ke map. Dan menggunakan fungsi find untuk mencari berat badan Jajang. Kemudian menggunakan perluangan berupa for.
Pada array, elemennya diakses menggunakan indeks yang dimulai dari 0, array biasanya hanya digunakan untuk menyimpan tipe data yang sama, ukuran array biasanya tidak dapat diubah setelah dilakukan deklarasi fungsi.
 Sedangkan pada map, elemennya diakses menggunakan key yang unik dan berbagai tipe data dan memungkinkan pengguna untuk mecari elemen tertentu tanpa mengetahui posisinya, urutan elemen dalam map tidak diurutkan dalam aturan penambahan dapat berbeda-beda, ukuran dalam map dapat diubah ubah seiring dengan penambahan dan penghapusan elemen.




## Kesimpulan
Kesimpulan dari materi tipe data yaitu, tipe data adalah fungsi pengelompokan data berdasarkan sifat data tersebut dan kegunaannya dalam program. Dan terdapat tiga tipe data yaitu, tipe data primitif merupakan tipe data dasar yang berisi data berbentuk int, float, string, dan boolean, tipe data abstrak yang memungkinkan pengguna memasukan banyak tipe data dengan fungsi struct ataupun class, tipe data koleksi yaitu tipe data yang memungkinkan menyimpan beberapa nilai dalam satu program secara bersamaan dengan array, vector, dan map.

## Referensi
[1]  Putri, MP, Barovih, G & Azdy, RA 2022, Algoritma Dan Struktur Data, Penerbit Widiana Bhakti Persada Bandung.

[2]  Dwi Putra, MT, Pradeka, D & Yuniarti, AR 2022, Belajar Dasar Pemrograman Dengan C++, Penerbit Widina.