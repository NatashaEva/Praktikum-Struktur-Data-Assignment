# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

1. Graph

Graph adalah salah satu jenis struktur data yang terdiri dari berbagai node yang saling terhubung. Objek yang berbentuk node yang saling terhubung ini tergambarkan oleh sebuah titik yang disebut vertex [1]. Suatu graph terdiri dari suatu himpunan tak kosong yang masing masing unsurnya disebut titik (vertex) dan suatu himpunan pasangan tak berurutan dari titik titik tersebut disebut sisi (edge) [2]. Graph merupakan struktur data nonlinier yang terdiri dari simpul dan sisi (edges). Graph  terdiri dari simpul(vertex) (V) dan sisi (edges) (E). Grafik tersebut dilambangkan dengan G=(V, E) [2]. 

Graph dibedakan menjadi dua jenis yaitu [1] :
- Direct Graph
Direct graph adalah garis yang terhubung ke semua simpul (vertex).
- Undirect Graph
Undirect graph adalah garis yang tidak terhubung dengan semua simpul (vertex).


2. Tree

Tree adalah struktur data non linier yang berbentuk menyerupai pohon, yang terdiri dari serangkaian node (simpul) yang saling berhubungan, node node ini dihubungkan oleh vektor [3]. Tree bisa didefinisikan sebagai kumpulan simpul dengan satu elemen khusus disebut Root dan node lainnya (subtree) [4]. Dalam tree terdapat jenis jenis tree yang bersifat khusus, diantaranya adalah binary tree. Binary tree adalah tree yang tiap nodenya hanya dapat memiliki maksimal 2 subtree dan kedua subtree tersebut harus dipisah [4].

## Guided 1


```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}

```

### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/cdd1b56f-bc9b-484d-9225-b02aa77d7640)



Kode diatas merupakan program graph yang digunakan untuk menggambarkan jaringan rute antar kota di Jawa Barat dan sekitarnya. 

Pada program ini melakukan inisialisasi variabel 'string simpul[7]' yang merupakan array berukuran 7 untuk menyimpan nama nama kota, dan variabel 'int busur[7][7]' yang merupakan matriks berukuran 7x7 untuk menyimpan bobot (jarak) antar kota.

 Dalam program ini terdapat beberapa program, yang pertama yaitu fungsi 'tampilGraph' untuk menampilkan graph kota dan jarak dalam bentuk yang mudah terbaca. Didalam fungsi ini terdapat looping untuk mengiterasi baris per baris array simpul (kota), jika ada jarak busur bukan 0 maka akan menampilkan nama kota tujuan dan jarak busurnya.


## Guided 2

```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main () {
    TNode *zero = new TNode(0);
    //0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    /// \
    // 1 9

    one->left = zero;
    // 7
    // / \
    // 1 9
    // / \
    // 0 NULL

    one->right = five;
    // 7
    // / \
    // 1 9
    // / \
    // 0 5

    nine->left = eight;
    // 7 
    // / \
    // 1 9
    // / \ / \
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;

    return 0;
}


```

### Output 
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/4742abaa-b86b-4c54-8328-fb185e5d5bdc)


Kode diatas merupakan sebuah program binary tree dan tiga jenis transversal dalam tree yaitu pre-oreder, in-order, dan post-order yang digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal, program ini digunakan menyimpan data angka seperti tree. 

Program ini melakukan pendefinisian struktur node sbg perwakilan dalam binary  tree 'struct TNode'. 'TNode' berisi variabel 'data' untuk menyimpan nilai dari node, pointer 'left' dan 'right' untuk menunjukan node child sebelah kiri dan kanan. Terdapat 3 fungsi transversal pada program ini, yang pertama pre-order transversal, disini akan dilakukan pencarian tree yaitu dengan mengunjungi node saat ini, melakukan rekursif panggil 'preOrder' di node kanan dan kiri. Selanjutnya In-Order transversal juga akan melakukan penelusuran tree dengan cara melakukan rekursif memanggil 'inOrder' untuk node child kiri, mengunjungi node saat ini, dan melakukan rekursif memanggil 'inOrder' untuk node child kanan. Terakhir, Post-Order transversal dengan cara mengunjungi node child di kiri lalu ke node child kanan, lalu mengunjungi node saat ini. Lalu untuk fungsi 'main' program ini berfungsi untuk membangun binary tree dan memanggill fungsi transversal lalu mencetak hasilnya.





## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.  Output Program :

![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/0d845ffb-ac11-4347-9646-4dd9443580b4)




```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // untuk menggunakan setfill dan setw

using namespace std;

int main() {
    string identitas = "2311110005/Natasha Eva Dwi Nurdiyanti";

    cout << "NIM/Nama: " << identitas << endl << endl;

    // Meminta input jumlah simpul
    int numNodes;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        cout << "Silakan masukkan nama simpul\nSimpul " << i + 1 << " : ";
        cin >> nodes[i];
    }

    vector<vector<int>> graph(numNodes, vector<int>(numNodes));

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul\n" << nodes[i] << "-->" << nodes[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    // Fungsi untuk menampilkan matriks bobot dengan format yang diinginkan
    cout << endl;
    cout << "     ";
    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i];
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}


```


#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/5e5284a6-6fa3-4c0a-9626-93e7b408c1cf)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/2e4530ce-76a1-4590-97e4-bbcf6799ad50)


Kode diatas merupakan program graph yang memungkinkan user menentukan jumlah simpul (node) dan bobot (jarak) antar simpul. Program ini akan meminta pengguna untuk memasukan jumlah simpul (node) dalam graph yang akan disimpan dalam variabel 'numNodes', lalu meminta memasukan nama setiap node yang akan disimpan di 'nodes' dan bobotnya antar node. 

Untuk memasukan bobot antar simpul diperlukan untuk membuat matriks ketetanggaan ('graph') untuk menyimpannya, dengan cara melakukan loop ('for (int i = 0; i < numNodes; i++)') untuk mengiterasi tiap simpul awal, dan loop ('for (int j = 0; j < numNodes; j++)') untuk mengiterasi simpul tujuan. Jika simpul awal dan tujuan sama (i == j), bobot akan menjadi 0, jika tidak sama, program akan meminta pengguna untuk memasukkan bobot antara dua simpul tersebut. Kemudian data data nama dan jumlah simpul akan ditampilkan secara matriks, baris pertama akan menunjukan nama nama node, dan setiap baris akan menunjukan nama node awal dan bobotnya.



 ### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!


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
![Cuplikan layar 2024-06-07 214413](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/bcb4f725-5c66-4394-9ef0-1b28646f4de4)

![Cuplikan layar 2024-06-07 214438](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/cdff87fc-7a7c-4174-8ba0-7879bac4590f)

![Cuplikan layar 2024-06-07 214524](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/c62b3fdd-a701-4422-99cb-d4f5e0472654)


#### Full Code Screenshots
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/a4e5b7c0-3c98-40e5-a808-de50fb667215)


Kode diatas merupakan program tree  yang memungkinkan user untuk menginput data tree sendiri dan memilih menu yang diinginkan yaitu menu input data tree, tampilkan matriks bobot, tampilkan child dari node, tampilkan descendant node, dan keluar.

Dalam prgram ini terdapat fungsi 'displayMenu' untuk menampilkan menu yang diinputkan. Kemudian terdapat fungsi 'displayMatrix' untuk menampilkan bobot antar simpul(node) dalam bentuk matriks. Fungsi 'findIndex'untuk menemukan posisi node berdasarkan nama node. Fungsi 'findDescendants' untuk mencari semua turunan dari node.

Saat pengguna memilih menu 1 (input data tree) maka user akan diminta memasukan jumlah node dan memberi node tsb nama, lalu memasukan bobot nya untuk setiap node. Untuk menu 2 (tampilkan matriks bobot) program akan melalkukan pengecekan apakah data tree sudah diinputkan lalu program akan menampilkannya dalam bentuk matriks. Lalu menu 3 (tampilkan child dari node) user akan diminta memasukan nama node yang ingin dilihat childnya, kemudian akan dicari dengan 'findIndex', apabila child telah ditemukan maka prgram kan memanggil 'displayChild' untuk menampilkannya.
Untuk menu 4 (tampilkan descendat dari node) user akan diminta memasukan nama node yang ingin dilihat descendant nya, program ini akan memanggil 'finfIndex' untuk mencari indeks node ts. Lalu akan memanggil 'displayDescendants' untuk mencari (dengan fungsi 'findDescendats') dan menampilkan semua descendat dari node yang dicari.




## Kesimpulan

Graph terdiri dari kumpulan node dan edge yang saling terhubung, edge dapat memiliki bobot atapun tidak. Graph memiliki beragam jenis yaitu graph berbobot (weighted graph) yaitu graph yang edges nya memiliki bobot/nilai. Graph terhubung adalah graph yang terdapat jalur/hubungan antar simpul. Graph tidak terhubung adalah graph yang tidak memiliki jalur/hubungan antar simpul lain. Untuk tree adalah struktur data yang terdiri dari satu root node dan node lainnya akan terhubung dengan root yang disebut parent. Dalam tree, terdapat tipe binary tree yang setiap simpulnya memiliki maksimal 2 child. Tree memiliki 3 jenis transversal yaitu pre-order, in-order, dan post-order. Graph dan tree digunakan untuk merepresentasikan dan menyelesaikan masalah yang melibatkan hubungan antar objek. Graph lebih umum dan fleksibel, memungkinkan representasi hubungan kompleks dengan sirkuit, sedangkan tree menawarkan struktur yang lebih terorganisir dan efisien untuk operasi pencarian dan pengurutan. 

## Referensi

[1] Oki Arifin et al., DASAR PEMROGRAMAN : Teori & Aplikasi. PT. Sonpedia Publishing Indonesia, 2023.

[2] Erkamim Erkamim et al., Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia, 2024.

[3] Pastima Simanjuntak, S.Kom., M.SI, E. Elisa,. S.Kom, and Hotma Pangaribuan, S.Kom., M.SI, Pengantar Konsep Struktur Data. Pustaka Galeri Mandiri, 2020.

[4] Muhammad Benny Chaniago and Cecep Kurnia Sastradipraja, Buku Ajar Algoritma dan Struktur Data. Kaizen Media Publishing, 2022.
 ‌


‌

 