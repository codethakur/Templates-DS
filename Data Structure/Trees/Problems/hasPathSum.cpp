#include"../Header/Tree.h"
#include<queue>
#include<memory>


int hasPathSum(const std::shared_ptr<BinaryTreeNode> root, int sum)
{
    if (!root) {
        return 0;
    }

    int remainingSum = sum - root->data;

    // If it's a leaf node, check if remaining sum is zero
    if (!root->left && !root->right) {
        return (remainingSum == 0);
    }

    // Recursively check left and right subtrees
    return (root->left && hasPathSum(root->left, remainingSum)) ||
           (root->right && hasPathSum(root->right, remainingSum));
}


