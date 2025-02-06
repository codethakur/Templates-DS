#include"../Header/Tree.h" 

#include <queue>
#include <iostream>

int findMaxnonRecursion(std::shared_ptr<BinaryTreeNode> root) {
    if (!root) return INT_MIN; // Handle empty tree case

    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(root);
    
    int maxVal = root->data;

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        maxVal = std::max(maxVal, node->data);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return maxVal;
}
