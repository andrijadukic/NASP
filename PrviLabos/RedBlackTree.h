#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <cstdio>
#include <utility>
#include <string>

enum Color {
    RED, BLACK
};

struct Node {
    char *key;
    bool color;
    Node *left, *right, *parent;

    explicit Node(char *data) {
        this->key = data;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RedBlackTree {
private:
    Node *root;

    void fixRuleViolations(Node *node);

    void leftRotate(Node *x);

    void rightRotate(Node *y);

    Node *search(char key);

public:
    RedBlackTree();

    void InsertElement(char key);

    std::pair<char *, char *> getChildrenNodesValues(const char *key = nullptr);

    bool isRedNode(const char *key = nullptr);

    char *getRootNode();

    std::string PreOrderTraversal();

    std::string PostOrderTraversal();
};

#endif
