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

public:
    int counter_if;
    int counter_swap;
    BST();

    void insert(int keyl);
    bool remove(int key);
    int height();
    void print_BST();
};