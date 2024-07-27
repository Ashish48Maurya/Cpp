#include <bits/stdc++.h>
using namespace std;

class maxHeap {
public:
    vector<int> v;
    int size;
    int totalCap;

    maxHeap(int cap) {
        v.resize(cap);
        size = 0;
        totalCap = cap;
    }

    void insert(int val) {
        if (size == totalCap) {
            cout << "Heap Full" << endl;
            return;
        }
        v[size] = val;
        int index = size;
        size++;

        while (index > 0 && v[index] > v[(index - 1) / 2]) {
            swap(v[index], v[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
};

void heapify(vector<int>& maxheap, int start, int end) {
    int largest = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;

    if (left <= end && maxheap[left] > maxheap[largest]) largest = left;
    if (right <= end && maxheap[right] > maxheap[largest]) largest = right;

    if (largest != start) {
        swap(maxheap[largest], maxheap[start]);
        heapify(maxheap, largest, end);
    }
}

void heapSort(vector<int>& maxheap) {
    int size = maxheap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(maxheap, i, size - 1);
    }
    for (int i = size - 1; i > 0; i--) {
        swap(maxheap[0], maxheap[i]);
        heapify(maxheap, 0, i - 1);
    }
}

int main() {
    vector<int> arr = {12, 17, 18, 23, 15, 30, 20, 22, 14, 24, 19};
    maxHeap h1(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        h1.insert(arr[i]);
    }
    vector<int> maxheap = h1.v;
    heapSort(maxheap);

    for (int num : maxheap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
