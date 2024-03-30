#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  int n = 5; // Jumlah mahasiswa
  float ips[n] = {3.8, 2.9, 3.3, 4.0, 2.4}; // Array IPS
  int i, j, min, temp;

  // Looping untuk mengurutkan IPS
  for (i = 0; i < n - 1; i++) {
    min = i; // Indeks minimum saat ini
    for (j = i + 1; j < n; j++) {
      // Mencari nilai minimum dalam array
      if (ips[j] > ips[min]) {
        min = j;
      }
    }

    // Menukar nilai minimum dengan nilai di indeks i
    if (min != i) {
      temp = ips[i];
      ips[i] = ips[min];
      ips[min] = temp;
    }
  }

  // Menampilkan hasil pengurutan
  cout << "IPS mahasiswa dari terbesar hingga terkecil: " << endl;
  for (i = 0; i < n; i++) {
    cout << ips[i] << " ";
  }

  cout << endl;

  return 0;
}
