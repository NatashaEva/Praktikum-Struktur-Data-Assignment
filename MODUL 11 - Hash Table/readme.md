# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Hash table adalah struktur data yang digunakan untuk mengimplementasikan pemetaan (mapping) antara kunci (keys) dengan nilai nilai (values) [1].  Hash table merupakan salah satu struktur data yang sangat efisien karna memungkinkan akses cepat ke nilai nilai dengan keys tertentu [1]. Struktur data ini menggunakan fungsi hash untuk menentukan lokasi dan sejumlah bucket (slot, tabel) penyimpan key dan value [2].  Dengan fungsi hash, tabel hash dapat menghindari pencarian berurutan dan memberikan waktu akses konstan ke data [1].

Meski demikian, terdapat aturan yang dibuat untuk mencegah tabrakan (collision handling), situasi dimana dua kunci yang berbeda pada hash menghasilkan indeks yang sama dalam tabel hash [1].

Terdapat beberapa teknik yang digunakan untuk menangani tabrakan (collision handling), diantaranya yaitu :

1. Chaining (Open hashing)

   Setiap item dalam tabel hash berisi daftar yang berisi semua nilai yang sama (linked list) akan dipindahkan ketempat lain.[2].  Karena tidak dapat mengurutkan dua rekaman data yang berbeda di ruangan yang sama, maka diperlukan mencari tempat alternatif baru bagi semua rekaman data kecuali rekaman data pertama yang menghasilkan indeks tertentu [3]. Maka, pencarian akan menjadi lambat, karna pencarian nama memerlukan tahap pencarian pada daftar terkait [4].

2. Open addressing (closed hashing)
   
   Jika terjadi tabrakan, sistem ini akan mencari slot kosong lain dalam tabel untuk menempatkan nilai yang bersangkutan (probing) [1]. Untuk menentukan lokasi loncat berikutnya menggunakan fungsi kuadrat (quadratic probing), kemudian fungsi hash akan menentukan lokasi berikutnya (double hashing) [2].


## Guided 1


```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}



```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/bae679cc-57ba-4ad7-a173-cd0aad6327e0)



Kode diatas meruapan program hash table yang menggunakan teknik chaining (open hashing) untuk menangani tabrakan (collision). 

- Program ini pertama tama akan melakukan, Penfinisian fungsi 'hash_func' untuk mengembalikan indeks di mana kunci tersebut akan disimpan dalam tabel hash. Indeks dihitung dengan mengambil sisa pembagian kunci dengan ukuran maksimum tabel ('MAX_SIZE'). 
- Kemudian, setiap elemen dalam tabel hash akan diwakili oleh sebuah node ('Node') yang menyimpan pasangan key-value dan pointer ('next') ke node berikutnya dalam linked list untuk menangani tabrakan.
- Untuk class 'HashTable' ini mereprentasikan hash table secara menyeluruh, dalamnya terdapat constructor untuk mengalokasikan memori untuk 'table' dengan ukuran 'MAX_SIZE' dan menginisialisasi semua pointer menjadi 'nullptr' dan destructor untuk membersihkan semua node yang dialokasikan untuk menghindari memory leak. 
- Kemudian fungsi insertion untuk menambahkan kunci dan nilai ke hash table. Jika key sudah ada maka value akan diperbaharui. Jika belum ada, node baru akan ditambahkan di awal linked list pada indeks yang sesuai.
- Lalu untuk fungsi searching untuk mencari value yang terkait dengan key tertentu, Jika ditemukan, value akan dikembalikan, jika tidak, -1 dikembalikan.
- Fungsi deletiion untuk mengahapus node dengan key terntentu dari hash table.
- Transversal untuk mencari dan mencetak semua key dan value dalam hash table.






## Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
    
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}



```

### Output 
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/fa9923e3-bb30-4a05-8acf-0a5c8396fecc)

Kode diatas merupakan sebuah program hash table yang digunakan untuk menyimpan data pegawai berupa nama dan nomor telepon. Hash Table memungkinkan pencarian nomor telepon berdasarkan nama dengan waktu rata-rata yang lebih cepat dibandingkan pencarian linear pada list atau array biasa. Ini dikarenakan fungsi hash membantu memetakan nama ke indeks bucket tertentu, sehingga pencarian hanya perlu dilakukan pada bucket terkait.

- Dalam 'HashNode' menyimpan variabel 'name'  dan 'phone_number' yang bertipe string untuk menyimpan data nama dan nomor telepon pegawai.
- Dalam 'HashMap' untuk mengelola array hash table berukuran tetap.
- Fungsi 'Insertion' untuk memasukan data nama dan no telp ke dalam hashmap.
-Fungsi 'Removal' untuk menghapus node dengan nama tertentu dari hash map.
- Fungsi 'Search' untuk mencari data no telp berdasarkan nama.





## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a.Setiap mahasiswa memiliki NIM dan nilai. b.Program memiliki tampilan pilihan menu berisi poin C. c.Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).



```C++
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    string NIM;
    float nilai;
};

class HashTable {
private:
    vector<list<Mahasiswa>> table;
    int size;
    
    int hashFunction(const string& NIM) {
        int hash = 0;
        for (char c : NIM) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }
    
    void tambahMahasiswa(const string& NIM, float nilai) {
        int index = hashFunction(NIM);
        Mahasiswa mhs = {NIM, nilai};
        table[index].push_back(mhs);
        cout << "Data mahasiswa dengan NIM " << NIM << " berhasil ditambahkan." << endl;
    }

    void hapusMahasiswa(const string& NIM) {
        int index = hashFunction(NIM);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->NIM == NIM) {
                chain.erase(it);
                cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNIM(const string& NIM) {
        int index = hashFunction(NIM);
        auto& chain = table[index];
        for (auto& mhs : chain) {
            if (mhs.NIM == NIM) {
                cout << "Mahasiswa ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNilai(float minNilai, float maxNilai) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            for (auto& mhs : table[i]) {
                if (mhs.nilai >= minNilai && mhs.nilai <= maxNilai) {
                    cout << "Mahasiswa ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa dengan nilai dalam rentang " << minNilai << " - " << maxNilai << "." << endl;
        }
    }
};

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Hapus Mahasiswa\n";
    cout << "3. Cari Mahasiswa berdasarkan NIM\n";
    cout << "4. Cari Mahasiswa berdasarkan Nilai (80 - 90)\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    HashTable ht(10);
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                string NIM;
                float nilai;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                if (NIM.length() != 10) {
                    cout << "NIM harus terdiri dari 10 karakter." << endl;
                    break;
                }
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.tambahMahasiswa(NIM, nilai);
                break;
            }
            case 2: {
                string NIM;
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> NIM;
                ht.hapusMahasiswa(NIM);
                break;
            }
            case 3: {
                string NIM;
                cout << "Masukkan NIM yang dicari: ";
                cin >> NIM;
                ht.cariMahasiswaByNIM(NIM);
                break;
            }
            case 4: {
                ht.cariMahasiswaByNilai(80, 90);
                break;
            }
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}


```


#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/36ccaf8c-f5e9-4bfb-900c-741b53a7a05d)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/d66d0578-1b3a-4a18-9218-1c7993a1b32f)

Kode diatas merupakan program hash table yang digunakan untuk menyimpan dan mengelola data mahasiswa berupa NIM dan nilai. Program ini memiliki beberapa operasi yaiu penambahan dan penghapusan data mahasiswa, pencarian data mahasiswa berdasarkannim dan berdasarkan rentang nilai.

- Pertama dilakukan pendefinisian struct dengan nama 'Mahasiswa' untuk menyimpan data mahasiswa yaitu 'NIM' dan 'nilai' 
- Class 'HashTable' untuk mengelola array dan memori dengan ukuran 's', ukuran ini menentukan jumlah bucket dalam hash table.
- Fungsi 'hashFunction' untuk menghitung indeks bucket untuk NIM, dengan mengalikan NIM dengan konstanta kemudian menjumlahkan hasil tsb, dan melakukan operasi modulo thd ukuran hash table.
- Fungsi 'tambahMahasiswa' untuk menambahkan data mahasiswa yang berupa nim dan nilai.
-Fungsi 'hapusMahasiswa' untuk mengahapus data yang sudah diinputkan berdasarkan 'NIM'.
-Fungsi 'cariMahasiswaByNIM' untuk mencari data nilai mahasiswa berdasarkan 'NIM'.
- Fungsi 'cariMahasiswaByNilai' untuk mencari NIM mahasiswa yang memiliki rentang niai 80 - 90



## Kesimpulan

Hash table adalah struktur data yang digunakan untuk mengimplementasikan pemetaan (mapping) antara kunci (keys) dengan nilai nilai (values). Struktur data ini menggunakan fungsi hash untuk menentukan lokasi dan sejumlah bucket (slot, tabel) penyimpan key dan value. Meski demikian, terdapat aturan yang dibuat untuk mencegah tabrakan (collision handling), situasi dimana dua kunci yang berbeda pada hash menghasilkan indeks yang sama dalam tabel hash. Terdapat dua teknik untuk mengatasi tabrakan yaitu ; chaining (Open hashing) yaitu setiap item dalam tabel hash berisi daftar yang berisi semua nilai yang sama (linked list) akan dipindahkan ketempat lain, dan open addressing (closed hashing) yaitu jika terjadi tabrakan, sistem ini akan mencari slot kosong lain dalam tabel untuk menempatkan nilai yang bersangkutan.

## Referensi

[1] PENGANTAR ILMU KOMPUTER : Panduan Komprehensif bagi Pemula. (2023). (n.p.): PT. Sonpedia Publishing Indonesia.

[2] Algoritma dan Struktur Data menggunakan Golang, Bonus: Intro Pemrograman Web: untuk dosen, mahasiswa, ataupun hobbyist. (2014). (n.p.): Kiswono Prayogo.

[3] Siahaan, V., & Sianipar, R. H. (2018). C#.NET Teori dan Aplikasi untuk Mahasiswa. Balige: Balige Publishing

[4] Sistem Operasi: Buku Referensi Informatika dan Sistem Informasi. (2018). (n.p.): Sefa Bumi Persada.


‌
‌  
‌


‌

 