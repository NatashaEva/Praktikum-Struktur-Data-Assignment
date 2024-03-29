#include <iostream>
#include <string>

using namespace std;

void bubble_sort(string nama[], int n) {
  bool not_sorted = true;
  int j = 0;
  string tmp;

  while (not_sorted) {
    not_sorted = false;
    j++;
    for (int i = 0; i < n - j; i++) {
      if (nama[i] > nama[i + 1]) {
        tmp = nama[i];
        nama[i] = nama[i + 1];
        nama[i + 1] = tmp;
        not_sorted = true;
      }
    }
  }
}

void print_array(string nama[], int n) {
  for (int i = 0; i < n; i++) {
    cout << nama[i] << " ";
  }
  cout << endl;
}

int main() {
  // Deklarasi variabel
  int n = 10; // Jumlah warga
  string nama[n] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Menampilkan nama warga sebelum sorting
  cout << "Urutan nama warga Pak RT sebelum sorting: " << endl;
  print_array(nama, n);

  // Mengurutkan nama warga
  bubble_sort(nama, n);

  // Menampilkan nama warga setelah sorting
  cout << "Urutan nama warga Pak RT setelah sorting: " << endl;
  print_array(nama, n);

  return 0;
}
