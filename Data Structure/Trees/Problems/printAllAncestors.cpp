#include "../Header/Tree.h"
#include <queue>
#include <iostream>
#include <iostream>
#include <vector>
#include <memory>

int printAllAncestrors(const std::shared_ptr<BinaryTreeNode>&root, const std::shared_ptr<BinaryTreeNode>&node)
{
    if(!root){
        return 0;
    }
    
    if(root->left==node || root->right==node ||
        printAllAncestrors(root->left, node) ||
        printAllAncestrors(root->right, node) ){
        std::cout << root->data << " ";

            return 1;
    }
    return 0;
} 