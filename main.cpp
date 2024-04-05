#include "PriorityQueue.h"

int main() {
    vector<int> vals;
    int val;
    cout << "Enter positive integers for the priority queue (enter -1 to quit): ";
    cin >> val;
    while (val != -1) {
        vals.push_back(val);
        cin >> val;
    }
    PriorityQueue heap(vals);
    int option;
    cout << "-------------------------------" << endl;
    cout << "1) Insert a value" << endl;
    cout << "2) Delete the min value" << endl;
    cout << "3) Print array representation" << endl;
    cout << "4) Exit" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;

    while (option != 4) {
        if (option == 1) {
            int val;
            cout << "Enter val: ";
            cin >> val;
            heap.insert(val);

        } else if (option == 2) {
            cout << "minValue: " << heap.deleteMin() << endl;

        } else {
            heap.print();
        }
        cout << "\n-------------------------------" << endl;
        cout << "1) Insert a value" << endl;
        cout << "2) Delete the min value" << endl;
        cout << "3) Print array representation" << endl;
        cout << "4) Exit" << endl;
        cout << "-------------------------------" << endl;
        cin >> option;
    }
    return 0;
}