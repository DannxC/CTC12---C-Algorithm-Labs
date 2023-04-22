#include "RedBlackTree.h"

// Create and initialize a new Node
Node* RedBlackTree::createNode(double key, long value){
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;
    newNode->parent = NIL;
    newNode->left = NIL;
    newNode->right = NIL;

    return newNode;
};

// Constructor: Initialize the RedBlackTree
RedBlackTree::RedBlackTree() {
    NIL = createNode(0, 0);
    NIL->color = BLACK;
    NIL->parent = NIL;
    NIL->left = NIL;
    NIL->right = NIL;

    root = NIL;
    counter = 0;
}

// Destructor: Clean up the RedBlackTree
RedBlackTree::~RedBlackTree() {
    deleteSubTree(root);
    delete NIL;
}

// Get the size of the tree
long RedBlackTree::size() {
    return counter;
}

// Add a new node to the tree
void RedBlackTree::add(double key, long value) {
    Node* newNode = createNode(key, value);
    // newNode->parent = NIL;
    // newNode->left = NIL;
    // newNode->right = NIL;
    insertBST(newNode);
    counter++;
}

// Find nodes within a range
void RedBlackTree::find(std::vector<long> &res, double first, double last) {
    findInRange(root, res, first, last);
}

// Recursively delete subtree
void RedBlackTree::deleteSubTree(Node* node) {
    if (node != NIL) {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        delete node;
    }
}

// Insert node into the binary search tree
void RedBlackTree::insertBST(Node* z) {
    Node* y = NIL;
    Node* x = root;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NIL) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = NIL;
    z->right = NIL;
    z->color = RED;

    fixInsertion(z);
}

// Fix insertion in the Red-Black Tree
void RedBlackTree::fixInsertion(Node* z) {
    // Maintain Red-Black properties
    while (z->parent->color == RED) {
        // Check left subtree
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y->color == RED) {
                // Recolor and move up the tree
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Rotate and recolor
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else { // Check right subtree
            Node* y = z->parent->parent->left;
            if (y->color == RED) {
                // Recolor and move up the tree
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                // Rotate and recolor
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    // Ensure root is always BLACK
    root->color = BLACK;
}

// Rotate the tree to the left
void RedBlackTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    // Update parent pointers
    if (y->left != NIL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    // Update root if necessary
    if (x->parent == NIL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    // Complete the rotation
    y->left = x;
    x->parent = y;
}

// Rotate the tree to the right
void RedBlackTree::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;

    // Update parent pointers
    if (y->right != NIL) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    // Update root if necessary
    if (x->parent == NIL) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }

    // Complete the rotation
    y->right = x;
    x->parent = y;
}

// Find nodes within a range in the tree recursively
void RedBlackTree::findInRange(Node* node, std::vector<long> &res, double first, double last) {
    // Check if the current node's key is within the range
    if (node == NIL) {
        return;
    }

    // Search left subtree if the key is larger than the lower bound
    if (first > node->key) {
        findInRange(node->right, res, first, last);
    }

    // Search right subtree if the key is smaller than the upper bound
    if (node->key > last) {
        findInRange(node->left, res, first, last);
    }

    // Make the real logic if the node is inside the bounderies
    if (first <= node->key && node->key <= last) {
        findInRange(node->left, res, first, last);
        res.push_back(node->value);
        findInRange(node->right, res, first, last);
    }
}
