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