# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Antrean atau queue adalah salah satu konsep struktur data yang ditandai dengan tempat penyisipan/penambahan dan penghapusan elemen data yang berada di kedua ujung kumpulan data disebut front (bagian depan) dan rear (bagian belakang) [2], dan memiliki sistem kerja di mana yang pertama masuk maka akan menjadi yang pertama keluar (FIFO = first in first out), seperti halnya antrean yang terjadi dalam dunia nyata [1].

 Bagi yang pertama masuk antrian akan berada di posisi depan dilanjutkan oleh yang lain di posisi belakang, ketika elemen di depan meninggalkan antrian maka elemen selanjutnya akan bergeser satu posisi ke arah depan [2]. 

Jenis - jenis operasi dalam queue [2]:
1. queue(): Membuat queueu baru.
2. enqueue(item): Menambah data dalam queue, penambahan data selalu dilakukan dari bagian belakang (rear).
3. dequeue(): Menghapus data, selalu dilakukan dari bagian depan (front).
4. isEmpty(): Untuk mengetahui apakah queue dalam keadaan kosong atau tidak.
5. size(): Untuk mengidentifikasi jumlah data dalam queue. 

   


## Guided 


```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5; // deklarasi maksimal queue 5 elemen
int front = 0;
int back = 0;

string queueTeller[5]; 

bool isFull() { // Pengecekan ada isinya atau tidak 
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if(isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearqueue() {
    if (isEmpty()) {
        cout << "Antrian kososng" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewqueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << "." << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
 
int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewqueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewqueue();
    cout << "Jumlah antrian = " << countQueue << endl;
    clearqueue();
    viewqueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
} 


```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ff08ebc8-76ad-4d22-9c36-62f1d3e40298)


Kode diatas merupakan program antrian (queue) menggunakan array, dalam program ini memiliki beberapa fungsi yaitu fungsi isFull(): yang digunakan untuk memeriksa apakah antrian sudah penuh, fungsi isEmpty(): digunakan untuk memeriksa apakah antrian kosong, fungsi enqueueAntrian(string data): digunakan untuk menambahakan elemen baru dalam antrian, fungsi dequeueAntrian(): digunakan untuk menghapus dan memindahkane elemen sisa ke depan dalam antrian, fungsi countqueue(): digunakan untuk menghitung jumlah elemen dalam antrian, fungsi clearqueue(): digunakan untuk mengahapus semua elemen dalam antrian, dan fungsi viewqueue(): digunakan untuk mencetak isi antrian.




## Unguided 

#### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list !


```C++
#include <iostream>

using namespace std;

struct Node {
  string data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
    return;
  }

  Node* temp = front;
  front = front->next;
  delete temp;

  if (front == nullptr) {
    back = nullptr;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void clearqueue() {
  while (front != nullptr) {
    dequeueAntrian();
  }
}

void viewqueue() {
  cout << "Data antrian teller: " << endl;
  int i = 1;
  Node* current = front;
  while (current != nullptr) {
    cout << i << "." << current->data << endl;
    current = current->next;
    i++;
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewqueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearqueue();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}



```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/cc07f922-b4b7-4635-ab70-4fb1a19c24b0)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/ff506c25-60f3-4537-bbfd-3ee0c8483b90)

Kode diatas merupakan program antrian (queue) yang berbentuk linked list. Penggunaan linked list ditandai dengan penggunaan node dalam kode. Menggunakan variabel front sebagai pointer untuk menunjuk node pertama (depan) dalam antrian dan back sebagai pointer yang menunjuk ke node terakhir (belakang) dalam antrian. Pada program diatas terdapat beberapa fungsi diantaranya yaitu fungsi isEmpty untuk memeriksa apakah antrian kosong, fungsi enqueueAntrian untuk menambahkan elemen baru ke akhir antrian, dengan cara membuat node baru(newNode) kemudian mengisi node data dari node baru lalu mengatur node next daru node baru menjadi nullptr karena node terakhir. Fungsi dequeueAntrian untuk menghapus dan memindahkane elemen sisa ke depan dalam antrian, dengan memeriksa apakah antrian kosong. Jika kosong, pesan "Antrian kosong" dicetak, kemudian menyimpan node terdepan (front) dalam Node sementara (temp) lalu mengupdate front untuk menunjuk ke Node berikutnya (front->next) lalu menghapus Node sementara (temp) menggunakan delete. Fungsi countQueue untuk menghitung jumlah elemen dalam antrian, dengan menginisialisasi count menjadi 0 lalu membuat pointer sementara (current) yang menunjuk ke node terdepan (front) lalu melakukan loop selama current tidak nullptr lalu mengembalikan nilai count. Fungsi clearqueue untuk mengahpus semua elemen dalam antrian dengan melakukan looping pada dequeue() hingga antrian kosong. Fungsi viewqueue untuk mencetak isi anrian.


 
### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa !


```C++

#include <iostream>

using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
};

struct Node {
  Mahasiswa data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(Mahasiswa mahasiswa) { // Enqueue using Student struct
  Node* newNode = new Node;
  newNode->data = mahasiswa;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
    return;
  }

  Node* temp = front;
  front = front->next;
  delete temp;

  if (front == nullptr) {
    back = nullptr;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void clearqueue() {
  while (front != nullptr) {
    dequeueAntrian();
  }
}

void viewqueue() {
  cout << "Data antrian mahasiswa: " << endl;
  int i = 1;
  Node* current = front;
  while (current != nullptr) {
    cout << i << "." << "Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
    current = current->next;
    i++;
  }
}

int main() {
  Mahasiswa M1 = {"Natasha Eva Dwi Nurdiyanti", "2311110005"};
  Mahasiswa M2 = {"Eva", "231"};
  enqueueAntrian(M1);
  enqueueAntrian(M2);
  viewqueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearqueue();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}



```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/abbc6f86-a36b-49db-8f7d-0ca37262b31c)

### Full Code Screenshots :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/02246271-c7b4-4062-a230-8198a75f317a)

 
Kode diatas merupakan program queue(antrian) yang menggunakan linked list untuk menyimpan nama mahasiswa dan nim. Kode ini menyimpan informasi mahaisiswa menggunakan struct yang terdiri dari nama sebagai string yang menyimpan nama mahasiswa dan nim sebagai string yang menyimpan NIM mahasiswa, program ini menyimpan informasi mahasiswa dengan node data yang bernama Mahasiswa. Program ini memiliki fungsi isEmpty(): yang digunakan untuk memeriksa apakah antrian sudah kosong,  fungsi enqueueAntrian(string data): digunakan untuk menambahakan elemen baru dalam antrian, fungsi dequeueAntrian(): digunakan untuk menghapus dan memindahkane elemen sisa ke depan dalam antrian, fungsi countqueue(): digunakan untuk menghitung jumlah elemen dalam antrian, fungsi clearqueue(): digunakan untuk mengahapus semua elemen dalam antrian, dan fungsi viewqueue(): digunakan untuk mencetak isi antrian. Dan juga fungsi main untuk membuat objek Mahasiswa untuk dua mahasiswa yaitu M1 dan M2, menambahkan M1 dan M2 ke dalam antrian menggunakan enqueueAntrian, menampilkan isi antrian menggunakan viewqueue, menampilkan jumlah mahasiswa dalam antrian menggunakan countQueue, menghapus mahasiswa terdepan dari antrian menggunakan dequeueAntrian, menampilkan isi antrian setelah penghapusan, menampilkan jumlah mahasiswa setelah penghapusan, menghapus semua mahasiswa dari antrian menggunakan clearqueue, menampilkan isi antrian setelah penghapusan semua mahasiswa, menampilkan jumlah mahasiswa setelah penghapusan semua mahasiswa.


## Kesimpulan
Antrean atau queue adalah salah satu konsep struktur data yang ditandai dengan tempat penyisipan/penambahan dan penghapusan elemen data yang berada di kedua ujung kumpulan data disebut front (bagian depan) dan rear (bagian belakang), dan memiliki sistem kerja di mana yang pertama masuk maka akan menjadi yang pertama keluar (FIFO = first in first out). Jenis - jenis operasi dalam queue yaitu queue(), enqueue(item):, dequeue():, isEmpty():, size():.


## Referensi

[1] Mudah C, Algoritma M, Data D. Ade Mulyana, dkk 

[2] Hidayah AK, Alam RG, Prihandoko P. STRUKTUR DATA DENGAN PYTHON [Internet]. Buku Google. PT. Penerbitan Sonpedia Indonesia; 2023 
‌


‌

 