#include <iostream>

using namespace std;

struct Node {
  string data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;

bool isEmpty() {
  return front == nullptr;
}

void enqueueAntrian(string data) {
  Node* newNode = new Node;
  newNode->data = data;
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
  cout << "Data antrian teller: " << endl;
  int i = 1;
  Node* current = front;
  while (current != nullptr) {
    cout << i << "." << current->data << endl;
    current = current->next;
    i++;
  }
}

int main() {
  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
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
