#pragma once
#include <memory>
#include <string>
#include <vector>

struct Node {
	int key;
	std::shared_ptr<Node> parent;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

    Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};


class SBST
{
private:
    std::shared_ptr<Node> root;
    char* left_trace;
    char* right_trace;

private:
    auto rotateLeft(std::shared_ptr<Node>) -> void;
    auto rotateRight(std::shared_ptr<Node>) -> void;
    auto splay(std::shared_ptr<Node>) -> void;
    auto join(std::shared_ptr<Node>, std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto split(std::shared_ptr<Node>, std::shared_ptr<Node> &, std::shared_ptr<Node> &) -> void;
    auto printTreeHelper(std::shared_ptr<Node>, std::string, bool) -> void;
    auto preOrderHelper(std::shared_ptr<Node>) -> void;
    auto inOrderHelper(std::shared_ptr<Node>) -> void;
    auto postOrderHelper(std::shared_ptr<Node>) -> void;
    auto deleteNodeHelper(std::shared_ptr<Node>, int) -> void;
    auto searchInTreeHelper(std::shared_ptr<Node>, int) -> std::shared_ptr<Node>;
    auto height_recursive(std::shared_ptr<Node> node) -> int;
    auto print_recursive(std::shared_ptr<Node> node, int depth, char prefix) -> void;

public:
    long long counter_if;
    long long counter_swap;

    SBST();
    auto preorder() -> void;
    auto inorder() -> void;
    auto postorder() -> void;
    auto searchInTree(int) -> std::shared_ptr<Node>;
    auto minimum(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto maximum(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto successor(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto predecessor(std::shared_ptr<Node>) -> std::shared_ptr<Node>;
    auto insert(int) -> void;
    auto getRoot() -> std::shared_ptr<Node>;

    auto remove(int) -> void;
    auto height() -> int;
    auto print_BST() -> void;
};