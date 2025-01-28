#include <iostream>
using namespace std;

void display(int* a, int sz) {
    if (sz == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    
    cout << "[";
    for (int i = 0; i < sz; i++) {
        cout << *(a + i);
        if (i < sz - 1) cout << " ";
    }
    cout << "]" << endl;
}

void insert(int*& a, int& sz, int n) {
    // Create new array with larger size
    int* newArray = new int[sz + 1];
    
    if (sz == 0) {
        // If array is empty, just insert the number
        *newArray = n;
    }
    else {
        // If new number is larger than last element, just append it
        if (n > *(a + sz - 1)) {
            // Copy all existing elements
            for (int i = 0; i < sz; i++) {
                *(newArray + i) = *(a + i);
            }
            // Append the new element
            *(newArray + sz) = n;
        }
        else {
            // Start from the end and move elements until we find the right position
            int i = sz - 1;
            while (i >= 0 && *(a + i) > n) {
                *(newArray + i + 1) = *(a + i);
                i--;
            }
            // Insert at the correct position
            *(newArray + i + 1) = n;
            // Copy remaining elements (if any) before the insertion point
            for (int j = 0; j <= i; j++) {
                *(newArray + j) = *(a + j);
            }
        }
    }
    
    // Delete old array if it exists
    if (sz > 0) {
        delete[] a;
    }
    
    // Update array pointer and size
    a = newArray;
    sz++;
}

void remove(int*& a, int& sz, int n) {
    if (sz == 0) {
        cout << "Array is empty" << endl;
        return;
    }
    
    // Find position of element to remove
    int pos = -1;
    for (int i = 0; i < sz; i++) {
        if (*(a + i) == n) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << "Element not found" << endl;
        return;
    }
    
    // Create new array with smaller size
    int* newArray = new int[sz - 1];
    
    // Copy elements before removal position
    for (int i = 0; i < pos; i++) {
        *(newArray + i) = *(a + i);
    }
    
    // Copy elements after removal position
    for (int i = pos + 1; i < sz; i++) {
        *(newArray + i - 1) = *(a + i);
    }
    
    // Delete old array
    delete[] a;
    
    // Update array pointer and size
    a = newArray;
    sz--;
}

// Example main function to test the implementation
int main() {
    int* arr = nullptr;
    int size = 0;
    
    insert(arr, size, 3);
    insert(arr, size, 1);
    insert(arr, size, 7);
    insert(arr, size, 12);
    cout << "After inserting 1, 3, 7, 12: ";
    display(arr, size);
    
    insert(arr, size, 5);
    cout << "After inserting 5: ";
    display(arr, size);
    
    remove(arr, size, 7);
    cout << "After removing 7: ";
    display(arr, size);
    
    // Clean up
    delete[] arr;
    return 0;
}