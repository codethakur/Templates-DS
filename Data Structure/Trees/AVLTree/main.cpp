#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include"AVLTree.h"


// **Main function to test AVL Tree**
int main() {
    #if 0
    std::shared_ptr<AVLTreeNode> root = nullptr;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); // LL Case
    root = insert(root, 25); // LR Case
    root = insert(root, 40);
    root = insert(root, 50); // RR Case
    root = insert(root, 35); // RL Case

    std::cout << "In-order traversal of AVL tree: ";
    inOrder(root);
    std::cout << std::endl;


    std::cout << "checkHeight: " << checkHeight(root) << std::endl;
    if (isBalanced(root)) {
        std::cout << "Yes";
    }
    else {
        std::cerr << "NO";
    }

    #endif


    int h = 4; // Height of the AVL tree
    std::shared_ptr<AVLTreeNode> root = GenerateAVL(h);

    std::cout << "Generated AVL Tree (In-Order Traversal): ";
    inOrder(root);
    std::cout << std::endl;
    inOrder(root);
    return 0;
}
