#include "./Header/Tree.h"
#include "PrintTree.cpp"
#include "./Problems/printAllAncestors.cpp"
#include <iostream>

int main()
{
    auto root1 = std::make_shared<BinaryTreeNode>(1);
    root1->left = std::make_shared<BinaryTreeNode>(2);
    root1->right = std::make_shared<BinaryTreeNode>(3);
    root1->left->left = std::make_shared<BinaryTreeNode>(4);
    root1->left->right = std::make_shared<BinaryTreeNode>(5);
    root1->right->left = std::make_shared<BinaryTreeNode>(6);
    root1->right->right = std::make_shared<BinaryTreeNode>(7);

    auto root2 = std::make_shared<BinaryTreeNode>(1);
    root2->left = std::make_shared<BinaryTreeNode>(2);
    root2->right = std::make_shared<BinaryTreeNode>(3);
    root2->left->left = std::make_shared<BinaryTreeNode>(4);
    root2->left->right = std::make_shared<BinaryTreeNode>(5);
    root2->right->left = std::make_shared<BinaryTreeNode>(6);
    root2->right->right = std::make_shared<BinaryTreeNode>(20);
   
  

   system("pause>0");
    return 0;
}
