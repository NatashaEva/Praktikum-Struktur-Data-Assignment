#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  // Deklarasi variabel
  int n;
  vector<char> karakter;

  // Meminta user untuk memasukkan jumlah karakter
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Meminta user untuk memasukkan n karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    karakter.push_back(c);
  }

  // Sorting ascending
  sort(karakter.begin(), karakter.end());

  // Menampilkan hasil sorting ascending
  cout << "Urutan karakter setelah ascending sort: ";
  for (char c : karakter) {
    cout << c << " ";
  }
  cout << endl;

  // Sorting descending
  sort(karakter.rbegin(), karakter.rend());

  // Menampilkan hasil sorting descending
  cout << "Urutan karakter setelah descending sort: ";
  for (char c : karakter) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}
