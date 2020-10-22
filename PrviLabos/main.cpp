#include <iostream>
#include "RedBlackTree.h"

int main() {
    RedBlackTree redBlackTree = RedBlackTree();
    redBlackTree.InsertElement('2');
    redBlackTree.InsertElement('4');
    redBlackTree.InsertElement('3');
    redBlackTree.InsertElement('7');
    redBlackTree.InsertElement('8');
    redBlackTree.InsertElement('1');
    redBlackTree.InsertElement('0');
    redBlackTree.InsertElement('2');
    redBlackTree.InsertElement('5');
    redBlackTree.InsertElement('1');
    redBlackTree.InsertElement('0');
    redBlackTree.InsertElement('0');
    redBlackTree.InsertElement('4');
    redBlackTree.InsertElement('7');
    redBlackTree.InsertElement('7');
    redBlackTree.InsertElement('3');
    redBlackTree.InsertElement('3');

    std::cout << redBlackTree.PostOrderTraversal();
    std::cout << std::endl;
    std::cout << redBlackTree.PreOrderTraversal();
    std::cout << std::endl;

    redBlackTree.print();
}
