#include <iostream>

using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
};

struct Node {
  Mahasiswa data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(Mahasiswa mahasiswa) { // Enqueue using Student struct
  Node* newNode = new Node;
  newNode->data = mahasiswa;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = back = newNode;
  } else {
    back->next = newNode;
    back = newNode;
  }
}

void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Antrian kosong" << endl;
    return;
  }

  Node* temp = front;
  front = front->next;
  delete temp;

  if (front == nullptr) {
    back = nullptr;
  }
}

int countQueue() {
  int count = 0;
  Node* current = front;
  while (current != nullptr) {
    count++;
    current = current->next;
  }
  return count;
}

void clearqueue() {
  while (front != nullptr) {
    dequeueAntrian();
  }
}

void viewqueue() {
  cout << "Data antrian mahasiswa: " << endl;
  int i = 1;
  Node* current = front;
  while (current != nullptr) {
    cout << i << "." << "Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl;
    current = current->next;
    i++;
  }
}

int main() {
  Mahasiswa M1 = {"Natasha Eva Dwi Nurdiyanti", "2311110005"};
  Mahasiswa M2 = {"Eva", "231"};
  enqueueAntrian(M1);
  enqueueAntrian(M2);
  viewqueue();
  cout << "Jumlah Antrian = " << countQueue() << endl;
  dequeueAntrian();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  clearqueue();
  viewqueue();
  cout << "Jumlah antrian = " << countQueue() << endl;
  return 0;
}
