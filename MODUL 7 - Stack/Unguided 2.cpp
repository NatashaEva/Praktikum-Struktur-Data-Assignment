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
