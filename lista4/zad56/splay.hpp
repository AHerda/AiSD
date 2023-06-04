#pragma once

#include <iostream>
#include <vector>
#include <memory>


struct Node {
	int key;
	std::shared_ptr<Node> parent;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;

    Node(int key) : key(key), parent(nullptr), left(nullptr), right(nullptr) {}
};

class Splay {
private:
	std::shared_ptr<Node> root;
    char* left_trace;
    char* right_trace;

	void remove_recursive(std::shared_ptr<Node> node, int key);
	void leftRotate(std::shared_ptr<Node> x);
	void rightRotate(std::shared_ptr<Node> x);
	void splay(std::shared_ptr<Node> x);
	std::shared_ptr<Node> join(std::shared_ptr<Node> s, std::shared_ptr<Node> t);
    int height_recursive(std::shared_ptr<Node> root);
	void split(std::shared_ptr<Node> &x, std::shared_ptr<Node> &s, std::shared_ptr<Node> &t);
    void print_recursive(std::shared_ptr<Node> node, int depth, char prefix);
public:
    long long counter_if;
    long long counter_swap;

	Splay();
    //~Splay();
    std::shared_ptr<Node> getRoot();
	std::shared_ptr<Node> maximum(std::shared_ptr<Node> node);
	void insert(int key);
	void remove(int data);
    int height();
    void print_BST();
};