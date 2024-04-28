#include <iostream>
#include <string>
using namespace std;

// Struktur Node
struct Node {
    string nama;
    int nim;
    Node* next;
};

// Class LinkedList
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data di depan
    void tambahDepan(string nama, int nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan data di belakang
    void tambahBelakang(string nama, int nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanData() {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus data di awal
    void hapusDepan() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Fungsi untuk menghapus data di akhir
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Fungsi untuk menghapus data sesuai posisi
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* temp = head;
        if (posisi == 1) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; i < posisi - 2; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Fungsi untuk mengubah data sesuai posisi
    void ubahData(int posisi, string namaBaru, int nimBaru) {
        Node* temp = head;
        for (int i = 0; i < posisi - 1; i++) {
            temp = temp->next;
        }
        temp->nama = namaBaru;
        temp->nim = nimBaru;
    }
};

int main() {
    LinkedList list;
    int opsi;

    do {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Hapus Tengah" << endl;
        cout << "6. Ubah Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> opsi;

        switch (opsi) {
            case 1: {
                string nama;
                int nim;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            }
            case 2: {
                string nama;
                int nim;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            }
            case 3: {
                list.hapusDepan();
                cout << "Data di depan berhasil dihapus" << endl;
                break;
            }
            case 4: {
                list.hapusBelakang();
                cout << "Data di belakang berhasil dihapus" << endl;
                break;
            }
            case 5: {
                int posisi;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                list.hapusTengah(posisi);
                cout << "Data berhasil dihapus" << endl;
                break;
            }
            case 6: {
                int posisi;
                string namaBaru;
                int nimBaru;
                cout << "Masukkan posisi : ";
                cin >> posisi;
                cout << "Masukkan nama baru : ";
                cin >> namaBaru;
                cout << "Masukkan NIM baru : ";
                cin >> nimBaru;
                list.ubahData(posisi, namaBaru, nimBaru);
                cout << "Data berhasil diubah" << endl;
                break;
            }
            case 7: {
                list.tampilkanData();
                break;
            }
            case 0: {
                cout << "Program selesai" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (opsi != 0);

    return 0;
}
