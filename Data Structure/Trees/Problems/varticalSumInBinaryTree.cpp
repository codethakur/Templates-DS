#include "../Header/Tree.h"
#include <stack>
#include <iostream>
#include <memory>
#include<map>
#include<vector>


void verticalSumHelper(const std::shared_ptr<BinaryTreeNode>& root, int column, std::map<int, int>& columnSum) {
    if (!root) {
        return;
    }

    // Add the current node's value to the corresponding column in the map
    columnSum[column] += root->data;

    // Recur for left and right children, adjusting the column index
    verticalSumHelper(root->left, column - 1, columnSum);
    verticalSumHelper(root->right, column + 1, columnSum);
}

void printVerticalSum(const std::shared_ptr<BinaryTreeNode>& root) {
    std::map<int, int> columnSum;

    // Call the helper function to fill the columnSum map
    verticalSumHelper(root, 0, columnSum);

    // Print the vertical sum for each column in order
    for (const auto& entry : columnSum) {
       std:: cout << "Column " << entry.first << ": " << entry.second << std::endl;
    }
}