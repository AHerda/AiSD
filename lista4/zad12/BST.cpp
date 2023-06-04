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

void BST::insert(int key) {
    Node** current = &root;

    while(*current != nullptr) current = (key < (*current)->key) ? &((*current)->left) : &((*current)->right); counter_if++; counter_swap++;

    *current = new Node(key);
    counter_swap++;
}

bool BST::remove(int key) {
    counter_swap+=2;
    Node** parent = nullptr;
    Node** current = &root;

    counter_if++;
    while(*current != nullptr && (*current)->key != key) {
        parent = current;
        current = (key < (*current)->key) ? &((*current)->left) : &((*current)->right);

        counter_if+=2;
        counter_swap+=2;
    }

    if(*current == nullptr) return false;

    if((*current)->left == nullptr) {
        Node* temp = (*current)->right;
        delete *current;
        *current = temp;
        counter_swap++;
    } else if((*current)->right == nullptr) {
        Node* temp = (*current)->left;
        delete *current;
        *current = temp;
        counter_swap++;
    } else {
        counter_swap+=2;
        Node* succ_parent = *current;
        Node* succ = (*current)->right;

        while(succ->left != nullptr) {
            succ_parent = succ;
            succ = succ->left;
            counter_swap+=2;
        }

        if(succ_parent != *current) {
            succ_parent->left = succ->right;
            counter_swap++;
        }
        else {
            succ_parent->right = succ->right; counter_swap++;
        }
        (*current)->key = succ->key;

        delete succ;
    }
    return true;
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