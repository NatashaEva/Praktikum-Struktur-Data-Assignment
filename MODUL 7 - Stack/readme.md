# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Natasha Eva Dwi Nurdiyanti</p>

## Dasar Teori

Stack adalah struktur data yang ditandai dengan tempat penyisipan/penambahan dan penghapusan elemen data yang terjadi hanya disatu tempat yang disebut puncak (top) tumpukan. Cara mengakses stack yaitu dengan metode Last In First Out (LIFO) yang artinya data yang terakhir kali masuk ke dalam stack adalah yang pertama kali akan keluar [1]. Stack tidak memiliki nomor indeks, oleh sebab itu elemen data yang berbeda pada posisi tengah tidak dapat diakses secara langsung [1].

Setidaknya, stack harus memiliki operasi-operasi sebagai
berikut [2]:
1. Push: Untuk menambahkan item pada tumpukan
paling atas, dan tidak bisa dilakukan lagi apabila stack
sudah penuh.
2. Pop: Untuk mengambil item teratas, dengan syarat stack tidak boleh kosong.
3. Clear: Untuk mengosongkan stack, dengan
cara mengeset Top dengan -1. Jika Top bernilai kurang dari
nol, maka stack dianggap kosong.
4. IsEmpty: Untuk memeriksa apakah stack kosong. Tanda bahwa stack kosong adalah Top bernilai kurang dari nol.
5. IsFull: Untuk memeriksa apakah stack sudah penuh. Stack penuh jika puncak stack terdapat tepat di bawah jumlah maksimum yang bisa ditampung oleh stack.
6. Retrieve: Untuk mendapatkan nilai dari item teratas.

   


## Guided 

### 1. Sourcecode

```C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}


void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah "  << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack suda penuh?" << isFull() << endl;
    cout << "Apakah data stack kososng?" << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    
    cout << "Banyakanya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}





```
### Output
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/cae3e287-0936-45fa-9531-b200ee4ac347)


Kode diatas merupakan program stack yang digunakan untuk mengelola daftar buku dengan maksimal data 5 elemen, program ini memungkinkan untuk menambahkan buku baru ke stack, menghapus buku dari stack, melihat buku pada posisi tertentu di stack menghitung jumlah buku di stack, mengubah judul buku pada posisi tertentu di stack, dan menghapus semua buku dari stack. Program ini menggunakan variabel arrayBuku[5] yang digunakan untuk menyimpan judul buku, dengan ukuran maksimum 5 elemen. Dalam program ini terdapat beberapa fungsi yaitu isFull() yang digunakan untuk mengembalikan true jika stack penuh (top mencapai maksimal), fungsi isEmpty()untuk mengembalikan true jika stack kosong (top = 0), fungsi pushArrayBuku(string data) untuk menambahkan elemen baru (judul buku) ke array pada posisi top, fungsi popArrayBuku() untuk menghapus elemen teratas (judul buku) dari array, fungsi peekArrayBuku untuk
menampilkan elemen pada posisi yang ditentukan, fungsi changeArrayBuku untuk memperbarui elemen pada posisi yang ditentukan dengan judul buku baru (data), fungsi destroyArrayBuku() untuk menghapus semua elemen dalam stack dengan mengosongkan nilai array, fungsi cetakArrayBuku() untuk mencetak elemen stack dicetak dari atas ke bawah.



## Unguided 

#### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.


```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stack;
int top = -1;

// Fungsi Push
void push(char ele) {
    stack[++top] = ele;
}

// Fungsi Pop
char pop() {
    return stack[top--];
}

// Fungsi untuk mengecek palindrome atau bukan
int isPalindrome(char str[]) {
    int length = strlen(str);

    // Mengalokasikan memori secara dinamis untuk stack berdasarkan panjang string
    stack = (char*)malloc(length * sizeof(char));
    if (stack == NULL) {
        printf("Alokasi memori gagal!\n");
        return -1; // Indikasi erorr
    }

    int mid = length / 2;


    for (int i = 0; i < mid; i++) {
        push(str[i]);
    }

    // Lewati karakter tengah untuk string yang berukuran ganjil
    if (length % 2 != 0) {
        mid++;
    }

    // Membandingkan seluruh karakter sampai akhir
    while (str[mid] != '\0') {
        char ele = pop();
        if (ele != str[mid]) {
            return 0; // Bukan palindrome
        }
        mid++;
    }

    free(stack); //  Mendealokasikan memori yang digunakan untuk stack untuk mencegah kebocoran memori.
    return 1; // Palindrome
}

int main() {
    char str[100]; // Mengatur maximum panjang string

    printf("Masukan Kalimat: ");
    fgets(str, sizeof(str), stdin);

    //  Menghapus karakter baris baru berlebih (jika ada)
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str) == 1) {
        printf("%s adalah palindrome.\n", str);
    } else if (isPalindrome(str) == 0) {
        printf("%s bukan palindrome.\n", str);
    } else { 
        printf("Erorr.\n");
    }

    return 0;
}


```
#### Output:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/bc5cbd03-0776-458d-89c4-e014256dfe66)

#### Full code screenshots:
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/79e273bb-4315-4061-b274-5a8eb0b8efe2)

Kode diatas merupakan program yang digunakan untuk memeriksa kalimat yang dimasukan oleh user merupakan kalimat palindrom atau bukan,  yang mana menggunakan struktur data stack untuk menyimpan dan membandingkan karakter dalam kalimat. Program ini akan meminta user untuk memasukan kalimat dan membacanya yang kemudian akan disimpan dalam array str. Kemudian program ini akan memerikasa panjang kalimat yang telah dimasukan user lalu dialokasikan memori untuk stack. Kemudian program akan melakukan looping untuk memasukan karakter dalam stack dengan menggunakan fungsi push, untuk karakter yang berjumlah ganjil, karakter tengahnya tidak dibandingkan karena palindrom harus memiliki karakter yang sama di kedua sisi. Kemudian dilakukan looping untuk pembandingan karakter dengan mengeluarkan karakter dari stack dan membandingkannya dengan karakter yang sesuai di separuh kedua lalu menggunakan fungsi pop untuk mengeluarkan karakter tsb dari stack. Jika semua karakter yang dikeluarkan dari stack cocok dengan karakter di separuh kedua kalimat, maka kalimat adalah palindrom. Jika ada karakter yang tidak cocok, kalimat bukan palindrom hal ini menggunakan fungsi isPalindrome.

 
### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?


```C++

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data stack
typedef struct {
    char* items; // Array untuk menyimpan karakter-karakter
    int top;     // Indeks atas
    int maxSize; // Ukuran maksimum 
} Stack;

// Fungsi untuk membuat stack baru
Stack* buatStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Alokasi memori untuk stack
    stack->items = (char*)malloc(maxSize * sizeof(char)); // Alokasi memori untuk array items
    stack->top = -1; // Mengatur indeks atas stack ke -1 (stack kosong)
    stack->maxSize = maxSize; // Mengatur ukuran maksimum stack
    return stack;
}

// Fungsi untuk memeriksa apakah stack kosong
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk memeriksa apakah stack penuh
int isFull(Stack* stack) {
    return stack->top == stack->maxSize - 1;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack penuh.\n");
        return;
    }
    stack->items[++stack->top] = item; // Menambahkan elemen ke dalam stack
}

// Fungsi untuk menghapus dan mengembalikan elemen teratas dari stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong.\n");
        return '\0'; // Mengembalikan karakter kosong jika stack kosong
    }
    return stack->items[stack->top--]; // Menghapus dan mengembalikan elemen teratas dari stack
}

// Fungsi untuk membalikkan kalimat menggunakan stack
void balikanKata(char sentence[]) {
    int length = strlen(sentence);
    Stack* stack = buatStack(length);

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (int i = 0; i < length; i++) {
        push(stack, sentence[i]);
    }

    // Mengeluarkan setiap karakter dari stack untuk membalikkan urutan
    printf("Kalimat setelah dibalik: ");
    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan untuk stack
    free(stack->items);
    free(stack);
}

int main() {
    char sentence[100];

    // Minta input kalimat dari pengguna
    printf("Masukkan kalimat (min 3 kata): ");
    fgets(sentence, sizeof(sentence), stdin);

    // Memanggil fungsi untuk membalikkan kalimat
    balikanKata(sentence);

    return 0;
}


```

### Output :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/e26a7fe0-98ca-4236-9eb5-63c3c7f5fa8b)

### Full Code Screenshots :
![image](https://github.com/NatashaEva/Praktikum-Struktur-Data-Assignment/assets/161322715/63159e7b-6329-4076-8fa9-fa0dd3bc0e5d)

 
Kode diatas merupakan program yang digunakan untuk membalikan kalimat yang dimasukan oleh user menggunakan struktur data stack. Dalam program ini terdapat beberapa fungsi yaitu fungsi buatStack yang digunakan untuk menyediakan memori untuk struktur data stack, fungsi isEmpty untuk memeriksa apakah stack kosong atau tidak, fungsi isFull untuk memeriksa apaka stack penuh atau tidak, fungsi push untuk menambahkan elemen ke array, fungsi pop untuk menghapus elemen teratas(top) dari array, dan fungsi balikKata untuk menerima input kalimat dan panjang kalimat. Program ini akan membaca kalimat yang dimasukan user kemudian membuat stack baru menggunakan fungsi buatStack, kemudian memasukan tiap karakter dalam stack dengan fungsi push, lalu melakukan looping hingga stack kosong lalu dikeluarkan dari stack dengan fungsi pop dan membalikan urutan karakter dalam stack. 


## Kesimpulan
Stack adalah struktur data yang ditandai dengan tempat penyisipan/penambahan dan penghapusan elemen data yang terjadi hanya disatu tempat yang disebut puncak (top) tumpukan, yang mana data yang terakhir kali masuk ke dalam stack adalah yang pertama kali akan keluar. Stack harus memiliki operasi-operasi yaitu push, pop, clear, IsEmpty, IsFull, dan Retrive.


## Referensi

[1] Hidayah AK, Alam RG, Prihandoko P. STRUKTUR DATA DENGAN PYTHON [Internet]. Buku Google. PT. Penerbitan Sonpedia Indonesia; 2023 
‌ 

[2] Mudah C, Algoritma M, Data D. Ade Mulyana, dkk 


‌


‌

 