#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

void RedBlackTree::InsertElement(char key) {
    Node **walk = &root;
    while (*walk) {
        char currentKey = *((*walk)->key);
        if (key > currentKey)
            walk = &(*walk)->right;
        else
            walk = &(*walk)->left;
    }
    *walk = new Node(&key);

    fixRuleViolations(*walk);
}

void RedBlackTree::fixRuleViolations(Node *node) {
    while (node != root && node->parent->color == RED) {
        Node *parent = node->parent;
        Node *grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(node);
                    node = parent;
                }
                rightRotate(parent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        } else {
            Node *uncle = grandparent->left;
            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(node);
                    node = parent;
                }
                leftRotate(parent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(Node *x) {
    Node *y = x->right;

    x->right = y->left;

    if (x->right != nullptr) {
        x->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node *y) {
    Node *x = y->left;

    y->left = x->right;

    if (y->left != nullptr) {
        y->left->parent = x;
    }

    x->parent = y->parent;

    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

Node *RedBlackTree::search(char key) {
    Node **walk = &root;
    while (*walk) {
        char currentKey = *((*walk)->key);
        if (currentKey == key) {
            return *walk;
        }
        if (key > currentKey)
            walk = &(*walk)->right;
        else
            walk = &(*walk)->left;
    }

    return nullptr;
}

std::pair<char *, char *> RedBlackTree::getChildrenNodesValues(const char *key) {
    if (key == nullptr) return std::pair<char *, char *>(root->left->key, root->right->key);

    Node *node = search(*key);

    return std::pair<char *, char *>(node->left->key, node->right->key);
}

bool RedBlackTree::isRedNode(const char *key) {
    return search(*key)->color == RED;
}

char *RedBlackTree::getRootNode() {
    return root->key;
}

std::string RedBlackTree::PreOrderTraversal() {
}

std::string RedBlackTree::PostOrderTraversal() {
    return std::__cxx11::string();
}

