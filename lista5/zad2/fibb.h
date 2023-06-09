#pragma once

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

struct Node
{
    Node *left;
    Node *right;
    Node *parent;
    Node *child;
    int key;
    int degree;
    bool marked;

    Node(int key)
    {
        this->key = key;
        this->degree = 0;
        this->marked = false;
        this->left = this->right = this->parent = this->child = nullptr;
    }

    Node()
    {
        this->key = 0;
        this->degree = 0;
        this->marked = false;
        this->left = this->right = this->parent = this->child = nullptr;
    }
};

class FibHeap
{
    Node *min;
    int N;
    int counter_if;
    int counter_if_temp;
    
public:
    auto reset_counter() -> void;
    auto reset_counter_temp() -> void;
    auto get_counter() -> int;
    auto get_counter_temp() -> int;
    auto counter_increase() -> void;

    FibHeap();
    FibHeap(Node*);
    auto isEmpty() -> bool;
    auto insert(Node*) -> void;
    auto Union(FibHeap*) -> void;
    auto first() -> Node*;
    auto extractMin() -> Node*;
    auto decreaseKey(Node*, int) -> void;
    auto Delete(Node*) -> void;
};