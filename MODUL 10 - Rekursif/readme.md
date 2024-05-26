# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Rekursi adalah konsep yang mendasari banyak algoritma
dalam ilmu komputer. Secara sederhana, rekursi adalah kemampuan sebuah fungsi untuk memecah masalah menjadi sub-masalah yang lebih kecil. Fungsi tersebut kemudian memanggil dirinya sendiri untuk menyelesaikan sub-masalah tersebut. Prinsip ini mencerminkan cara yang seringkali memecahkan masalah dalam kehidupan seharihari, dengan membaginya menjadi bagian-bagian yang lebih kecil dan lebih mudah dikelola. Ini adalah ciri khas dari rekursi - memecah masalah menjadi versi yang lebih sederhana dari masalah itu sendiri. Rekursi memiliki daya ungkit yang kuat dalam mengekspresikan ide ide dan algoritma yang kompleks. Ia memberikan cara berpikir yang berbeda dalam menghadapi masalah, dengan melihatnya dari sudut pandang yang lebih abstrak [3]. 

Metode rekursif adalah metode yang secara langsung atau tidak langsung memanggil dirinya sendiri [1]. Oleh karena itu, algoritma rekursif harus dinyatakan dalam prosedur atau fungsi karena hanya prosedur atau fungsi yang dapat dipanggil dalam sebuah program[2]. Kata rekursif berarti 'memiliki karakteristik untuk datang kembali atau mengulangi' [1]. 

Badan fungsi rekursif disusun oleh dua bagian yaitu basis dan rekurens. Basis adalah bagian yang berisi proses yang memberikan sebuah nilai definitif pada fungsi rekursif, pada bagian ini menghentikan fungsi rekursif. Dan rekurens adalah bagian yang mendefinisikan nilai dalam terminologi dirinya sendiri. Bagian ini akan memanggil diri sendiri dengan nilai input yang lebih sedikit atau lebih sederhana[2]. 

Rekursif memiliki dua jenis yaitu rekursif langsung dan tidak langung. Rekursif langsung adalah fungsi yang secara langsunng memanggil dirinya sendiri, sedangkan rekursif tidak langsung terjadi ketika fungsi A memanggil fungsi B, dan fungsi B memanggil kembali fungsi A [1]. 

Pemrograman rekursif ini memilki beberapa kelebihan dan kekurangan. Kelebihan program ini yaitu program ini menyediakan cara yang sederhana dalam penulisan kode program, sedangkan untuk kekurangan program ini yaitu program ini memiliki persyaratan ruang dan waktu yang besar [1].
   


## Guided 1


```C++
// Rekursi Langsung
#include <iostream> 

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}


```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/85eee202-4d6a-45a4-81cb-194b67d39673)



Kode diatas meruapan program rekursi berjenis rekursi langsung (direct recursion) yang digunakan untuk menampilkan urutan angka mundur dari nilai awal yang telah ditentukan.

Program ini mendefinisikan fungsi countdown untuk memeriksa kondisi if (n == 0) apakah nilai n sama dengan 0, jika iya maka fungsi ini akan langsung keluar, yang menandakan proses countdown telah selesai. Fungsi ini juga berguna untuk menampilkan bilangan dan memanggil diri sendiri. Proses ini akan terus berulang hingga mencapai nilai 0.


## Guided 2

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif tidak langsung:  ";
    functionA(num);
    return 0;
}


```

### Output 
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/d9284473-27f2-4397-ad7f-a1e121a1e7d3)


Kode diatas merupakan sebuah program rekursi tidak langsung (indirect recursion) yang dimana dua fungsi saling memanggil satu sama lain.

Program ini mendefinisikan dua fungsi yaitu 'functionB' dan 'functionA'. Fungsi 'functionB' untuk kondisi if (n > 0), apabila terpenuhi maka akan mencetak nilai n dan memanggil fungsi 'functionA' secara rekursif dengan parameter n/2. Kemudian untuk fungsi 'functionA' untuk kondisi if(n > 0), apabila terpenuhi maka akan mencetak nilai n kemudian akan memanggil fungsi 'functionB' secara rekursif dengan parameter n - 1. Proses pemanggilan ini akan bergantian hingga n mencapai 0 pada salah satu fungsi. 




## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!



```C++
#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Harap masukkan bilangan bulat positif!" << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    }

    return 0;
}


```


#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/a7502b38-6aca-4bcc-86a2-18f5036ad30c)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/13bd4392-f3ef-4a89-9717-6b5e32c2e85d)


Kode diatas merupakan program rekursif langsung yang digunakan untuk menghitung nilai faktorial dari sebuah bilangan positif yang diinputkan user.

Program ini mendefinisikan 'faktorial' untuk menghitung nilai faktorial n menggunakan rekursi. Fungsi ini digunakan oleh kondisi if (n == 0), apabila kondisi ini  terpenuhi maka nilai faktorial 0 didefinisikan sbg 1. Jika tidak terpenuhi maka fungsi menghitung faktorial dengan mengalikan n dengan faktorial n - 1.




 ### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!


```C++
#include <iostream>

using namespace std;

// Deklarasi fungsi
int faktorialA(int n);
int faktorialB(int n);

// Fungsi faktorialA memanggil faktorialB
int faktorialA(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorialB(n - 1);
    }
}

// Fungsi faktorialB memanggil faktorialA
int faktorialB(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorialA(n - 1);
    }
}

int main() {
    int n;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Harap masukkan bilangan bulat positif!" << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorialA(n) << endl;
    }

    return 0;
}
```

#### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/a7502b38-6aca-4bcc-86a2-18f5036ad30c)

#### Full Code Screenshots
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/42d43830-d2c7-4fc8-9cbe-5824ff0755ba)


Kode diatas merupakan program rekursif tidak langsung yang digunakan untuk menghitung nilai faktorial dari bilangan positif yang diinputkan user.

Dalam program ini didefinisikan fungsi 'faktorialA' dan fungsi 'faktorialB' yang akan saling memanggil. Fungsi 'faktorialA' digunakan untuk menghitung nilai faktorial n, fungsi ini menggunakan kondisi if (n == 0), apabila kondisi ini terpenuhi maka nilai faktorial 0 didefinisikan sebagai 1. Namun apabila tidak terpenuhi maka fungsi ini akan menghitung faktorial dengan mengalikan n dengan faktorial  n - 1. Untuk fungsi 'faktorialB' memiliki struktur yang sama dengan fungsi 'faktorialA', fungsi ini akan menghitung faktorial dengan mengalikan n dengan faktorial dari n - 1, kemudian akan melakukan pemanggilan rekursif dengan mengalikan 'faktorialA' dengan n - 1.




## Kesimpulan

Metode rekursif adalah metode yang secara langsung atau tidak langsung memanggil dirinya sendiri. Badan fungsi rekursif disusun oleh dua bagian yaitu basis dan rekurens. Basis adalah bagian yang berisi proses yang memberikan sebuah nilai definitif pada fungsi rekursif, pada bagian ini menghentikan fungsi rekursif. Dan rekurens adalah bagian yang mendefinisikan nilai dalam terminologi dirinya sendiri. Bagian ini akan memanggil diri sendiri dengan nilai input yang lebih sedikit atau lebih sederhana. Rekursif memiliki dua jenis yaitu rekursif langsung dan tidak langung. Rekursif langsung adalah fungsi yang secara langsunng memanggil dirinya sendiri, sedangkan rekursif tidak langsung terjadi ketika fungsi A memanggil fungsi B, dan fungsi B memanggil kembali fungsi A. Pemrograman rekursif ini memilki beberapa kelebihan dan kekurangan. Kelebihan program ini yaitu program ini menyediakan cara yang sederhana dalam penulisan kode program, sedangkan untuk kekurangan program ini yaitu program ini memiliki persyaratan ruang dan waktu yang besar.

## Referensi

[1] Shofwan Hanief. M.T S. Kom and I. Wayan Jepiara. M.Cs S. Kom, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi, 2020.

[2] Riyanto, Joko and Yanti, Fitri and Santoso, Bambang and Syaripudin, Ari (2022) ALGORITMA DAN PEMROGRAMAN 2.

[3] Purbasari, Wika, et al. ALGORITMA PEMROGRAMAN. Edited by Setiya Putra, Yusuf W., and Hanson P. Putro, CV WIDINA MEDIA UTAMA, 2024.


‌
‌  
‌


‌

 