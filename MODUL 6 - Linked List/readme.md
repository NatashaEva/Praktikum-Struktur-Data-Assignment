# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

### Single Linked List
Linked list ini merupakan struktur data yang terdiri dari
rantaian elemen sejenis yang saling berhubungan. Setiap elemen memiliki pendahulu dan penerusnya ,kecuali elemen terakhir [1]. Pengelolaan memori secara dinamis artinya tidak perlu mengalokasi memori lebih awal secara tetap [2]. 

### Double Linked List
Salah satu kelemahan single linked list adalah pointer
(penunjuk) hanya dapat bergerak satu arah, yaitu maju/mundur
atau kanan/kiri sehingga pencarian data pada single linked
list hanya dapat bergerak dalam satu arah. Untuk mengatasi
kelemahan ini, kita bisa menggunakan metode double linked
list. Linked list ini dikenal dengan nama linked list berpointer ganda atau double linked list, pointernya yaitu prev yang digunakan untuk menggeser mundur selain itu juga tetap mempertahankan pointer next. [2].

### Linked List Non-Circular
Linked list Setiap nodenya pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat
pembacaan isi linked list.

   
### Linked List Circular
Linked lis circular adalah linked list dimana node node yang  terhubung seperti lingkaran. Dalam linked list circular, node pertama dan node terakhir terhubung satu sama lain atau tidak memiliki akhir. List yang berbentuk circular dengan head/first sebagai penunjuk awal list dan akan diteruskan dengan obyek-obyek yang saling berhubungan, diakhiri dengan tail/ last sebagai penunjuk akhir list. Bedanya akhir list akan memiliki referensi yang akan menunjuk kembali ke awal list (head/first) dan atau head/first pun akan memiliki referensi yang menunjuk bahwa data sebelumnya adalah tail/last list.


## Guided 

### 1. Latihan Single Linked List 

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}


```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/29eb23f3-27e4-4330-9acc-6b2a50bc5595)


Kode diatas merupakan program single linked list yang digunakan untuk penambahan data bertipe integer di depan dan belakang, penghapusan data di depan, belakang, dan tengah, pengubahan data di depan, belakang, dan tengah, serta penghapusan semua data dan menampilkan isi list. Dalam program ini menggunakan Variabel head dan tail digunakan untuk menunjukkan node pertama dan terakhir dalam linked list. Pada program ini terdapat beberpaa fungsi yaitu fungsi insert depan, belakang, dan tengah  digunakan untuk menambahkan node baru di depan, belakang, dan tengah  list pada posisi yang ditentukan, fungsi hapus depan, belakang, dan tengah digunakan untuk menghapus node pertama, terakhir, dan tengah pada posisi yang ditentukan, fungsi ubah depan, belakang, da tengah  digunakan untuk mengubah nilai data dari node pertama, terakhir, dan tengah list pada posisi yang ditentukan.

### 2. Latihan Double Linked List 


```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}


```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/6a266517-fdca-45ca-a00b-503d4f1031f0)


 Kode diatas merupakan program double linked list yang digunakan untuk menambah, menghapus, mengubah, menampilkan, dan membersihkan data di dalamnya. Dalam program ini terdapat beberapa fungsi yaitu fungsi push() digunakan untuk menambahkan sebuah node di depan linked list, fungsi pop() digunakan untuk menghapus node pertama dari linked list, fungsi update() digunakan untuk mengubah nilai data dari node 'oldData' dengan nilai data baru 'newData', fungsi deleteAll() digunakan untuk menghapus semua node dari linked list. 

### 3. Single Linked List Circular


```C++
#include <iostream>
using namespace std;

///Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; //true
    else
        return 0; //false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu -> next;
    }

    return jumlah;
}

// Tambah depan
void insertDepan(string data) {
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah belakang
void insertBelakang(string data) {
    //Buat Node Baru
    buatNode(data);

    if(isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if(hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }
            
            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong !" << endl;
    }
}

//Hapus tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering 
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor ++;
        } 

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong! " << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil dihapus !" << endl; 
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong !" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/32eab6d6-592f-47e5-99ca-04106d253957)



Kode diatas merupakan program single linked list circular yang digunakan untuk menambahkan, menghapus, dan menampilkan data bertipe string. Pada program ini terdapat beberapa fungsi yaitu fungsi insert depan, belakang, dan tengah yang digunakan untuk menambah data baru didepan, belakang, atau tengah list, fungsi hapus depan, belakang, dan tengah yang digunakan untuk menghapus data didepan, belakang ataupun ditengah list, fungsi clear list yang digunakan untuk menghapus keseluruhan node dalam list, dan fungsi tampil yang digunakan untuk menampilkan seluruh data dalam list.  




## Unguided 

### Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

#### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa


```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string nama;
    int nim;
    Node* next;
};

// Class LinkedList
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di depan
    void tambahDepan(string nama, int nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data di belakang
    void tambahBelakang(string nama, int nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanData() {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus data di awal
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Fungsi untuk menghapus data di akhir
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Fungsi untuk menghapus data sesuai posisi
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        if (posisi == 1) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; i < posisi - 2; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Fungsi untuk mengubah data sesuai posisi
    void ubahData(int posisi, string namaBaru, int nimBaru) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            temp = temp->next;
        }
        temp->nama = namaBaru;
        temp->nim = nimBaru;
    }
};

int main() {
    LinkedList list;
    int opsi;

    do {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Hapus Tengah" << endl;
        cout << "6. Ubah Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> opsi;

        switch (opsi) {
            case 1: {
                string nama;
                int nim;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            }
            case 2: {
                string nama;
                int nim;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            }
            case 3: {
                list.hapusDepan();
                cout << "Data di depan berhasil dihapus" << endl;
                break;
            }
            case 4: {
                list.hapusBelakang();
                cout << "Data di belakang berhasil dihapus" << endl;
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                list.hapusTengah(posisi);
                cout << "Data berhasil dihapus" << endl;
                break;
            }
            case 6: {
                int posisi;
                string namaBaru;
                int nimBaru;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                cout << "Masukkan nama baru : ";
                cin >> namaBaru;
                cout << "Masukkan NIM baru : ";
                cin >> nimBaru;
                list.ubahData(posisi, namaBaru, nimBaru);
                cout << "Data berhasil diubah" << endl;
                break;
            }
            case 7: {
                list.tampilkanData();
                break;
            }
            case 0: {
                cout << "Program selesai" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (opsi != 0);

    return 0;
}

```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4d9c3c55-79c5-472b-be53-6b1f29c2ca98)


#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/8a579a70-3ec6-40df-8159-8f21f8460f5e)

Kode diatas merupakan program single linked non-circular yang digunakan untuk menyimpan data nama serta nim mahasiswa yang mana dapat menambahkan data baru, menghapus data, mengubah data serta menampilkan data. Program ini memiliki beberapa fungsi yaitu fungsi tambahDepan dan tambahBelakang yang digunakan untuk menambahkan data diawal dan dibelakang list, fungsi hapusDepan, hapusBelakang dan hapusTengah yang digunakan untuk menghapus data didepan, dibelakang ataupun pada posisi tertentu dalam list, fungsi tampilkanData yang digunakan untuk menampilkan keseluruh data dalam list, kemudian fungsi ubahData yang digunakan untuk mengubah data berdasarkan posisi tertentu dalam list. 

 
### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan.

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/22026e60-8791-40b2-b2b1-fad0d6a28e4b)
 
Output diatas merupakan data yang telah dimasukan kedalam list menggunakan kode program di no 1 yang kemudian dijalankan kemudia user akan memilih operasi 1 untuk mengawali pengisian data kemudian dilanjutkan dengan memilih operasi 2 hingga semua data telah berhasil dimasukan kedalam list, kemudian untuk menampilkan list data yang telah dimasukan user memilih operasi 7.



###  3. Lakukan perintah berikut: 
#### a. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 
#### b. Hapus data Denis 
#### c. Tambahkan data berikut di awal: Owi 2330000 
#### d. Tambahkan data berikut di akhir: David 23300100 
#### e. Ubah data Udin menjadi data berikut: Idin 23300045 
#### f. Ubah data terkahir menjadi berikut: Lucy 23300101 
#### g. Hapus data awal 
#### h. Ubah data awal menjadi berikut: Bagas 2330002 
#### i. Hapus data akhir 
#### j. Tampilkan seluruh data




### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/42b5376b-179e-4929-9ca5-473afb70dcb5)


Output diatas merupakan hasil akhir dari perubahan data dari perintah diatas. User menggunakan operasi 1 untuk menambahkan data di awal list, kemudian menggunakan operasi no 2 untuk menambahkan data diakhir list, lalu operasi no 3 untuk menghapus data diawal list, kemudian operasi no 4 untuk menghapus data di akhir list, operasi no 6 untuk mengubah data lalu user akan diperintahkan untuk mengisi posisi data yang akan dihapus, dan operasi no 7 untuk menampilkan keseluruhan hasil akhir data. 



## Kesimpulan
Kesimpulan dari materi ini, single linked list adalah struktur data yang terdiri dari rantaian elemen sejenis yang saling berhubungan [1]. Double linked list, linked list ini dikenal dengan nama linked list berpointer ganda atau double linked list, pointernya yaitu prev yang digunakan untuk menggeser mundur selain itu juga tetap mempertahankan pointer next [2]. Linked list non-circular yang mana node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list. Linked lis circular adalah linked list dimana node node yang  terhubung seperti lingkaran. Dalam linked list circular, node pertama dan node terakhir terhubung satu sama lain atau tidak memiliki akhir.

## Referensi

[1] Mulyana, Ade & Sukamto, Anton & Cahyadi, Septian & Priambodo, Bagus & Jumaryadi, Yuwan & Nashar, M.Nashar. (2021). Cara Mudah Mempelajari Algoritma dan Struktur Data. 

[2] B. Soetanto, “STRUKTUR DATA ‘DASAR DASAR PEMROGRAMAN’” 


‌


‌

 