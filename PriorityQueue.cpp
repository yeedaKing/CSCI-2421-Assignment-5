#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    heap = {0};
}

PriorityQueue::PriorityQueue(const vector<int> arr) {
    heap = {0};
    for (int num: arr) {
        insert(num);
    }
}

bool PriorityQueue::isEmpty() {
    return heap.size() == 1;
}

void PriorityQueue::insert(int val) {
    heap.push_back(val);
    int indx = heap.size()-1;
    while (indx > 1 && heap[indx/2] > heap[indx]) {
        swap(heap[indx], heap[indx/2]);
        indx /= 2;
    }
}

int PriorityQueue::deleteMin() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int min = heap[1];
    int n = heap.size()-1;
    heap[1] = heap[n];
    heap.pop_back();
    int i = 1;
    while (true) {
        bool flag1 = (2*i < n) ? heap[i] > heap[2*i] : false;
        bool flag2 = (2*i+1 < n) ? heap[i] > heap[2*i+1] : false;
        if (flag1 && flag2) {
            if (heap[2*i] < heap[2*i+1]) {
                swap(heap[2*i], heap[i]);
                i *= 2;

            } else {
                swap(heap[2*i+1], heap[i]);
                i = 2*i + 1;
            }

        } else if (flag1) {
            swap(heap[2*i], heap[i]);
            i *= 2;

        } else if (flag2) {
            swap(heap[2*i+1], heap[i]);
            i = 2*i + 1;

        } else {
            break;
        }
    }
    return min;
}

void PriorityQueue::print() {
    for (int i=1; i<heap.size(); i++) {
        cout << heap[i] << ' ';
    }
    cout << endl;
}