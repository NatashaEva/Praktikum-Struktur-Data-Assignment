#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // Deklarasi variabel
  string kalimat;
  char cari;
  int awal, akhir, tengah;
  bool b_flag = false;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Input huruf yang dicari
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> cari;

  // Mengubah semua huruf dalam kalimat menjadi huruf kecil
  for (int i = 0; i < kalimat.length(); i++) {
    kalimat[i] = tolower(kalimat[i]);
  }

  // Mengurutkan huruf dalam kalimat
  sort(kalimat.begin(), kalimat.end());

  // Menentukan batas awal dan akhir pencarian
  awal = 0;
  akhir = kalimat.length() - 1;

  // Melakukan binary search
  while (b_flag == 0 && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if (kalimat[tengah] == cari) {
      b_flag = true;
      break;
    } else if (kalimat[tengah] < cari) {
      awal = tengah + 1;
    } else {
      akhir = tengah - 1;
    }
  }

  // Menampilkan hasil pencarian
  if (b_flag) {
    cout << "Huruf " << cari << " ditemukan " << endl;
  } else {
    cout << "Huruf " << cari << " tidak ditemukan pada kalimat" << endl;
  }

  return 0;
}