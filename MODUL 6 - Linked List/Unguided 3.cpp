#include <iostream>

using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int jumlah = 0;

    for (int i = 0; i < n; ++i) {
        if (data[i] == 4) {
            jumlah++;
        }
    }

    cout << "Jumlah angka 4 dalam data: " << jumlah << endl;

    return 0;
}
