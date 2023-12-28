#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool leftThread; // true if left is a thread, false if it is a child
    bool rightThread; // true if right is a thread, false if it is a child
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() {
        root = NULL;
    }

    // Insert a new node into the tree
    void insert(int data) {
        // Create a new node
        Node* newNode = new Node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leftThread = false;
        newNode->rightThread = false;

        // Insert the new node into the tree
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent;
            while (true) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        // Set the left child of the parent to be the new node
                        parent->left = newNode;
                        newNode->leftThread = true;
                        newNode->left = parent;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == NULL) {
                        // Set the right child of the parent to be the new node
                        parent->right = newNode;
                        newNode->rightThread = true;
                        newNode->right = parent;
                        break;
                    }
                }
            }
        }
    }

    // Traverse the tree in inorder
    void inorder() {
        Node* current = root;

        // Find the leftmost node in the tree
        while (current->left != NULL) {
            current = current->left;
        }

        // Traverse the tree using the threads
        while (current != NULL) {
            cout << current->data << " ";
            if (current->rightThread) {
                current = current->right;
            } else {
                current = current->right;
                while (current != NULL && current->left != NULL) {
                    current = current->left;
                }
            }
        }
    }
};

int main() {
    ThreadedBinaryTree tree;

    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(12);
    tree.insert(37);
    tree.insert(62);

    return 0;
}

