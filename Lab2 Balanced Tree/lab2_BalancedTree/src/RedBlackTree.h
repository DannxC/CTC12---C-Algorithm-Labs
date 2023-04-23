#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <vector>
#include <cstddef>

// Node color enum
enum Color {
    RED,
    BLACK
};

// Node class
class Node {
public:
    double key;
    long value;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

// Red-Black Tree class
class RedBlackTree {
public:
    RedBlackTree();
    ~RedBlackTree();

    long size();

    void add(double key, long idx);

    void find(std::vector<long> &res, double first, double last);

private:
    Node* root;
    Node* NIL;
    size_t counter;

    void deleteSubTree(Node* node);

    Node* createNode(double key, long value);

    void insertBST(Node* newNode);

    void fixInsertion(Node* node);
    void rotateLeft(Node* node);
    void rotateRight(Node* node);

    void findInRange(Node* root, std::vector<long> &res, double first, double last);
};

#endif // RED_BLACK_TREE_H
