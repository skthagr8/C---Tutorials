#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Initialize node with data and nullptr for left and right children   
    Node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

// Integer function to return the height of the tree
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Integer to get balance factor
int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right Rotation for (LL) case
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Return the new root
}

// Left Rotation for (RR) case
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update Heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Return the new root
}

// Recursive Insert function
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return root;
    }

    // Check if node is already present (no duplicates)
    if (root->data == value) {
        return root;
    }

    // Insert to the left if value is smaller than root
    if (root->data > value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    // Update the height of the node
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get the balance factor of the root
    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && value < root->left->data) {
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->data) {
        return rotateLeft(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

class Traversals {
public:
    static void inOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        std::cout << root->data << " ";  // Print the node value
        inOrderTraversal(root->right);
    }

    static void preOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    static void postOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data << " ";
    }
};

int main() {
    Node* root = nullptr;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);

    std::cout << "The height of this tree is: " << getHeight(root) << std::endl;

    std::cout << "In Order Traversal: ";
    Traversals::inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre Order Traversal: ";
    Traversals::preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post Order Traversal: ";
    Traversals::postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
