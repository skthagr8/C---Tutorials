#include <iostream>
using namespace std;

// Node class representing a single node of the binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}

    void insert(int data) {
        if (data < this->data) {
            if (this->left == nullptr) {
                this->left = new Node(data);
            } else {
                this->left->insert(data);
            }
        } else if (data > this->data) {
            if (this->right == nullptr) {
                this->right = new Node(data);
            } else {
                this->right->insert(data);
            }
        }
    }
};

// BinaryTree class to manage the root node and operations
class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
        } else {
            root->insert(data);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void printInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree binary_search_tree;
    binary_search_tree.insert(10);
    binary_search_tree.insert(5);
    binary_search_tree.insert(15);

    cout << "In-order traversal: ";
    binary_search_tree.printInOrder();

    return 0;
}
