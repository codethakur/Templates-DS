#include "./Header/GenericTree.h"
#include "PrintTree.cpp"
 #include <iostream>
// #define LOG std::cout<<  // Replace std::cout with LOG
// #define LOGOUT std::endl  // Replace std::endl with LOGOUT

#include"LOG.cpp"
int main()
{

    // Creating tree nodes
    auto root = std::make_shared<GenericTree<char>>('A');
    root->FirstChild = std::make_shared<GenericTree<char>>('B');
    root->FirstChild->nextSibling = std::make_shared<GenericTree<char>>('C');
    root->FirstChild->FirstChild = std::make_shared<GenericTree<char>>('D');

    // Output root data
    #if 0
    std::cout << "Root: " << root->data << std::endl;
    std::cout << "First Child: " << root->FirstChild->data << std::endl;
    std::cout << "Next Sibling of First Child: " << root->FirstChild->nextSibling->data << std::endl;
    std::cout << "First Child of 'B': " << root->FirstChild->FirstChild->data << std::endl;
    #endif
    GenericBinaryTree genericTree;
    LOG("total child");
    LOG(genericTree.ChildCount(root));
    LOG("Toal sibling");
    LOG(genericTree.siblingCount(root));

    system("pause>0");

    return 0;
}
