#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

RedBlackTree::~RedBlackTree() {
    delete root;
}

void RedBlackTree::InsertElement(const char key) {
    Node **walk = &root;
    Node *prev = nullptr;
    while (*walk) {
        prev = *walk;
        char currentKey = (*walk)->key;
        if (key < currentKey)
            walk = &(*walk)->left;
        else
            walk = &(*walk)->right;
    }
    *walk = new Node(key);
    (*walk)->parent = prev;

    fixRuleViolations(*walk);
}

void RedBlackTree::fixRuleViolations(Node *node) {
    while (node != root && node->parent->color == RED) {
        Node *parent = node->parent;
        Node *grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (uncle && uncle->color == RED) {
                parent->color = uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(parent);
                    std::swap(node, parent);
                }
                rightRotate(grandparent);
                std::swap(parent->color, grandparent->color);
            }
        } else {
            Node *uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                parent->color = uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(parent);
                    std::swap(node, parent);
                }
                leftRotate(grandparent);
                std::swap(parent->color, grandparent->color);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(Node *parent) {
    Node *node = parent->right;

    parent->right = node->left;

    if (parent->right) {
        parent->right->parent = parent;
    }

    Node *grandparent = parent->parent;
    if (!grandparent) {
        root = node;
    } else if (parent == grandparent->left) {
        grandparent->left = node;
    } else {
        grandparent->right = node;
    }
    node->parent = grandparent;

    node->left = parent;
    parent->parent = node;
}

void RedBlackTree::rightRotate(Node *parent) {
    Node *node = parent->left;

    parent->left = node->right;

    if (parent->left) {
        parent->left->parent = parent;
    }

    Node *grandparent = parent->parent;
    if (!grandparent) {
        root = node;
    } else if (parent == grandparent->left) {
        grandparent->left = node;
    } else {
        grandparent->right = node;
    }
    node->parent = grandparent;

    node->right = parent;
    parent->parent = node;
}

Node *RedBlackTree::search(char key) {
    Node *walk = root;
    while (walk) {
        char currentKey = walk->key;
        if (currentKey == key) return walk;
        if (key < currentKey)
            walk = walk->left;
        else
            walk = walk->right;
    }

    return nullptr;
}

std::pair<char *, char *> RedBlackTree::getChildrenNodesValues(const char *key) {
    Node *node = key ? search(*key) : root;
    Node *left = node->left;
    Node *right = node->right;

    return std::pair<char *, char *>(left ? &(left->key) : nullptr, right ? &(right->key) : nullptr);
}

bool RedBlackTree::isRedNode(const char *key) {
    Node *node = search(*key);
    return node != nullptr && node->color == RED;
}

char *RedBlackTree::getRootNode() {
    return root ? &(root->key) : nullptr;
}

std::string RedBlackTree::PreOrderTraversal() {
    std::string preOrder;
    preOrderRec(root, preOrder);
    return preOrder;
}

void RedBlackTree::preOrderRec(Node *node, std::string &preOrder) {
    if (!node) return;

    preOrder += node->key;
    preOrderRec(node->left, preOrder);
    preOrderRec(node->right, preOrder);
}

std::string RedBlackTree::PostOrderTraversal() {
    std::string postOrder;
    postOrderRec(root, postOrder);
    return postOrder;
}

void RedBlackTree::postOrderRec(Node *node, std::string &postOrder) {
    if (!node) return;

    postOrderRec(node->left, postOrder);
    postOrderRec(node->right, postOrder);
    postOrder += node->key;
}