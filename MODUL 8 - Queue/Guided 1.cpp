#include <iostream>

using namespace std;

const int maksimalQueue = 5; // deklarasi maksimal queue 5 elemen
int front = 0;
int back = 0;

string queueTeller[5]; 

bool isFull() { // Pengecekan ada isinya atau tidak 
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if(isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearqueue() {
    if (isEmpty()) {
        cout << "Antrian kososng" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewqueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << "." << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
 
int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewqueue();
    cout << "Jumlah Antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewqueue();
    cout << "Jumlah antrian = " << countQueue << endl;
    clearqueue();
    viewqueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
} 