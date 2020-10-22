#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <cstdio>
#include <utility>
#include <string>

enum Color {
    RED, BLACK
};

struct Node {
    char key;
    bool color;
    Node *left, *right, *parent;

    explicit Node(char key) {
        this->key = key;
        left = right = parent = nullptr;
        color = RED;
    }

    ~Node() {
        delete parent;
        delete left;
        delete right;
    }
};

class RedBlackTree {
private:
    Node *root;

    void fixRuleViolations(Node *node);

    void leftRotate(Node *parent);

    void rightRotate(Node *parent);

    Node *search(char target);

    static std::string preOrderRec(Node *node);

    static std::string postOrderRec(Node *node);

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
