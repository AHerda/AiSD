#include "BST.hpp"

BST::BST() {
    root = nullptr;
    counter_if = 0;
    counter_swap = 0;
}

int BST::height_recursive(Node* node) {
    if(node == nullptr) return 0;

    int lh = height_recursive(node->left);
    int rh = height_recursive(node->right);

    return std::max(lh, rh) + 1;
}

void BST::print_recursive(Node* node, int depth, char prefix){
    if(node == nullptr) return;
    if(node->left != nullptr) print_recursive(node->left, depth + 1, '/');

    if(prefix == '/') left_trace[depth - 1] = '|';
    if(prefix == '\\') right_trace[depth - 1] = ' ';

    if(depth == 0) std::cout << "-";
    if(depth > 0) std::cout << " ";

    for(int i = 0; i < depth - 1; i++) {
        if(left_trace[i] == '|' || right_trace[i] == '|') {
            std::cout << "| ";
        } else {
            std::cout << "  ";
        }
    }

    if(depth > 0) {
        if(prefix == '/') std::cout << "\u250C";
        else std::cout << "\u2514";
    }
    std::cout << "[" << node->key << "]" << std::endl;

    left_trace[depth] = ' ';
    if(node->right != nullptr) {
        right_trace[depth] = '|';
        print_recursive(node->right, depth + 1, '\\');
    }
}

void BST::insert_recursive(Node** node, int key) {
    if(*node == nullptr) {
        *node = new Node(key);
        counter_swap++;
    }
    else if(key < (*node)->key) {
        insert_recursive(&((*node)->left), key);
        counter_if++;
    }
    else {
        insert_recursive(&((*node)->right), key);
    }
}

void BST::insert(int key) {
    insert_recursive(&root, key);
}

Node* BST::min_node(Node* node) {
    if (node == nullptr) {
        counter_swap++;
        return nullptr;
    }
    else if (node->left == nullptr) {
        counter_swap+=2;
        return node;
    }
    else {
        counter_swap+=2;
        return min_node(node->left);
    }
}

Node* BST::remove_recursive(Node* node, int key) {
    Node* tmp;
    counter_swap++;

    if (node == nullptr)
        return nullptr;
    else if (key < node->key) {
        counter_if++;
        node->left = remove_recursive(node->left, key);
    }
    else if (key > node->key) {
        counter_if += 2;
        node->right = remove_recursive(node->right, key);
    }
    else if (node->left && node->right) {
        counter_if += 4;
        tmp = min_node(node->right);
        node->key = tmp->key;
        node->right = remove_recursive(node->right, node->key);
    }
    else {
        counter_if += 4;
        counter_swap += 2;
        tmp = node;
        if(node->left == nullptr)
            node = node->right;
        else if(node->right == nullptr)
            node = node->left;
        delete tmp;
    }
    return node;
}

int BST::height() {
    return height_recursive(root);
}

void BST::print_BST() {
    int size = height_recursive(root);
    left_trace = new char[size];
    right_trace = new char[size];

    print_recursive(root, 0, '-');

    delete [] left_trace;
    delete [] right_trace;
}

void BST::remove(int key) {
    Node* temp = remove_recursive(root, key);
}