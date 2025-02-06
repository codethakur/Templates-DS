#pragma once

#include <memory>

struct BinaryTreeNode {
    int data;
    std::shared_ptr<BinaryTreeNode> left;
    std::shared_ptr<BinaryTreeNode> right;

    BinaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void printTree(std::shared_ptr<BinaryTreeNode> root);
void deleteBinaryTree(std::shared_ptr<BinaryTreeNode> root)
{
    // No explicit delete is needed. When root goes out of scope, shared_ptr automatically manages memory.
    if(root == nullptr)
        return;

    // Recursively delete left and right subtrees
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    // After recursive calls, the memory will automatically be cleaned up when the shared_ptr goes out of scope
}
