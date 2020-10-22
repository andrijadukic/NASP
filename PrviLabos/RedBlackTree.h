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
    Node *left, *right, *parent;
    bool color;

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

    Node *search(char key);

    static void preOrderRec(Node *node, std::string &preOrder);

    static void postOrderRec(Node *node, std::string &postOrder);

    static void printRec(Node *node, int depth);

public:
    RedBlackTree();

    ~RedBlackTree();

    void InsertElement(char key);

    std::pair<char *, char *> getChildrenNodesValues(char *key = nullptr);

    bool isRedNode(char *key = nullptr);

    char *getRootNode();

    std::string PreOrderTraversal();

    std::string PostOrderTraversal();

    void print();
};

#endif
