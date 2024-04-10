/*********************************************************
* Summary: This file includes the definition for the PriorityQueue class (implemented
* in PriorityQueue.cpp).
*
* This program defines a priority queue class via a minimum binary heap implementation.
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

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class PriorityQueue {
public:
    // constructors
    PriorityQueue();
    PriorityQueue(const vector<int> arr);
    
    // methods
    bool isEmpty();
    void insert(int val);
    int deleteMin();
    void print();

private:
    // initialize variable
    vector<int> heap;

    // private function
    void heapifyDown();
};

#endif