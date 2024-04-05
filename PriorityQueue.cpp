/*********************************************************
* Summary: This file includes the implementation for the PriorityQueue class (defined
* in PriorityQueue.h).
*
* This program implements a priority queue class via a minimum binary heap implementation.
* An object of this class can be initialized with a default constructor or a constructor
* accepting a list of values for the queue. The PriorityQueue class supports inserting new
* nodes as well as removing/returning the minimum value of the queue. There is also a
* simple boolean function that returns true if the queue is currently empty and false if
* not. Note that the heap is implemented using a vector.
*
* Author: David Yee
* Created: April 5, 2024
* Summary of Modifications [if applicable]:
*
********************************************************/

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    heap = {0};
}

PriorityQueue::PriorityQueue(const vector<int> arr) {
    heap = {0};
    // insert the values into the heap one by one
    for (int num: arr) {
        insert(num);
    }
}

bool PriorityQueue::isEmpty() {
    // one-based indexing is used instead of zero-based indexing
    return heap.size() == 1;
}

void PriorityQueue::insert(int val) {
    /**
     * Inserts a new value into the data structure. Ensures the heap
     * properties are maintained.
     *
     *
     * @param val value to insert
     * @return void
     */

    heap.push_back(val);
    int indx = heap.size()-1;

    // index of current node's parent == (current node's index)/2
    while (indx > 1 && heap[indx/2] > heap[indx]) {
        swap(heap[indx], heap[indx/2]);
        indx /= 2;
    }
}

int PriorityQueue::deleteMin() {
    /**
     * Returns the minimum value and removes it from the structure.
     * Ensures the heap properties are maintained.
     * 
     *
     * @return The minimum value within the heap
     */

    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    // store min result to return later
    int min = heap[1];

    // replace min value with rightmost node on last level
    int n = heap.size()-1;
    heap[1] = heap[n];
    heap.pop_back();
    int i = 1;

    // traverse heap to find correct position
    while (true) {
        // check if the left and right child values are less than current node's val
        bool flag1 = (2*i < n) ? heap[i] > heap[2*i] : false;
        bool flag2 = (2*i+1 < n) ? heap[i] > heap[2*i+1] : false;

        if (flag1 && flag2) {
            // choose the smaller of the two to swap with if both vals are less than node's
            if (heap[2*i] < heap[2*i+1]) {
                swap(heap[2*i], heap[i]);
                i *= 2;

            } else {
                swap(heap[2*i+1], heap[i]);
                i = 2*i + 1;
            }

        } else if (flag1) {
            // case where only the left child is smaller than the node's value
            swap(heap[2*i], heap[i]);
            i *= 2;

        } else if (flag2) {
            // case where only the right child is smaller than the node's value
            swap(heap[2*i+1], heap[i]);
            i = 2*i + 1;

        } else {
            // node is in the correct position, so exit out of the loop
            break;
        }
    }
    return min;
}

void PriorityQueue::print() {
    // print the values from left to right
    for (int i=1; i<heap.size(); i++) {
        cout << heap[i] << ' ';
    }
    cout << endl;
}