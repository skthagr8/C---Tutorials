#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Initialize node with data and nullptr for left and right children   
    Node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node){
    return (node == nullptr) ? 0 : node->height;
}

// Recursive Insert function, that accepts a pointer to the node struct and a value as a reference
Node* insert(Node* root, int value){
    if (root == nullptr){
        root = new Node(value);
        return root;
    }
    // Check if node is already present
    if(root->data == value){
        return root;
    }
    // Insert to the left if value is less than root
    if(root->data < value ){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


// Function for inorder traversal.
void inOrderTraversal(Node* root){
    if (root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";  // Print the node value
    inOrderTraversal(root->right);
}


int main(){
    Node* root = new Node(8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);

    std::cout << "The height of this tree is: " << getHeight(root) << std::endl;
    
    inOrderTraversal(root);
    return 0;
}