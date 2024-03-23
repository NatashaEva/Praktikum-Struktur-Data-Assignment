# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama[3]. Array dibagi menjadi beberpa jenis yaitu :

1. Array Satu Dimensi

Array satu dimensi adalah kumpulan elemen-elemen yang identik yang mana tersusun dalam satu baris, dapat disebut juga dengan istilah vektor yang mengambarkan data dalam suatu urutan[3]. Contohnya yaitu int A[5]; 

2. Array Dua Dimensi

Array dua dimensi merupakan suatu kumpulan elemen yang dapat melakukan penyimpanan secara terurut yang terbagi menjadi 2 unsur yakni baris dan kolom elemen yang bertipe sama[1]. Dan sering disebut dengan istilah matriks[3]. Contohnya yaitu int A[2][4]; 

3. Array Multidimensi

Array multidimensi ini seperti array dua dimensi namun memiliki ukuran yang lebih besar dan jumlah dimensinya berbeda[4]. Contohnya yaitu int A[2][8][8];

4. Array Empat Dimensi

Contohnya yaitu int A[2][6][5];

5. Array Lima Dimensi

Contohnya yaitu intA[2][7][3][4][8];

## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream> 
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    //input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)  // dimensi array paling dalam tidak bisa melihat array luar
            {
                cout << "input Array[" << x <<"][" << y << "][" << z << "] = ";
                cin >> arr [x][y][z];
            }
        }
        cout << endl;
    }
    //output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0;z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    //Tampilan Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y< 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}

```
Kode di atas merupakan program yang menghasilkan sebuah array tiga dimensi, array tiga dimensi dapat digunakan untuk menyimpan dan menampilkan data bilangan bulat dalam struktur seperti matriks yang elemennya lebih kompleks daripada array satu atau dua dimensi.

### 2.  Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main()
{
    // deklarasi variabel
    int maks, a, i = 1, lokasi;
    // masukan data
    cout << "Masukan panjang array: ";
    cin >> a;
    int *array = new int[a];
    cout << "Masukan " << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
 Kode diatas digunakan untuk mencari nilai maksimum pada sebuah elemen array. Program diatas menggunakan variabel maks untuk menyimpan nilai maksimum pada array dan variabel lokasi untuk menyimpan lokasi elemen dengan nilai maksimum tersebut



## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/9e339e83-7788-45a8-82ff-ed1362c9e8b6)



```C++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> data;
    int n;

    std::cout << "Masukkan jumlah elemen array: ";
    std::cin >> n;

    std::cout << "Masukkan " << n << " bilangan bulat:" << std::endl;
    
    for(int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        data.push_back(x);
    }

    std::cout << "Data Array: ";
    
    for(int i = 0; i < data.size(); ++i) {
        std::cout << data[i] << ' ';
    }

    std::cout << "\nNomor Genap: ";
    
    for(int i = 0; i < data.size(); ++i) {
        if(data[i] % 2 == 0) {
            std::cout << data[i] << ' ';
        }
    }

     std::cout << "\nNomor Ganjil: ";
     
     for(int i = 0; i < data.size(); ++i) {
         if(data[i] % 2 != 0) {
             std::cout << data[i] << ' ';
         }
     }

     return 0;
}

```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5de73205-76dc-4dbd-a8d6-481fc1235e6a)


#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/08a8bcae-fdd8-4f99-8fbe-3353cefad462)

Program diatas menggunakan struktur data vector untuk menyimpan bilangan bulat. Memasukkan jumlah elemen dalam array yang akan disimpan menggunakan variable integer n.
Memasukkan bilangan bulat sebanyak elemen yang diminta menggunakan variabel data. Menampilkan seluruh isi array yang dimasukkan dengan melakukan perulangan for. Memisahkan nomor genap dengan cara menggunakan operator % 2 ==0, sedangkan nomor ganjil dengan cara menggunakan operator % 2  != 0 dari data array.



### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!


```C++
#include <iostream>
#include <vector>

int main() {
    int x, y, z;

    std::cout << "Masukkan jumlah elemen pada dimensi pertama: ";
    std::cin >> x;
    std::cout << "Masukkan jumlah elemen pada dimensi kedua: ";
    std::cin >> y;
    std::cout << "Masukkan jumlah elemen pada dimensi ketiga: ";
    std::cin >> z;

    // Inisialisasi array tiga dimensi
    std::vector<std::vector<std::vector<int>>> data(x, std::vector<std::vector<int>>(y, std::vector<int>(z)));

    std::cout << "Masukkan " << x * y * z << " bilangan bulat:" << std::endl;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                std::cin >> data[i][j][k];
            }
        }
    }

    std::cout << "Array Tiga Dimensi yang Diinputkan:" << std::endl;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                std::cout << "data[" << i << "][" << j << "][" << k << "] = " << data[i][j][k] << std::endl;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                std::cout << data[i][j][k] << std::ends;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/8ee48e28-908b-4595-9445-88a0319421b5)

### Full code Screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/9371d1b3-a98f-4b15-a527-733de3446288)


Program diatas digunakan untuk membuat array 3 dimensi yang memungkinkan user untuk memasukan jumlah dan ukuran elemen array nya sendiri. Variabel x,y,z merupakan variabel integer untuk menyimpan jumlah elemen setiap dimensi. Indeks elemen array diinisialisasi dengan i,j,k.



### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen array ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        total += arr[i];
    }

    float average = total / n;

    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai rata-rata: " << average << endl;

    return 0;
}

```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/14ed65bb-09af-4588-a7a5-705f218c9dc7)


### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/04e8e826-4cb2-4e83-a800-17dc5cf3c036)



Program diatas digunakan untuk mencari nilai maksimum, nilai minimum, dan nilai rata rata elemen array yang telah diinputkan oleh user.  Program ini akan meminta user untuk memasukan jumlah elemen array dan disimpan dalam variabel n, dan akan dideklarasikan dengan arr yang memiliki kapasitas 100 elemen. Variabel max digunakan untuk menyimpan nilai maks awal, variabel min digunakan untuk menyimpan nilai minimum awal, dan variabel total digunakan untuk menyimpan jumlah seluruh elemen untuk perhitungan rata rata. Kemudian akan membandingkan elemen arr[i] dengan max,min,dan total. 



## Kesimpulan
Kesimpulan dari materi ini array merupakan suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Array dapat berupa satu dimensi adalah kumpulan elemen-elemen yang identik yang mana tersusun dalam satu baris, dua dimensi merupakan suatu kumpulan elemen yang dapat melakukan penyimpanan secara terurut yang terbagi menjadi 2 unsur yakni baris dan kolom elemen yang bertipe sama, multidimensi mirip seperti array dua dimensi namun memiliki ukuran yang lebih besar dan jumlah dimensinya berbeda, empat dimensi, dan lima dimensi. 

## Referensi

[1]P. Afrizal et al., “Universitas Pamulang Sistem Informasi S-1 i Algoritma dan Struktur Data ALGORITMA DAN STRUKTUR DATA.” 
‌

[2] J. nasir et al., Algoritma dan Struktur Data dengan Pemograman Pascal dan Phyton. CV. Gita Lentera, 2024. 

[3] Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. 

[4] lestari, K. (2019, March 29). STUKTUR DATA STATIS ARRAY. 