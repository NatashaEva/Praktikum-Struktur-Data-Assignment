#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // untuk menggunakan setfill dan setw

using namespace std;

int main() {
    string identitas = "2311110005/Natasha Eva Dwi Nurdiyanti";

    cout << "NIM/Nama: " << identitas << endl << endl;

    // Meminta input jumlah simpul
    int numNodes;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> numNodes;

    vector<string> nodes(numNodes);
    for (int i = 0; i < numNodes; ++i) {
        cout << "Silakan masukkan nama simpul\nSimpul " << i + 1 << " : ";
        cin >> nodes[i];
    }

    vector<vector<int>> graph(numNodes, vector<int>(numNodes));

    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                cout << "Silakan masukkan bobot antar simpul\n" << nodes[i] << "-->" << nodes[j] << " = ";
                cin >> graph[i][j];
            }
        }
    }

    // Fungsi untuk menampilkan matriks bobot dengan format yang diinginkan
    cout << endl;
    cout << "     ";
    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << setw(6) << nodes[i];
        for (int j = 0; j < numNodes; ++j) {
            cout << setw(6) << graph[i][j];
        }
        cout << endl;
    }

    return 0;
}
