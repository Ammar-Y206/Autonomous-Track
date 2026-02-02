#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    int* data = new int[size];

    for(int i = 0; i < size; i++) {
        data[i] = i * 2;
    }

    for(int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    delete[] data;
    data = nullptr;
}
