#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int n;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Harap masukkan bilangan bulat positif!" << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    }

    return 0;
}
