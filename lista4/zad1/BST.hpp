#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;
    char* left_trace;
    char* right_trace;

    int height_recursive(Node* node);
    void print_recursive(Node* node, int depth, char prefix);
    void print_recursive2(Node * root, int depth, char prefix);
    Node** find_min(Node** current);

public:
    BST();

    void insert(int key);
    bool remove(int key);
    int height();
    void print_BST();
};