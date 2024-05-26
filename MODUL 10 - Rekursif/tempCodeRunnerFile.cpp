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
