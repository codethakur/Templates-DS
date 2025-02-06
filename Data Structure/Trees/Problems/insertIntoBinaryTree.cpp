#include "../Header/Tree.h"  
#include <queue>
#include <iostream>

std::shared_ptr<BinaryTreeNode> insertIntoBinaryTree(std::shared_ptr<BinaryTreeNode> root, int data) {
    auto newNode = std::make_shared<BinaryTreeNode>(data);

    if (!root) {
        return newNode;  // Return new node if tree is empty
    }

    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(root);

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}
