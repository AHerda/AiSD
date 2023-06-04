#include "SBST.hpp"
#include <iostream>
#include <memory>

SBST::SBST() : root(nullptr), counter_if(0), counter_swap(0) {}

auto SBST::getRoot() -> std::shared_ptr<Node>
{
    return root;
}

auto SBST::rotateLeft(std::shared_ptr<Node> x) -> void
{
    counter_swap+=3;
    auto y = x->right;
    x->right = y->left;

    if (y->left != nullptr){
        y->left->parent = x;
        counter_swap++;
    }
    counter_swap+=2;
    y->parent = x->parent;
    if (x->parent == nullptr){
        this->root = y;
        counter_swap++;
    }
    else if (x == x->parent->left){
        x->parent->left = y;
        counter_swap+=2;
    }
    else{
        x->parent->right = y;
        counter_swap+=2;
    }

    counter_swap+=2;
    y->left = x;
    x->parent = y;
}

auto SBST::rotateRight(std::shared_ptr<Node> x) -> void
{
    counter_swap+=3;
    auto y = x->left;
    x->left = y->right;

    if (y->right != nullptr){
        y->right->parent = x;
        counter_swap++;
    }
    counter_swap+=2;
    y->parent = x->parent;
    if (x->parent == nullptr){
        counter_swap++;
        this->root = y;
    }
    else if (x == x->parent->right){
        x->parent->right = y;
        counter_swap+=2;
    }
    else{
        x->parent->left = y;
        counter_swap+=2;
    }

    counter_swap+=2;
    y->right = x;
    x->parent = y;
}

auto SBST::splay(std::shared_ptr<Node> x) -> void
{
    counter_swap++;
    while (x->parent)
    {
        counter_swap++;
        if (!x->parent->parent)
        {
            counter_swap++;
            if (x == x->parent->left)
            {
                rotateRight(x->parent);
            }
            else
            {
                rotateLeft(x->parent);
            }
        }
        else if (x == x->parent->left && x->parent == x->parent->parent->left)
        {
            counter_swap++;
            rotateRight(x->parent->parent);
            rotateRight(x->parent);
        }
        else if (x == x->parent->right && x->parent == x->parent->parent->right)
        {
            counter_swap+=2;
            rotateLeft(x->parent->parent);
            rotateLeft(x->parent);
        }
        else if (x == x->parent->right && x->parent == x->parent->parent->left)
        {
            counter_swap+=3;
            rotateLeft(x->parent);
            rotateRight(x->parent);
        }
        else
        {
            counter_swap+=3;
            rotateRight(x->parent);
            rotateLeft(x->parent);
        }
    }
}

auto SBST::minimum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    counter_swap++;
    if (node->left == nullptr)
        return node;
    return minimum(node->left);
}

auto SBST::maximum(std::shared_ptr<Node> node) -> std::shared_ptr<Node>
{
    if (node->right == nullptr)
        return node;
    return maximum(node->right);
}

auto SBST::join(std::shared_ptr<Node> leftSubtree, std::shared_ptr<Node> rightSubtree) -> std::shared_ptr<Node>
{
    if (leftSubtree == nullptr || rightSubtree == nullptr)
        return (leftSubtree != nullptr) ? leftSubtree : rightSubtree;

    auto x = maximum(leftSubtree);
    splay(x);

    counter_swap+=2;
    x->right = rightSubtree;
    x->parent = x;

    return x;
}

auto SBST::split(std::shared_ptr<Node> x, std::shared_ptr<Node> &leftSubtree, std::shared_ptr<Node> &rightSubtree) -> void
{
    splay(x);
    counter_swap++;
    if (x->right)
    {
        counter_swap+=2;
        rightSubtree = x->right;
        rightSubtree->parent = nullptr;
    }
    else
    {
        counter_swap++;
        rightSubtree = nullptr;
    }

    counter_swap+=3;
    leftSubtree = x;
    leftSubtree->right = nullptr;
    if (rightSubtree)
    {
        counter_swap++;
        rightSubtree->parent = nullptr;
    }
}



auto SBST::insert(int key) -> void
{
    auto node = std::make_shared<Node>(key);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;
    std::shared_ptr<Node> y = nullptr;
    auto x = this->root;
    counter_swap+=7;

    while (x != nullptr)
    {
        counter_swap+=3;
        y = x;
        counter_if++;
        if (node->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    counter_swap+=2;
    node->parent = y;
    if (y == nullptr)
    {
        counter_swap++;
        root = node;
    }
    else if (node->key < y->key)
    {
        counter_swap++;
        counter_if++;
        y->left = node;
    }
    else
    {
        counter_swap++;
        counter_if++;
        y->right = node;
    }

    splay(node);
}

auto SBST::preOrderHelper(std::shared_ptr<Node> node) -> void
{
    if (node != nullptr)
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
    if (node != nullptr)
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
    if (node != nullptr)
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

auto SBST::searchInTree(int key) -> std::shared_ptr<Node>
{
    auto x = searchInTreeHelper(root, key);
    if (x)
    {
        splay(x);
    }
    return x;
}

auto SBST::successor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    counter_swap++;
    if (x->right != nullptr)
    {
        return minimum(x->right);
    }

    counter_swap+=3;
    auto y = x->parent;
    while (y != nullptr && x == y->right)
    {
        counter_swap+=3;
        x = y;
        y = y->parent;
    }

    return y;
}

auto SBST::predecessor(std::shared_ptr<Node> x) -> std::shared_ptr<Node>
{
    counter_swap++;
    if (x->left != nullptr)
    {
        return maximum(x->left);
    }

    counter_swap+=3;
    auto y = x->parent;
    while (y != nullptr && x == y->left)
    {
        counter_swap+=3;
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
    counter_swap+=3;
    while (currentNode != nullptr)
    {
        counter_swap++;
        counter_if++;
        if (currentNode->key == key)
        {
            counter_swap++;
            x = currentNode;
            break;
        }

        counter_if++;
        if (currentNode->key < key)
        {
            counter_swap++;
            currentNode = currentNode->right;
        }
        else
        {
            counter_swap++;
            currentNode = currentNode->left;
        }
    }

    counter_swap++;
    if (x == nullptr)
    {
        return;
    }

    splay(x);
    counter_swap++;
    if (!x->left)
    {
        counter_swap+=2;
        root = x->right;
        if (root)
        {
            counter_swap++;
            root->parent = nullptr;
        }
        return;
    }
    else if (!x->right)
    {
        counter_swap+=3;
        root = x->left;
        if (root)
        {
            counter_swap++;
            root->parent = nullptr;
        }
        return;
    }

    auto maxLeft = maximum(x->left);
    splay(maxLeft);
    maxLeft->right = x->right;
    counter_swap+=3;
    if (maxLeft->right)
    {
        counter_swap++;
        maxLeft->right->parent = maxLeft;
    }

    counter_swap+=2;
    root = maxLeft;
    root->parent = nullptr;
}

auto SBST::remove(int key) -> void
{
    deleteNodeHelper(root, key);
}

auto SBST::height_recursive(std::shared_ptr<Node> node) -> int
{
    if (node == nullptr)
        return 0;
    int leftHeight = height_recursive(node->left);
    int rightHeight = height_recursive(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

auto SBST::height() -> int {
    return height_recursive(root);
}

auto SBST::print_recursive(std::shared_ptr<Node> node, int depth, char prefix) -> void {
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