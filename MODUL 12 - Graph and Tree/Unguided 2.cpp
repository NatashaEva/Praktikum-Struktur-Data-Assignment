#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "Menu: \n";
    cout << "1. Input Data Tree\n";
    cout << "2. Tampilkan Matriks Bobot\n";
    cout << "3. Tampilkan Child dari Node\n";
    cout << "4. Tampilkan Descendant dari Node\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

// Fungsi untuk menampilkan matriks bobot
void displayMatrix(const vector<string>& nodes, const vector<vector<int>>& graph) {
    cout << endl;
    cout << "     ";
    for (int i = 0; i < nodes.size(); ++i) {
        cout << setw(6) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < nodes.size(); ++i) {
        cout << setw(6) << nodes[i];
        for (int j = 0; j < nodes.size(); ++j) {
            cout << setw(6) << graph[i][j];
        }
        cout << endl;
    }
}

// Fungsi untuk mencari index dari node
int findNodeIndex(const vector<string>& nodes, const string& node) {
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i] == node) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk menampilkan child dari node
void displayChild(const vector<string>& nodes, const vector<vector<int>>& graph, const string& node) {
    int nodeIndex = findNodeIndex(nodes, node);
    if (nodeIndex == -1) {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    cout << "Child dari " << node << ": ";
    for (int j = 0; j < nodes.size(); ++j) {
        if (graph[nodeIndex][j] != 0) {
            cout << nodes[j] << " ";
        }
    }
    cout << endl;
}

// Fungsi rekursif untuk menampilkan semua descendant dari node
void findDescendants(const vector<string>& nodes, const vector<vector<int>>& graph, int nodeIndex, set<string>& descendants) {
    for (int j = 0; j < nodes.size(); ++j) {
        if (graph[nodeIndex][j] != 0 && descendants.find(nodes[j]) == descendants.end()) {
            descendants.insert(nodes[j]);
            findDescendants(nodes, graph, j, descendants);
        }
    }
}

// Fungsi untuk menampilkan descendant dari node
void displayDescendants(const vector<string>& nodes, const vector<vector<int>>& graph, const string& node) {
    int nodeIndex = findNodeIndex(nodes, node);
    if (nodeIndex == -1) {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    set<string> descendants;
    findDescendants(nodes, graph, nodeIndex, descendants);

    cout << "Descendant dari " << node << ": ";
    for (const auto& desc : descendants) {
        cout << desc << " ";
    }
    cout << endl;
}

int main() {
    vector<string> nodes;
    vector<vector<int>> graph;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            int numNodes;
            cout << "Silakan masukkan jumlah simpul : ";
            cin >> numNodes;

            nodes.resize(numNodes);
            for (int i = 0; i < numNodes; ++i) {
                cout << "Silakan masukkan nama simpul\nSimpul " << i + 1 << " : ";
                cin >> nodes[i];
            }

            graph.assign(numNodes, vector<int>(numNodes, 0));
            for (int i = 0; i < numNodes; ++i) {
                for (int j = 0; j < numNodes; ++j) {
                    if (i != j) {
                        cout << "Silakan masukkan bobot antar simpul\n" << nodes[i] << "-->" << nodes[j] << " = ";
                        cin >> graph[i][j];
                    }
                }
            }
        } else if (choice == 2) {
            if (!nodes.empty()) {
                displayMatrix(nodes, graph);
            } else {
                cout << "Silakan input data tree terlebih dahulu!\n";
            }
        } else if (choice == 3) {
            if (!nodes.empty()) {
                string node;
                cout << "Masukkan nama node: ";
                cin >> node;
                displayChild(nodes, graph, node);
            } else {
                cout << "Silakan input data tree terlebih dahulu!\n";
            }
        } else if (choice == 4) {
            if (!nodes.empty()) {
                string node;
                cout << "Masukkan nama node: ";
                cin >> node;
                displayDescendants(nodes, graph, node);
            } else {
                cout << "Silakan input data tree terlebih dahulu!\n";
            }
        } else if (choice != 5) {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (choice != 5);

    return 0;
}
