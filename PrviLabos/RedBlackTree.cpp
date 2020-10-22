#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

RedBlackTree::~RedBlackTree() {
    delete root;
}

void RedBlackTree::InsertElement(char key) {
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
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    leftRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                rightRotate(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        } else {
            Node *uncle = grandparent->left;
            if (uncle && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rightRotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                leftRotate(grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(Node *parent) {
    Node *node = parent->right;

    parent->right = node->left;

    if (parent->right != nullptr) {
        parent->right->parent = parent;
    }

    node->parent = parent->parent;

    if (parent->parent == nullptr) {
        root = node;
    } else if (parent == parent->parent->left) {
        parent->parent->left = node;
    } else {
        parent->parent->right = node;
    }

    node->left = parent;
    parent->parent = node;
}

void RedBlackTree::rightRotate(Node *parent) {
    Node *node = parent->left;

    parent->left = node->right;

    if (parent->left != nullptr) {
        parent->left->parent = parent;
    }

    node->parent = parent->parent;

    if (parent->parent == nullptr) {
        root = node;
    } else if (parent == parent->parent->left) {
        parent->parent->left = node;
    } else {
        parent->parent->right = node;
    }

    node->right = parent;
    parent->parent = node;
}

Node *RedBlackTree::search(char key) {
    Node *walk = root;
    while (walk) {
        char currentKey = walk->key;
        if (currentKey == key) {
            return walk;
        }
        if (key < currentKey)
            walk = walk->left;
        else
            walk = walk->right;
    }

    return nullptr;
}

std::pair<char *, char *> RedBlackTree::getChildrenNodesValues(char *key) {
    Node *node = key ? search(*key) : root;
    Node *left = node->left;
    Node *right = node->right;

    return std::pair<char *, char *>(left ? &(left->key) : nullptr, right ? &(right->key) : nullptr);
}

bool RedBlackTree::isRedNode(char *key) {
    return search(*key)->color == RED;
}

char *RedBlackTree::getRootNode() {
    return &(root->key);
}

std::string RedBlackTree::PreOrderTraversal() {
    std::string preOrder;
    preOrderRec(root, preOrder);
    return preOrder;
}

std::string RedBlackTree::PostOrderTraversal() {
    std::string postOrder;
    postOrderRec(root, postOrder);
    return postOrder;
}

void RedBlackTree::preOrderRec(Node *node, std::string &preOrder) {
    if (!node) return;

    preOrder += node->key;
    preOrderRec(node->left, preOrder);
    preOrderRec(node->right, preOrder);
}

void RedBlackTree::postOrderRec(Node *node, std::string &postOrder) {
    if (!node) return;

    postOrderRec(node->left, postOrder);
    postOrderRec(node->right, postOrder);
    postOrder += node->key;
}

void RedBlackTree::print() {
    int h = 5;
    int i;
    for (i = 1; i <= h; i++) {
        printRec(root, i);
        printf("\n");
    }
}

void RedBlackTree::printRec(Node *root, int depth) {
    if (root == nullptr)
        return;
    if (depth == 1)
        printf("%c ", root->key);
    else if (depth > 1) {
        printRec(root->left, depth - 1);
        printRec(root->right, depth - 1);
    }
}

