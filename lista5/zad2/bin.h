#pragma once
#include <memory>
#include <vector>
#include <limits.h>

struct Node
{
    std::shared_ptr<Node> child;
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> sibling;
    int key;
    int degree;

    Node(int key) : key(key), degree(0), parent(nullptr), sibling(nullptr) {}
};

class BinHeap
{
private:
    std::shared_ptr<Node> head;

public:
    BinHeap();
    auto getHead() -> std::shared_ptr<Node>;
    auto setHead(std::shared_ptr<Node> head) -> void;
    auto minimum() -> std::shared_ptr<Node>;
};

auto link(std::shared_ptr<BinHeap> H1, std::shared_ptr<BinHeap> H2) -> void;
auto merge(std::shared_ptr<BinHeap> H1, std::shared_ptr<BinHeap> H2) -> std::shared_ptr<Node>;
auto bhUnion(std::shared_ptr<BinHeap> H1, std::shared_ptr<BinHeap> H2) -> std::shared_ptr<BinHeap>;