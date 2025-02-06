#include"../Header/Tree.h" 

#include <queue>
#include <iostream>


bool isIdentical(const std::shared_ptr<BinaryTreeNode>root1, const std::shared_ptr<BinaryTreeNode>root2)
{
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr && root2 != nullptr || root1 != nullptr && root2 == nullptr ) return false;

    return (    root1->data == root2->data && 
                isIdentical(root1->left, root2->left) && 
                isIdentical(root1->right, root2->right)
            );


}