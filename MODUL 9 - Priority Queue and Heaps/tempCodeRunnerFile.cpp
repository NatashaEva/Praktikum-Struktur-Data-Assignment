#include <iostream>
#include <algorithm>

int H[50];
int heapsize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i + 1);
}

int rightChild(int i) {
    return (2 * i + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapsize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapsize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapsize = heapsize + 1;
    H[heapsize] = p;
    shiftUp(heapsize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapsize];
    heapsize = heapsize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n, value;
    std::cout << "Enter the number of elements to insert into the heap: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int index, newPriority;
    std::cout << "Enter the index to change priority and new priority value: ";
    std::cin >> index >> newPriority;
    changePriority(index, newPriority);

    std::cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Enter the index to remove: ";
    std::cin >> index;
    remove(index);

    std::cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapsize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
