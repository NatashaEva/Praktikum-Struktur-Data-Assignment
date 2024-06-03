#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    string NIM;
    float nilai;
};

class HashTable {
private:
    vector<list<Mahasiswa>> table;
    int size;
    
    int hashFunction(const string& NIM) {
        int hash = 0;
        for (char c : NIM) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }
    
    void tambahMahasiswa(const string& NIM, float nilai) {
        int index = hashFunction(NIM);
        Mahasiswa mhs = {NIM, nilai};
        table[index].push_back(mhs);
        cout << "Data mahasiswa dengan NIM " << NIM << " berhasil ditambahkan." << endl;
    }

    void hapusMahasiswa(const string& NIM) {
        int index = hashFunction(NIM);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->NIM == NIM) {
                chain.erase(it);
                cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus." << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNIM(const string& NIM) {
        int index = hashFunction(NIM);
        auto& chain = table[index];
        for (auto& mhs : chain) {
            if (mhs.NIM == NIM) {
                cout << "Mahasiswa ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void cariMahasiswaByNilai(float minNilai, float maxNilai) {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            for (auto& mhs : table[i]) {
                if (mhs.nilai >= minNilai && mhs.nilai <= maxNilai) {
                    cout << "Mahasiswa ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa dengan nilai dalam rentang " << minNilai << " - " << maxNilai << "." << endl;
        }
    }
};

void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tambah Mahasiswa\n";
    cout << "2. Hapus Mahasiswa\n";
    cout << "3. Cari Mahasiswa berdasarkan NIM\n";
    cout << "4. Cari Mahasiswa berdasarkan Nilai (80 - 90)\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    HashTable ht(10);
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: {
                string NIM;
                float nilai;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                if (NIM.length() != 10) {
                    cout << "NIM harus terdiri dari 10 karakter." << endl;
                    break;
                }
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                ht.tambahMahasiswa(NIM, nilai);
                break;
            }
            case 2: {
                string NIM;
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> NIM;
                ht.hapusMahasiswa(NIM);
                break;
            }
            case 3: {
                string NIM;
                cout << "Masukkan NIM yang dicari: ";
                cin >> NIM;
                ht.cariMahasiswaByNIM(NIM);
                break;
            }
            case 4: {
                ht.cariMahasiswaByNilai(80, 90);
                break;
            }
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}
