#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(const vector<int> arr);
    
    bool isEmpty();
    void insert(int val);
    int deleteMin();
    void print();

private:
    vector<int> heap;
};

#endif