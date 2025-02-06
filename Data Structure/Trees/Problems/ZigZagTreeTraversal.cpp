#include "../Header/Tree.h"
#include <stack>
#include <iostream>
#include <memory>

void zigZagTraversal(std::shared_ptr<BinaryTreeNode> root)
{
    if (!root) return;

    std::stack<std::shared_ptr<BinaryTreeNode>> currentLevelStack;
    std::stack<std::shared_ptr<BinaryTreeNode>> nextLevelStack;

    currentLevelStack.push(root);
    bool leftToRight = true;

    while (!currentLevelStack.empty()) {
        auto temp = currentLevelStack.top();
        currentLevelStack.pop();
        
        if (temp) {
            std::cout << temp->data << " ";
            
            // Push children in opposite order for zigzag traversal
            if (leftToRight) {
                if (temp->left) nextLevelStack.push(temp->left);
                if (temp->right) nextLevelStack.push(temp->right);
            } else {
                if (temp->right) nextLevelStack.push(temp->right);
                if (temp->left) nextLevelStack.push(temp->left);
            }
        }

        // If current stack is empty, move to the next level
        if (currentLevelStack.empty()) {
            leftToRight = !leftToRight;
            std::swap(currentLevelStack, nextLevelStack);
        }
    }
}
