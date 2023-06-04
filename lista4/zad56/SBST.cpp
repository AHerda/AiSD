#include "SBST.hpp"
#include <iostream>
#include <memory>

SBST::SBST() : root(nullptr), counter_if(0), counter_swap(0) {}

auto SBST::getRoot() -> std::shared_ptr<Node>
{
    return root;
}

auto SBST::rotateLeft(std::shared_ptr<Node> node) -> void
{
    counter_swap+=2;
    auto y = node->right;
    node->right = y->left;

    counter_swap++;
    if(y->left != nullptr) {
        y->left->parent = node;
        counter_swap++;
    }

    counter_swap+=2;
    y->parent = node->parent;

    if(node->parent == nullptr){
        counter_swap++;
        this->root = y;
    }
    else if(node == node->parent->left){
        counter_swap+=2;
        node->parent->left = y;
    }
    else{
        node->parent->right = y;
        counter_swap+=2;
    }

    counter_swap+=2;
    y->left = node;
    node->parent = y;
}

auto SBST::rotateRight(std::shared_ptr<Node> node) -> void
{
    counter_swap+=3;
    auto y = node->left;
    node->left = y->right;

    if(y->right != nullptr) {
        counter_swap++;
        y->right->parent = node;
    }

    counter_swap+=2;
    y->parent = node->parent;
    if(node->parent == nullptr){
        counter_swap++;
        this->root = y;
    }
    else if(node == node->parent->right){
        counter_swap+=2;
        node->parent->right = y;
    }
    else{
        counter_swap+=2;
        node->parent->left = y;
    }

    counter_swap+=2;
    y->right = node;
    node->parent = y;
}

auto SBST::splay(std::shared_ptr<Node> node) -> void
{
    while (node->parent)
    {
        if(!node->parent->parent)
        {
            if(node == node->parent->left)
            {
                rotateRight(node->parent);
            }
            else
            {
                rotateLeft(node->parent);
            }
        }
        else if(node == node->parent->left && node->parent == node->parent->parent->left)
        {
            rotateRight(node->parent->parent);
            rotateRight(node->parent);
        }
        else if(node == node->parent->right && node->parent == node->parent->parent->right)
        {
            rotateLeft(node->parent->parent);
            rotateLeft(node->parent);
        }
        else if(node == node->parent->right && node->parent == node->parent->parent->left)
        {
            rotateLeft(node->parent);
            rotateRight(node->parent);
        }
        else
        {
            rotateRight(node->parent);
            rotateLeft(node->parent);
        }
    }
}

auto SBST::minimum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    if(node->left == nullptr)
        return node;
    return minimum(node->left);
}

auto SBST::maximum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    if(node->right == nullptr)
        return node;
    return maximum(node->right);
}

auto SBST::join(std::shared_ptr<Node> leftSubtree, std::shared_ptr<Node> rightSubtree) -> std::shared_ptr<Node>
{
    if(leftSubtree == nullptr || rightSubtree == nullptr)
        return leftSubtree ? leftSubtree : rightSubtree;

    auto x = maximum(leftSubtree);
    splay(x);
    x->right = rightSubtree;
    x->parent = x;

    return x;
}

auto SBST::split(std::shared_ptr<Node> node, std::shared_ptr<Node> &leftSubtree, std::shared_ptr<Node> &rightSubtree) -> void
{
    splay(node);
    if(node->right)
    {
        rightSubtree = node->right;
        rightSubtree->parent = nullptr;
    }
    else
    {
        rightSubtree = nullptr;
    }
    leftSubtree = node;
    leftSubtree->right = nullptr;
    if(rightSubtree)
    {
        rightSubtree->parent = nullptr;
    }
}

void SBST::print_recursive(std::shared_ptr<Node> node, int depth, char prefix) {
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

void SBST::print_BST() {
    int size = height_recursive(root);
    left_trace = new char[size];
    right_trace = new char[size];

    print_recursive(root, 0, '-');

    delete [] left_trace;
    delete [] right_trace;
}

auto SBST::insert(int key) -> void
{
    auto node = std::make_shared<Node>(key);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    std::shared_ptr<Node> y = nullptr; // jawnie musze pokazac ze przypisuje nullptr
    auto x = this->root;

    while (x != nullptr)
    {
        y = x;
        if(node->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    node->parent = y;
    if(y == nullptr)
    {
        node = node;
    }
    else if(node->key < y->key)
    {
        y->left = node;
    }
    else
    {
        y->right = node;
    }

    splay(node);
}

auto SBST::preOrderHelper(std::shared_ptr<Node> node) -> void
{
    if(node != nullptr)
    {
        std::cout << node->key << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

auto SBST::preorder() -> void
{
    preOrderHelper(root);
}

auto SBST::inOrderHelper(std::shared_ptr<Node> node) -> void
{
    if(node != nullptr)
    {
        inOrderHelper(node->left);
        std::cout << node->key << " ";
        inOrderHelper(node->right);
    }
}

auto SBST::inorder() -> void
{
    inOrderHelper(root);
}

auto SBST::postOrderHelper(std::shared_ptr<Node> node) -> void
{
    if(node != nullptr)
    {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->key << " ";
    }
}

auto SBST::postorder() -> void
{
    postOrderHelper(root);
}

auto SBST::searchInTreeHelper(std::shared_ptr<Node> node, int key) -> std::shared_ptr<Node>
{
    if(node == nullptr || key == node->key)
    {
        return node;
    }

    if(key < node->key)
    {
        return searchInTreeHelper(node->left, key);
    }
    return searchInTreeHelper(node->right, key);
}

auto SBST::searchInTree(int key) -> std::shared_ptr<Node>
{
    auto x = searchInTreeHelper(root, key);
    if(x)
    {
        splay(x);
    }
    return x;
}

auto SBST::successor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    if(x->right != nullptr)
    {
        return minimum(x->right);
    }

    auto y = x->parent;
    while (y != nullptr && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

auto SBST::predecessor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    if(x->left != nullptr)
    {
        return maximum(x->left);
    }

    auto y = x->parent;
    while (y != nullptr && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

auto SBST::deleteNodeHelper(std::shared_ptr<Node> node, int key) -> void
{
    std::shared_ptr<Node> x = nullptr;
    std::shared_ptr<Node> t, s;
    std::shared_ptr<Node> currentNode = node;
    while (currentNode != nullptr)
    {
        if(currentNode->key == key)
        {
            x = currentNode;
            break;
        }

        if(currentNode->key < key)
        {
            currentNode = currentNode->right;
        }
        else
        {
            currentNode = currentNode->left;
        }
    }

    if(x == nullptr)
    {
        return;
    }

    splay(x);

    if(!x->left)
    {
        node = x->right;
        if(node)
        {
            node->parent = nullptr;
        }
        return;
    }
    else if(!x->right)
    {
        node = x->left;
        if(node)
        {
            node->parent = nullptr;
        }
        return;
    }

    auto maxLeft = maximum(x->left);
    splay(maxLeft);

    maxLeft->right = x->right;

    if(maxLeft->right)
    {
        maxLeft->right->parent = maxLeft;
    }

    node = maxLeft;
    maxLeft->parent = nullptr;
}

auto SBST::remove(int key) -> void
{
    deleteNodeHelper(root, key);
}

auto SBST::height_recursive(std::shared_ptr<Node> node) -> int {
    if(node == nullptr) return 0;

    int lh = height_recursive(node->left);
    int rh = height_recursive(node->right);

    return std::max(lh, rh) + 1;
}

auto SBST::height() -> int {
    return height_recursive(root);
}