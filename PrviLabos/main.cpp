#include <iostream>
#include "RedBlackTree.h"

int main() {
    RedBlackTree redBlackTree = RedBlackTree();
    redBlackTree.InsertElement('V');
    redBlackTree.InsertElement('T');
    redBlackTree.InsertElement('A');
    redBlackTree.InsertElement('Y');
    redBlackTree.InsertElement('K');
    redBlackTree.InsertElement('R');
    redBlackTree.InsertElement('I');
    redBlackTree.InsertElement('O');
    redBlackTree.InsertElement('H');
    redBlackTree.InsertElement('F');
    redBlackTree.InsertElement('Q');

    std::cout << redBlackTree.PostOrderTraversal();
    std::cout << std::endl;
    std::cout << redBlackTree.PreOrderTraversal();
    std::cout << std::endl;
}
