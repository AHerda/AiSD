#pragma once

#include <iostream>
#include <queue>
#include <climits>
#include <cmath>

struct Node
{
    int key;
    int order;
    Node *sibling, *parent, *child;

    Node(int key)
    {
        this -> key = key;
        this -> order = 0;
        this -> sibling = this -> parent = this -> child = nullptr;
    }
};

class BHeap
{
    int counter_if;
    int counter_if_temp;
    Node *head;
    Node *min;
    
    auto combineTrees(Node *root1, Node *root2) -> void;
    auto combineHeaps(BHeap *heap1, BHeap *heap2) -> Node*;

public:
    auto reset_counter() -> void;
    auto reset_counter_temp() -> void;
    auto get_counter() -> int;
    auto get_counter_temp() -> int;
    auto counter_increase() -> void;

    BHeap();
    BHeap(Node* root);
    auto isEmpty() -> bool;
    auto insert(Node* root) -> void;
    auto unionHeap(BHeap *heap) -> void;
    auto first() -> Node*;
    auto extractMin() -> Node*;
    auto decreaseKey(Node *root, int val) -> void;
    auto Delete(Node *root) -> void;
    auto printTree(Node* root) -> void;
    auto printHeap() -> void;
};