#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

void RedBlackTree::InsertElement(char key) {
    Node **walk = &root;
    Node *prev = nullptr;
    while (*walk) {
        prev = *walk;
        char currentKey = (*walk)->key;
        if (key > currentKey)
            walk = &(*walk)->right;
        else
            walk = &(*walk)->left;
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
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
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
            if (uncle != nullptr && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
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

Node *RedBlackTree::search(char target) {
    Node *walk = root;
    while (walk) {
        char currentKey = walk->key;
        if (currentKey == target) {
            return walk;
        }
        if (target > currentKey)
            walk = walk->right;
        else
            walk = walk->left;
    }

    return nullptr;
}

std::pair<char *, char *> RedBlackTree::getChildrenNodesValues(const char *key) {
    if (key == nullptr) return std::pair<char *, char *>(&(root->left->key), &(root->right->key));

    Node *node = search(*key);

    return std::pair<char *, char *>(&(node->left->key), &(node->right->key));
}

bool RedBlackTree::isRedNode(const char *key) {
    return search(*key)->color == RED;
}

char *RedBlackTree::getRootNode() {
    return &(root->key);
}

std::string RedBlackTree::PreOrderTraversal() {
    return preOrderRec(root);
}

std::string RedBlackTree::PostOrderTraversal() {
    return postOrderRec(root);
}

std::string RedBlackTree::preOrderRec(Node *node) {
    if (node == nullptr) {
        return "";
    }

    std::string postOrder;
    postOrder += node->key;
    std::string left = postOrderRec(node->left);
    std::string right = postOrderRec(node->right);
    postOrder += left.empty() ? "" : left + " ";
    postOrder += right.empty() ? "" : right + " ";
    return postOrder;
}

std::string RedBlackTree::postOrderRec(Node *node) {
    if (node == nullptr) {
        return "";
    }

    std::string postOrder;
    std::string left = postOrderRec(node->left);
    std::string right = postOrderRec(node->right);
    postOrder += left.empty() ? "" : left + " ";
    postOrder += right.empty() ? "" : right + " ";
    return postOrder + node->key;
}

