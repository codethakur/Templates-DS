#include<iostream>
#include<memory>
#include "./Header/Tree.h"
#include<queue>

void printTree(std::shared_ptr<BinaryTreeNode> root) {
    if (!root) return;
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node->data << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    std::cout << std::endl;
}
