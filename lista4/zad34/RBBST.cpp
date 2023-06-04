#include "RBBST.hpp"
#include <iostream>
#include <memory>

RBBST::RBBST() : root(nullptr), counter_if(0), counter_swap(0) {}

auto RBBST::rotateLeft(std::shared_ptr<Node> node) -> void
{
    counter_swap+=2;
    auto y = node->right;
    node->right = y->left;

    if (y->left != nullptr) {
        y->left->parent = node;
        counter_swap++;
    }

    y->parent = node->parent;
    counter_swap++;

    if (node->parent == nullptr) {
        root = y;
        counter_swap++;
    }
    else if (node == node->parent->left) {
        node->parent->left = y;
        counter_swap++;
    }
    else {
        node->parent->right = y;
        counter_swap++;
    }

    counter_swap+=2;
    y->left = node;
    node->parent = y;
}

auto RBBST::rotateRight(std::shared_ptr<Node> node) -> void
{
    counter_swap+=2;
    auto y = node->left;
    node->left = y->right;

    if (y->right != nullptr) {
        y->right->parent = node;
        counter_swap++;
    }

    counter_swap++;
    y->parent = node->parent;

    if (node->parent == nullptr) {
        root = y;
        counter_swap++;
    }
    else if (node == node->parent->left) {
        node->parent->left = y;
        counter_swap++;
        }
    else{
        node->parent->right = y;
        counter_swap++;
    }

    counter_swap+=2;
    y->right = node;
    node->parent = y;
}

auto RBBST::fixInsertion(std::shared_ptr<Node> node) -> void
{
    while (node->parent != nullptr && node->parent->color == Color::RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            auto y = node->parent->parent->right;
            counter_swap++;

            if (y != nullptr && y->color == Color::RED)
            {
                node->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                node->parent->parent->color = Color::RED;
                node = node->parent->parent;
                counter_swap++;
            }
            else
            {
                if (node == node->parent->right)
                {
                    counter_swap++;
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = Color::BLACK;
                node->parent->parent->color = Color::RED;
                rotateRight(node->parent->parent);
                counter_swap++;
            }
        }
        else
        {
            counter_swap++;
            auto y = node->parent->parent->left;
            if (y != nullptr && y->color == Color::RED)
            {
                node->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                node->parent->parent->color = Color::RED;
                node = node->parent->parent;
                counter_swap++;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    counter_swap++;
                    rotateRight(node);
                }
                node->parent->color = Color::BLACK;
                node->parent->parent->color = Color::RED;
                rotateLeft(node->parent->parent);
            }
        }
    }
    root->color = Color::BLACK;
}

auto RBBST::insert(int key) -> void
{
    auto z = std::make_shared<Node>(key);
    std::shared_ptr<Node> y = nullptr;
    std::shared_ptr<Node> x = root;

    while (x != nullptr)
    {
        y = x;
        counter_swap++;
        if (z->key < x->key){
            x = x->left;
            counter_swap+=2;
        }
        else{
            x = x->right;
            counter_swap+=2;
        }
    }

    counter_swap++;
    z->parent = y;
    if (y == nullptr){
        root = z;
        counter_swap+=2;
    }
    else if (z->key < y->key){
        counter_if+=2;
        y->left = z;
        counter_swap++;
    }
    else{
        counter_if+=2;
        y->right = z;
        counter_swap++;
    }

    fixInsertion(z);
}

void RBBST::print_recursive(std::shared_ptr<Node> node, int depth, char prefix){
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
    std::cout << "[" << node->key << ((node->color == Color::BLACK) ? "] BLACK" : "] RED") << std::endl;

    left_trace[depth] = ' ';
    if(node->right != nullptr) {
        right_trace[depth] = '|';
        print_recursive(node->right, depth + 1, '\\');
    }
}

void RBBST::print_BST() {
    int size = height_recursive(root);
    left_trace = new char[size];
    right_trace = new char[size];

    print_recursive(root, 0, '-');

    delete [] left_trace;
    delete [] right_trace;
}

auto RBBST::deleteTree(std::shared_ptr<Node> node) -> void
{
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    if (node->parent)
    {
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else if (node == node->parent->right)
            node->parent->right = nullptr;
    }

    node.reset();
    root.reset();
}

auto RBBST::minimum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    if (node->left == nullptr){
        counter_swap++;
        return node;
    }
    return minimum(node->left);
}

auto RBBST::maximum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    counter_swap++;
    if (node->right == nullptr)
        return node;
    return maximum(node->right);
}

auto RBBST::deleteByKey(std::shared_ptr<Node> node, int key) -> std::shared_ptr<Node>
{
    counter_swap++;
    if (node == nullptr)
        return nullptr;

    counter_if++;
    if (key < node->key){
        node->left = deleteByKey(node->left, key);
        counter_swap++;
    }
    else if (key > node->key){
        counter_if++;
        node->right = deleteByKey(node->right, key);
        counter_swap++;
    }
    else
    {
        counter_if++;
        counter_swap+=2;
        if (node->left == nullptr && node->right == nullptr)
        {
            return nullptr;
        }
        else if (node->left == nullptr)
        {
            counter_swap+=2;
            std::shared_ptr<Node> temp = node->right;
            return temp;
        }
        else if (node->right == nullptr)
        {
            counter_swap+=3;
            std::shared_ptr<Node> temp = node->left;
            return temp;
        }
        else
        {
            counter_swap+=5;
            std::shared_ptr<Node> minNode = minimum(node->right);
            node->key = minNode->key;
            node->right = deleteByKey(node->right, minNode->key);
        }
    }

    return node;
}

auto RBBST::remove(int key) -> void
{
    root = deleteByKey(root, key);
    counter_swap++;
}

auto RBBST::searchInTreeHelper(std::shared_ptr<Node> node, int key) -> std::shared_ptr<Node>
{
    if (node == nullptr || key == node->key)
    {
        return node;
    }

    if (key < node->key)
    {
        return searchInTreeHelper(node->left, key);
    }
    return searchInTreeHelper(node->right, key);
}

auto RBBST::searchInTree(int key) -> std::shared_ptr<Node>
{
    return searchInTreeHelper(root, key);
}

auto RBBST::getRoot() -> std::shared_ptr<Node>
{
    return root;
}

auto RBBST::successor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    if (x->right != nullptr)
    {
        return minimum(x->right);
    }

    std::shared_ptr<Node> y = x->parent;
    counter_swap+=3;
    while (y != nullptr && x == y->right)
    {
        counter_swap+=4;
        x = y;
        y = y->parent;
    }

    return y;
}

auto RBBST::predecessor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    if (x->left != nullptr)
    {
        return maximum(x->left);
    }

    std::shared_ptr<Node> y = x->parent;
    while (y != nullptr && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

auto RBBST::preOrderHelper(std::shared_ptr<Node> node) -> void
{
    if (node != nullptr)
    {
        std::cout << node->key << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

auto RBBST::preorder() -> void
{
    preOrderHelper(this->root);
}

auto RBBST::postOrderHelper(std::shared_ptr<Node> node) -> void
{
    if (node != nullptr)
    {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->key << " ";
    }
}

auto RBBST::postorder() -> void
{
    postOrderHelper(root);
}

auto RBBST::inOrderHelper(std::shared_ptr<Node> node) -> void
{
    if (node != nullptr)
    {
        inOrderHelper(node->left);
        std::cout << node->key << " ";
        inOrderHelper(node->right);
    }
}

auto RBBST::inorder() -> void
{
    inOrderHelper(root);
}

int RBBST::height() {
    return height_recursive(root);
}
int RBBST::height_recursive(std::shared_ptr<Node> node) {
    if(node == nullptr) return 0;

    int lh = height_recursive(node->left);
    int rh = height_recursive(node->right);

    return std::max(lh, rh) + 1;
}
