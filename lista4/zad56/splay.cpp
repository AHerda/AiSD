#include <iostream>
#include <vector>
#include <fstream>
#include "splay.hpp"
void presentation(const int n, int *toInsert, int *toDelete);
void experiment(const int n, int *toInsert, int *toDelete);

Splay::Splay() : root(nullptr), counter_if(0), counter_swap(0) {}

void Splay::insert(int key) {
    std::shared_ptr<Node> node = std::make_shared<Node>(key);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    node->key = key;
    std::shared_ptr<Node> y = nullptr;
    std::shared_ptr<Node> x = this->root;
    counter_swap += 5;

    // Przechodzimy w dół drzewa, aż y będzie nodem w ostatnim rzędzie drzewa
    counter_swap++;
    while (x != nullptr) {
        y = x;
        counter_swap++;
        counter_if++;
        if (node->key < x->key) {
            x = x->left;
            counter_swap++;
        } else {
            counter_if++;
            counter_swap++;;
            x = x->right;
        }
        counter_swap++;
    }

    node->parent = y;
    counter_swap += 2;
    if (y == nullptr) {
        counter_swap++;
        root = node;
    } else if (node->key < y->key) {
        counter_if++;
        counter_swap++;;
        y->left = node;
    } else {
        counter_if += 2;;
        counter_swap++;
        y->right = node;
    }
    splay(node);
}

void Splay::remove(int key) {
    remove_recursive(this->root, key);
}

void Splay::remove_recursive(std::shared_ptr<Node> node, int key) {
    counter_swap++;
    std::shared_ptr<Node> x = nullptr;
    std::shared_ptr<Node> t;
    std::shared_ptr<Node> s;
    counter_swap++;
    while (node != nullptr) {
        counter_if++;
        if (node->key == key) {
            counter_swap++;
            x = node;
        }

        counter_if++;
        if (node->key < key) {
            counter_swap++;
            node = node->right;
        } else {
            counter_if++;
            counter_swap++;
            node = node->left;
        }
        counter_swap++;
    }

    counter_swap++;
    if (x == nullptr) {
        return;
    }
    split(x, s, t); 
    counter_swap++;
    if (s->left) { 
        counter_swap++;
        s->left->parent = nullptr;
    }
    root = join(s->left, t);
    counter_swap++;
    s = nullptr;
}

int Splay::height(){
    return height_recursive(this->root);
}

int Splay::height_recursive(std::shared_ptr<Node> root){
    if (root == nullptr) return 0;
    else if (root->left == nullptr && root->right == nullptr) return 1;
    else if (root->right == nullptr) return height_recursive(root->left) + 1;
    else if (root->left == nullptr)  return height_recursive(root->right) + 1;
    else return std::max(height_recursive(root->left), height_recursive(root->right)) + 1;
}

void Splay::leftRotate(std::shared_ptr<Node> x) {
    counter_swap += 2;
    std::shared_ptr<Node> y = x->right;
    x->right = y->left;

    counter_swap++;
    if (y->left != nullptr) {
        counter_swap++;
        y->left->parent = x;
    }
    counter_swap += 2;
    y->parent = x->parent;
    if (x->parent == nullptr) {
        counter_swap++;
        this->root = y;
    } else if (x == x->parent->left) {
        counter_swap += 2;
        x->parent->left = y;
    } else {
        counter_swap += 3;
        x->parent->right = y;
    }
    counter_swap += 2;
    y->left = x;
    x->parent = y;
}

void Splay::rightRotate(std::shared_ptr<Node> x) {
    counter_swap += 2;
    std::shared_ptr<Node> y = x->left;
    x->left = y->right;

    counter_swap++;
    if (y->right != nullptr) {
        counter_swap++;
        y->right->parent = x;
    }
    counter_swap += 2;
    y->parent = x->parent;
    if (x->parent == nullptr) {
        counter_swap++;
        this->root = y;
    } else if (x == x->parent->right) {
        counter_swap += 2;
        x->parent->right = y;
    } else {
        counter_swap += 3;
        x->parent->left = y;
    }
    counter_swap += 2;
    y->right = x;
    x->parent = y;
}

void Splay::splay(std::shared_ptr<Node> x) {
    counter_swap++;
    while (x->parent) {
        counter_swap++;
        if (!x->parent->parent) {
            counter_swap++;
            if (x == x->parent->left) {
                // Zig rotation
                rightRotate(x->parent);
            } else {
                counter_swap++;
                // Zag rotation
                leftRotate(x->parent);
            }
        } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
            counter_swap += 2;
            // Zig-zig rotation
            rightRotate(x->parent->parent);
            rightRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
            counter_swap += 4;
            // Zag-zag rotation
            leftRotate(x->parent->parent);
            leftRotate(x->parent);
        } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
            counter_swap += 6;
            // Zig-zag rotation
            leftRotate(x->parent);
            rightRotate(x->parent);
        } else {
            // Zag-zig rotation
            rightRotate(x->parent);
            leftRotate(x->parent);
        }
    }
}

std::shared_ptr<Node> Splay::join(std::shared_ptr<Node> s, std::shared_ptr<Node> t) {
    counter_swap++;
    if (!s) {
        return t;
    }
    counter_swap++;
    if (!t) {
        return s;
    }
    counter_swap++;
    std::shared_ptr<Node> x = maximum(s);
    splay(x);
    x->right = t;
    t->parent = x;
    counter_swap += 2;
    return x;
}

void Splay::split(std::shared_ptr<Node> &x, std::shared_ptr<Node> &s, std::shared_ptr<Node> &t) {
    splay(x);
    counter_swap++;
    if (x->right) {
        counter_swap += 2;
        t = x->right;
        t->parent = nullptr;
    } else {
        counter_swap += 2;
        t = nullptr;
    }
    s = x;
    s->right = nullptr;
    x = nullptr;
    counter_swap += 3;
} 

std::shared_ptr<Node> Splay::maximum(std::shared_ptr<Node> node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

void Splay::print_recursive(std::shared_ptr<Node> node, int depth, char prefix) {
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

void Splay::print_BST() {
    int size = height_recursive(this->root);
    left_trace = new char[size];
    right_trace = new char[size];

    print_recursive(root, 0, '-');

    delete [] left_trace;
    delete [] right_trace;
}