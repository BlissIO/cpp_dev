#include <iostream>

using namespace std;

void insert(int*& a, int& sz, int n){
    int *newArr = new int[sz + 1]; // Allocate new array with size sz + 1
    
    // Find position where n should be inserted
    int pos = 0;
    while (pos < sz && a[pos] < n) {
        pos++;
    }
    
    // Copy elements before insertion point
    for (int i = 0; i < pos; i++) {
        newArr[i] = a[i];
    }
    
    // Insert the new element
    newArr[pos] = n;
    
    // Copy remaining elements after insertion point
    for (int i = pos; i < sz; i++) {
        newArr[i + 1] = a[i];
    }
    
    delete[] a; // Free the old array memory
    a = newArr; // Update the pointer to the new array
    sz++; // Increase the size of the array
}


// The remove function has a few issues that need to be addressed:
// 1. The condition to find the element to remove is incorrect. It should check `a[i]` instead of `newArr[i]`.
// 2. The `found` variable is never set to true, which means the code to remove the element will never execute.
// 3. The index variable should store the index of the found element, not the value of `n`.
// 4. The display function should iterate until `sz - 1` instead of `sz` to avoid accessing out of bounds.

void remove(int*& a, int& sz, int n){
    int index = -1;
    bool found = false;
    int *newArr = new int[sz]; // Allocate new array with size sz - 1
    for (int i = 0; i < sz; i++){
        if (a[i] == n){ // Check the original array for the value
            index = i; // Store the index of the found element
            found = true; // Set found to true
            continue; // Skip adding this element to newArr
        }
        newArr[i - (found ? 1 : 0)] = a[i]; // Shift elements to newArr
    }

    if (found){
        sz--; // Decrease the size of the array
    } else {
        delete[] newArr; // If not found, delete the new array
        newArr = a; // Keep the original array
    }
    a = newArr; // Update the pointer to the new array
}



void display(int* a, int sz){
    if (sz == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    for (int i = 0; i < sz; i++){ // Change to < sz to avoid out of bounds
        cout << a[i] << endl;
    }
}

int main(){
    int* nums = nullptr;
    int size = 0;
    int num = 0;
    cout << "Enter num: ";
    cin >> num;
    insert(nums, size, num);
    cout << "Displaying Array" << endl;
    display(nums, size);

    cout << "Enter num: ";
    cin >> num;
    insert(nums, size, num);
    cout << "Displaying Array" << endl;
    display(nums, size);

    cout << "Enter num: ";
    cin >> num;
    insert(nums, size, num);
    cout << "Displaying Array" << endl;
    display(nums, size);

    cout << "Enter num: ";
    cin >> num;
    insert(nums, size, num);
    cout << "Displaying Array" << endl;
    display(nums, size);

    cout << "Enter remove num: " << endl;
    cin >> num;
    remove(nums, size, num);
    cout << "Displaying Array" << endl;
    display(nums, size);
    return 0;
}