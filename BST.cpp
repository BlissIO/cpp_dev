#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node in BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in BST
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Inserting elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    // Searching for a value
    int searchValue = 40;
    if (search(root, searchValue)) {
        cout << searchValue << " found in the BST." << endl;
    } else {
        cout << searchValue << " not found in the BST." << endl;
    }

    return 0;
}