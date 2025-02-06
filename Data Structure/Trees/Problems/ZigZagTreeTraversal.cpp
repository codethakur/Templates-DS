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

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        stack<TreeNode*> currentLevelStack;
        stack<TreeNode*> nextLevelStack;
        
        currentLevelStack.push(root);
        bool leftToRight = true;

        while (!currentLevelStack.empty()) {
            vector<int> levelValues;
            while (!currentLevelStack.empty()) {
                TreeNode* node = currentLevelStack.top();
                currentLevelStack.pop();
                
                if (node) {
                    levelValues.push_back(node->val);
                    
                    // Push children to the next level stack in the correct order
                    if (leftToRight) {
                        if (node->left) nextLevelStack.push(node->left);
                        if (node->right) nextLevelStack.push(node->right);
                    } else {
                        if (node->right) nextLevelStack.push(node->right);
                        if (node->left) nextLevelStack.push(node->left);
                    }
                }
            }
            
            // Add the current level's values to the result
            result.push_back(levelValues);
            
            // Toggle the direction for the next level and swap stacks
            leftToRight = !leftToRight;
            swap(currentLevelStack, nextLevelStack);
        }

        return result;
    }
#endif

