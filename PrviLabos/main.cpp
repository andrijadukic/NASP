#include <iostream>
#include "RedBlackTree.h"

int main() {
    RedBlackTree redBlackTree = RedBlackTree();
    redBlackTree.InsertElement('2');
    redBlackTree.InsertElement('4');
    redBlackTree.InsertElement('3');
    std::cout << redBlackTree.PostOrderTraversal();
}
