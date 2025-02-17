#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <utility>
#include <tuple>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <list>
#include <array>
#include <unordered_map>


struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Initialize node with data and nullptr for left and right children   
    Node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

class AVLTrees {
    private:
        Node* root;

    public:
        AVLTrees() : root(nullptr) {}

        // Integer function to return the height of the tree
        static int getHeight(Node* node){
            return (node == nullptr) ? 0 : node->height;
        }

        // Integer to get balance factor
        static int getBalanceFactor(Node* node){
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
        Node* insert(Node* node, int value){
            // Check if the root is null, if so, create a new node with the value and return it
            if (node == nullptr){
                return new Node(value);
            }
            
            // Check if node is already present (no duplicates)
            if (node->data == value) {
                return node;
            }
        
            // Insert to the left if value is smaller than root
            if(value < node->data){
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }

            // Update the height of the node
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

            // Get the balance factor of the root
            int balance = getBalanceFactor(node);
            
            // Left Left Case
            if (balance > 1 && value < node->left->data) {
                return rotateRight(node);
            }

            // Right Right Case
            if (balance < -1 && value > node->right->data) {
                return rotateLeft(node);
            }

            // Left Right Case
            if (balance > 1 && value > node->left->data) {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }

            // Right Left Case
            if (balance < -1 && value < node->right->data) {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
            return node;
        }

        void insert(int value) {
            root = insert(root, value);
        }

        Node* getRoot() const {
            return root;
        }

        Node* search(Node* node, int key) {
            // Base case: If the tree is empty or the key is found
            if (node == nullptr || node->data == key) {
                return node;
            }

            // If key is smaller, search in the left subtree
            if (key < node->data) {
                return search(node->left, key);
            }
            
            // If key is larger, search in the right subtree
            return search(node->right, key);
        }

        Node* search(int key) {
            return search(root, key);
        }
};

class Traversals {
    private:
        Node* root;

    public:
        enum TraversalType {
            INORDER,
            PREORDER,
            POSTORDER
        };

        Traversals(Node* root, TraversalType type) : root(root) {
            switch (type) {
                case INORDER:
                    inOrderTraversal(root);
                    break;
                case PREORDER:
                    preOrderTraversal(root);
                    break;
                case POSTORDER:
                    postOrderTraversal(root);
                    break;
                default:
                    throw std::invalid_argument("Invalid traversal type");
            }
            std::cout << std::endl;
        }

    private:
        // Function for inorder traversal.
        void inOrderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            inOrderTraversal(node->left);
            std::cout << node->data << " ";  // Print the node value
            inOrderTraversal(node->right);
        }

        // Function for pre-order traversal
        void preOrderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            std::cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }

        // Function for post-order traversal
        void postOrderTraversal(Node* node){
            if (node == nullptr){
                return;
            }
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout << node->data << " ";
        }
};

struct HashingFunction{
    public:
    int jenkinsHash(int key, int mapSize) {
        key += (key << 10);
        key ^= (key >> 6);
        key += (key << 3);
        key ^= (key >> 11);
        key += (key << 15);
        return key % mapSize;  // Ensure index is within valid range
    }

    int jenkinsHash(const std::string& key, int mapSize) {
       unsigned int hash = 0;
       for (char c : key) {
          hash += c;
          hash += (hash << 10);
          hash ^= (hash >> 6);
        }
       hash += (hash << 3);
       hash ^= (hash >> 11);
       hash += (hash << 15);
       return hash % mapSize;  // Ensure index is within valid range
    }

    int key;
    explicit HashingFunction(int key) : key(key) {}
    HashingFunction() : key(0) {}
};

template <typename T1, typename T2>
class Data {
    public:
        T1 key; // T1 is an integer or string
        T2 value; // T2 is a int or string
        
        Data() : key(""), value(0) {}
        explicit Data(T1 key, T2 value) : key(key), value(value) {}

    std::tuple<T1, T2> data;
   
    std::tuple <T1, T2> getData() {
        std::tuple<T1, T2> data = std::make_tuple(key, value);
        return data;
    }
    T1 getKey() const {
        return key;
    }
    T2 getValue() const {
        return value;
    }
};

class HashMap{
    private:
        typedef std::vector<Data<std::string,int>> Map;
        typedef Data<std::string,int> Data;
        HashingFunction hash; 
        Data data;
        Map map;
        AVLTrees trees;
        std::unordered_map<int, AVLTrees> collisionTrees;
    public:
        int size;
        int maxSize = 16;
    
    // Explicit constructor to initialize the size and max size of the map
    explicit HashMap(int maxSize) : size(0), maxSize(maxSize) {map.resize(maxSize);}

       // Function to resize the map
    void resizeMap() {
        maxSize *= 2; // Double the size
        Map newMap(maxSize); // Create a new vector with the updated size

        // Rehash and insert existing elements into the new map
        for (const auto& entry : map) {
            int index = hash.jenkinsHash(entry.getKey(), maxSize);
            while (newMap[index].getKey() != "") {  // Linear probing to find the empty spot
                index = (index + 1) % maxSize;
            }
            newMap[index] = entry;
        }

        map = std::move(newMap);  // Replace old map with the resized one
    }
   
  // Bulk insert function to handle multiple Data elements
    void insert(const std::vector<Data>& dataItems) {
        std::cout << "Attempting to insert " << dataItems.size() << " items..."<< std::endl;
        // Check if resizing is necessary
        if (size + dataItems.size() > maxSize) {
            std::cout << "Resizing the map...\n";
            resizeMap();  // Resize if necessary
        }
        for (const auto& data : dataItems) {
            std::string key = data.getKey();
            int index = hash.jenkinsHash(key, maxSize);
            int value = data.getValue();

            if (map[index].getKey() != "") {  // Collision detected
                if (collisionTrees.find(index) == collisionTrees.end()) {
                    collisionTrees[index] = AVLTrees();
                }
                collisionTrees[index].insert(value);
                std::cout << "Collision at index " << index << ": Value " << value << " stored in AVL tree.\n";
            } else {
                map[index] = data;
                size++;
                std::cout << "Inserted: " << key << " -> " << value << " at index " << index << "\n";
            }
        }
    }

    int retrieveIndex (std::string key) {
        int index = hash.jenkinsHash(key, maxSize);
        return index;
    }
    void displayCollisions() {
        for (const auto& [index, tree] : collisionTrees) {
            std::cout << "Collisions at index " << index << " (AVL Tree): ";
            Traversals(tree.getRoot(), Traversals::INORDER);
        }
    }
    
     // Function to display the map
    void display() {
        for (int i = 0; i < maxSize; i++) {
            if (map[i].getKey() != "") {
                std::cout << "[" << i << "] " << map[i].getKey() << ": " << map[i].getValue() << std::endl;
            }
        }
    }

    // Function to return the map which a list of data tuples
    Map getMap() {
        return map;
    }
    // Function to return the first tuple in the map
    Data returnFirstIndex() const {
        if (!map.empty()) {
            return map[0];
        }
        throw std::out_of_range("Map is empty");
    }

    // Function to return the last tuple in the map
    Data returnLastIndex(Map& map) {
        return map[map.size() - 1];
    }

    // Function to return the size of the map
    int getSize() {
        return size;
    }
 
};


int main(){
    std::cout << "Program started!" << std::endl;
    std::cout << std::endl;
    HashMap hashmap(8); // Start with a small size to force collisions

    // Insert values with minimal collisions
    std::vector<Data<std::string, int>> dataNoCollisions = {
        Data<std::string, int>("apple", 100),
        Data<std::string, int>("banana", 200),
        Data<std::string, int>("cherry", 300),
        Data<std::string, int>("date", 400)
    };

    std::cout << "Inserting values with no collisions:\n";
    hashmap.insert(dataNoCollisions);
    hashmap.display();
    
    std::cout << std::endl;

    // Insert values that will cause collisions
    std::vector<Data<std::string, int>> dataWithCollisions = {
        Data<std::string, int>("apple", 500),  // Same key (collision in hashmap)
        Data<std::string, int>("banana", 600), // Same key (collision in hashmap)
        Data<std::string, int>("grape", 700),  // May collide with another index
        Data<std::string, int>("kiwi", 800)    // May collide with another index
    };

    std::cout << "Inserting values with collisions:\n";
    hashmap.insert(dataWithCollisions);
    hashmap.display();

    std::cout << "\nDisplaying AVL Trees for Collisions:\n";
    hashmap.displayCollisions(); // Show AVL trees storing colliding values


    std::cout << std::endl;
    return 0;
}
