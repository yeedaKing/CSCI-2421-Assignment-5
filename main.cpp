/*******************************************************
Name      :  David Yee
Class     :  CSC 2421 Section 001
HW#       :  Assignment #4: Minimum Height BST
Due Date  :  04/15/2024
*******************************************************/

#include "PriorityQueue.h"

int main() {
    // have the user enter values for the queue and store them in a vector
    vector<int> vals;
    int val;
    cout << "Enter positive integers for the priority queue (enter -1 to quit): ";
    cin >> val;
    while (val != -1) {
        vals.push_back(val);
        cin >> val;
    }
    // initialize the priority queue and print out the main menu
    PriorityQueue heap(vals);
    int option;
    cout << "-------------------------------" << endl;
    cout << "1) Insert a value" << endl;
    cout << "2) Delete the min value" << endl;
    cout << "3) Print array representation" << endl;
    cout << "4) Exit" << endl;
    cout << "-------------------------------" << endl;
    cin >> option;

    // continue doing operations as long as the user doesn't wish to end the program
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