# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Priority queue memiliki fungsi seperti queue biasa yang memungkinkan memasukan elemen, namun jenis queue ini memungkinkan elemen dengan prioritas tertinggi keluar terlebih dahulu [1]. Struktur  data ini menggunakan operasi  Insert  dan  DeleteMin (yang mengembalikan dan menghapus elemen minimum) atau DeleteMax (yang mengembalikan dan menghapus elemen maksimum). Operasi ini setara dengan operasi EnQueue dan DeQueue dari queue biasa. Perbedaannya adalah, dalam priority queue, urutan elemen yang masuk ke antrian mungkin tidak sama dengan saat elemen tersebut diproses [2]. 

Prioroty queue disebut priority queue naik, jika item dengan nilai terkecil memiliki prioritas  tertinggi  (artinya, hapus elemen terkecil selalu). Demikian pula, priority queue dikatakan sebagai priority queue menurun jika item dengan nilai terbesar memiliki prioritas tertinggi (selalu hapus elemen maksimum) [2].

Heap adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A, maka nilai yang tersimpan disimpul A lebih besar atau sama dengan nilai yang tersimpan disimpul B. Hal ini mengakibatkan elemen dengan nilai terbesar selalu berada pada posisi akar, dan heap ini disebut maxheap (bila perbandingannya diterbalikkan, yaitu elemen terkecilnya selalu berada disimpul akar,heap ini disebut adalah minheap). Karena itulah, heap biasa dipakai untuk mengimplementasikan priority queue [3]. 

Operasi-operasi yang digunakan untuk heap adalah [3]:

1.Delete-max atau delete-min: menghapus simpul akar dari sebuah max- atau minheap.

2.Increase-key atau decrease-key: mengubah nilai yang tersimpan disuatu simpul.

3.Insert: menambahkan sebuah nilai kedalam heap.

4.Merge: menggabungkan dua heap untuk membentuk sebuah heap baru yang berisi semua elemen pembentuk heap tersebut.
   


## Guided 


```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return(i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) +1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while(i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]) ;
        i = parent(i);
    }
}


void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H [maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <=heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}

```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/99b37f79-31c3-4df3-903f-c57c046a4ed5)



Kode diatas merupakan program heap yang digunakan untuk mempriotaskan elemen yang terbesar berdasarkan nilainya. Dalam program ini terdapat array H dengan ukuran maks 50 yang digunakan untuk menyimpan elemen - elemen. 

Program ini berjalan dengan fungsi fungsi yaitu fungsi parent(i) yang digunakan untuk menghitung dan mengembalikan indeks parent dari elemen yang di indeks i, fungsi leftChild(i) untuk menghitung dan mengembalikan indeks kiri elemen yang ada di indeks i,  fungsi rightChild(i) untuk mengembalikan indeks kanan dari elemen pada indeks i, fungsi shiftUp(i) untuk menukar elemen baru dengan parentnya kedepan secara berulang hingga mendapat posisi yang tepat(nilai lebih besar dari parent), fungsi shiftDown(i) untuk menukar elemen bila terdapat perubahan prioritas menjadi lebih rendah dengan elemen terbesar kebelakang secara berulang. 

Untuk membangun sebuah heap dibuat secara bertahap berulang ulang dengan fungsi insert untuk menambahkan elemen kedalam heap. Selanjutnya untuk pencarian elemen maksimum dengan fungsi getMax akan mengakses elemen dengan nilai terbesar sebagai prioritas. Lalu untuk pengambilan elemen maksimum dengan fungsi extractMax untuk menghapus elemen prioritas dari heap. Kemudian untuk penyisipan elemen dengan fungsi insert akan menambahkan elemen baru bersamaan dengan fungsi shiftUp untuk memastikan elemen tersebut berada diposisi yang tepat. Lalu untuk mengahapus elemen dengan fungsi remove untuk menghapus elemen tertentu dari Heap, prioritas elemen tersebut dinaikkan terlebih dahulu, kemudian fungsi shiftUp dan extractMax digunakan secara berurutan untuk memindahkan dan menghapus elemen tersebut. Dan untuk pengubahan elemen prioritas dengan fungsi changePriority untuk mengubah prioritas elemen yang sudah ada di dalam Heap, tergantung pada perubahan prioritas (naik atau turun), fungsi shiftUp atau shiftDown digunakan untuk mengembalikan sifat Max-Heap.




## Unguided 

#### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.


```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i + 1);
}

int rightChild(int i) {
    return (2 * i + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n, value;
    std::cout << "Enter the number of elements to insert into the heap: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int index, newPriority;
    std::cout << "Enter the index to change priority and new priority value: ";
    std::cin >> index >> newPriority;
    changePriority(index, newPriority);

    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Enter the index to remove: ";
    std::cin >> index;
    remove(index);

    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/716ba533-e3d0-4b1b-aa9a-63db0255bea9)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/51d7399e-0d80-4963-85a8-9ceea4159eb9)

Kode diatas merupakan program modifikasi struktur data heap dari guided no 1, program ini memungkinkan mengelola elemen berdasarkan prioritasnya sesuai data elemen yang dimasukan secara manual oleh user. Program ini memiliki kegunaan untuk menampilkan elemen setelah dilakukan beberapa operasi yaitu memasukan elemen, mengeluarkan elemen maksimum, mengubah prioritas elemen, dan menghapus elemen tertentu berdasarkan indeksnya. Program ini memiliki fungsi dan langkah algoritma yang sama dengan guided 1. Namun, pada program ini memungkinkan user memasukan elemen elemen yang diinginkan dengan cara memasukan jumlah elemen (n) ke dalam heap dahulu, maka akan dilakukan looping sebanyak n kali dan menggunakan 'value' untuk membaca nilai elemen elemen tersebut dan memasukannya kedalam heap dengan menggunakan fungsi insert, selanjutnya program akan melakukan operasi yaitu ekstrak elemene maksimum, mengubah prioritas elemen, dan menghapus elemen yang diinginkan.


 

## Kesimpulan

Priority queue memiliki fungsi seperti queue biasa yang memungkinkan memasukan elemen, namun jenis queue ini memungkinkan elemen dengan prioritas tertinggi keluar terlebih dahulu. Prioroty queue disebut priority queue naik, jika item dengan nilai terkecil memiliki prioritas  tertinggi  (artinya, hapus elemen terkecil selalu). Demikian pula, priority queue dikatakan sebagai priority queue menurun jika item dengan nilai terbesar memiliki prioritas tertinggi (selalu hapus elemen maksimum). Sedangkan heap adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A, maka nilai yang tersimpan disimpul A lebih besar atau sama dengan nilai yang tersimpan disimpul B.


## Referensi

[1] Bible, Paul W., and Moser, Lucas. An Open Guide to Data Structures and Algorithms. PALNI Press. 2023.

[2] Joseph Teguh Santoso. (2021). STRUKTUR DATA dan ALGORITMA (Bagian 1). Penerbit Yayasan Prima Agus Teknik, 7(1), 1-333.

[3] Tobing, FL, Tobing, FAT dan Peranginangin, J. (2022). Implementasi Algoritma Heapsort dalam Game Pembelajaran Algoritma Sorting. JURNAL WIDYA , [online] 3(2), hlm.331–343. 

‌
‌  
‌


‌

 