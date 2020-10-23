#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

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

    static void preOrderRec(Node *node, std::string &preOrder);

    static void postOrderRec(Node *node, std::string &postOrder);

public:
    RedBlackTree();

    ~RedBlackTree();

    void InsertElement(char key);

    Node *search(char key);

    std::pair<char *, char *> getChildrenNodesValues(const char *key = nullptr);

    bool isRedNode(const char *key = nullptr);

    char *getRootNode();

    std::string PreOrderTraversal();

    std::string PostOrderTraversal();
};

#endif
