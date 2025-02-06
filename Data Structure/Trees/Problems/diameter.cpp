#include "../Header/Tree.h"
#include <queue>
#include <iostream>
#include "HeightofBinaryTree.cpp"

int diameter(const std::shared_ptr<BinaryTreeNode> root)
{
    if (!root) return 0;  // Base case: diameter of an empty tree is 0.

    HeightOfBinaryTree Height;
    int lHeight = Height.HeightOfBinaryTreeUsingRecursion(root->left);
    int rHeight = Height.HeightOfBinaryTreeUsingRecursion(root->right); 

    int LDiameter = diameter(root->left);
    int RDiameter = diameter(root->right);

    return std::max(lHeight + rHeight + 1, std::max(LDiameter, RDiameter));
}
