#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

void RedBlackTree::InsertElement(char key) {
    Node *node = new Node(&key);

}

void RedBlackTree::fixRuleViolations(Node *node) {
    while (node->parent->color == RED) {
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
                    leftRotate(node, parent);
                    node = parent;
                }
                rightRotate(parent, grandparent);
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
                    rightRotate(node, parent);
                    node = parent;
                }
                leftRotate(parent, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::leftRotate(Node *node, Node *parent) {

}

void RedBlackTree::rightRotate(Node *node, Node *parent) {

}

std::pair<char *, char *> RedBlackTree::getChildrenNodesValues(char *key) {
    return std::pair<char *, char *>();
}

bool RedBlackTree::isRedNode(char *key) {
    return false;
}

char *RedBlackTree::getRootNode() {
    return root->key;
}

std::string RedBlackTree::PreOrderTraversal() {
    return std::__cxx11::string();
}

std::string RedBlackTree::PostOrderTraversal() {
    return std::__cxx11::string();
}

