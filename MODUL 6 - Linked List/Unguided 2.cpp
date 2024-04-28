#include <iostream>
#include <string>

using namespace std;

int main() {
  string kalimat;
  int hurufVokal = 0;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Menghitung jumlah huruf vokal
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' ||
        kalimat[i] == 'e' || kalimat[i] == 'o') {
      hurufVokal++;
    }
  }

  // Menampilkan hasil
  cout << "Jumlah huruf vokal di kalimat: " << hurufVokal << endl;

  return 0;
}
