#pragma once
#include <memory>
#include <string>

enum class Color
{
    RED,
    BLACK
};

struct Node
{
    int key;
    Color color;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> parent;

    Node(int key) {
        this->key = key;
        left, right, parent = nullptr, nullptr, nullptr;
    }
    Node(int key, Color color) {
        this->key = key;
        this->color = color;
        left, right, parent = nullptr, nullptr, nullptr;
    }
};

class RBBST
{
private:
    std::shared_ptr<Node> root;
    char* left_trace;
    char* right_trace;

    auto rotateLeft(std::shared_ptr<Node>) -> void;
    auto rotateRight(std::shared_ptr<Node>) -> void;
    auto fixInsertion(std::shared_ptr<Node>) -> void;
    auto printTreeHelper(std::shared_ptr<Node>, std::string, bool) -> void;
    auto deleteByKey(std::shared_ptr<Node>, int) -> std::shared_ptr<Node>;
    auto minimum(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto maximum(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto searchInTreeHelper(std::shared_ptr<Node> node, int key) -> std::shared_ptr<Node>;
    auto preOrderHelper(std::shared_ptr<Node>) -> void;
    auto postOrderHelper(std::shared_ptr<Node>) -> void;
    auto inOrderHelper(std::shared_ptr<Node>) -> void;
    auto print_recursive(std::shared_ptr<Node> node, int depth, char prefix) -> void;
    auto height_recursive(std::shared_ptr<Node> node) -> int;

public:
    long long counter_if;
    long long counter_swap;

    RBBST();
    auto deleteTree(std::shared_ptr<Node>) -> void;
    auto inorder() -> void;
    auto insert(int) -> void;
    auto predecessor(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto preorder() -> void;
    auto postorder() -> void;
    auto remove(int) -> void;
    auto successor(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto searchInTree(int key) -> std::shared_ptr<Node>;
    auto getRoot() -> std::shared_ptr<Node>;
    auto print_BST() -> void;
    auto height() -> int;
};