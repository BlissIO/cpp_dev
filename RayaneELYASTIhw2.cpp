//*******************************************************************
// Rayane EL YASTI
// Homework 2
// due 1/28/2025
// This program implements a sorted array data structure that maintains
// numbers in ascending order. It provides the following operations:
// - insert: adds a new number while maintaining sorted order
// - delete: removes a specified number from the array
// - display: shows all numbers in the array in [x y z] format
// The program runs interactively, accepting user commands until 'exit'
// is entered.
//*******************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

void insert(int*& a, int& sz, int n) {
    // Create new array with space for one more element
    int* array = new int[sz + 1];
    
    // If array is empty, just insert the number
    if (sz == 0) {
        *array = n;
    }
    else {
        // If new number is largest, add it to the end
        if (n > *(a + sz - 1)) {
            // Copy existing elements
            for (int i = 0; i < sz; i++) {
                *(array + i) = *(a + i);
            }
            // Add new number at end
            *(array + sz) = n;
        }
        else {
            // Find where to insert the new number
            int i = sz - 1;
            while (i >= 0 && *(a + i) > n) {
                *(array + i + 1) = *(a + i);
                i--;
            }
            // Insert the new number
            *(array + i + 1) = n;
            // Copy remaining numbers
            for (int j = 0; j <= i; j++) {
                *(array + j) = *(a + j);
            }
        }
    }
    
    // Free old array memory
    if (sz > 0) {
        delete[] a;
    }
    // Point to new array
    a = array;
}

void remove(int*& a, int& sz, int n) {
    int i = 0;
    // Look for the number to delete
    while (i < sz && a[i] != n) {
        i++;
    }
    
    // Print message if number not found
    if (i == sz) {
        cout << "Element in the array was not found\n";
    }

    // If found, shift remaining numbers left
    if (i < sz) {
        for (int j = i; j < sz - 1; j++) {
            a[j] = a[j + 1];
        }
        sz--; // Reduce array size
    }
}

void display(int* a, int sz) {
    // Handle empty array
    if (sz == 0) {
        cout << "The Array is empty" << endl;
        return;
    }
    
    // Print array in [x y z] format
    cout << "[";
    for (int i = 0; i < sz; i++) {
        cout << *(a + i);
        if (i < sz - 1)
            cout << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Setup variables for array and user input
    int* arr = nullptr;
    int sz = 0;
    int n;
    string input;
    
    while (true) {
        // Get user command
        cout << "Please input the cmd [insert] [display] [delete] [exit]" << endl << "-->";
        cin >> input;
        
        if (input == "insert") {
            cout << "Please input the number that you want to insert into the array" << endl << "--> ";
            cin >> n;
            insert(arr, sz, n);
            sz++;
        }
        else if (input == "delete") {
            cout << "What is the number you want to delete" << endl << "--> ";
            cin >> n;
            remove(arr, sz, n);
        }
        else if (input == "display") {
            display(arr, sz);
        }
        else if (input == "exit") {
            // Clean up memory before exit
            if (arr != nullptr) {
                delete[] arr;
            }
            break;
        }
    }
    
    return 0;
}