#include <iostream>
using namespace std;

// Define a node structure for the linked list
struct Node {
    int value;     // Data stored in the node
    Node* next;    // Pointer to the next node in the list
};

int main() {
    // Create 3 nodes
    Node* head = new Node();  // First node
    Node* second = new Node(); // Second node
    Node* third = new Node();  // Third node

    // Assign values and connect the nodes
    head->value = 10;
    head->next = second;

    second->value = 20;
    second->next = third;

    third->value = 30;
    third->next = nullptr;  // End of the list

    // Pointer to walk through the list
    Node* current = head;

    // Traverse the list and print values
    while (current != nullptr) {
        cout << "Node value: " << current->value << endl;
        current = current->next;  // Move to the next node
    }

    // Clean up dynamically allocated memory
    delete head;
    delete second;
    delete third;

    return 0;
}
