#pragma once
#include <memory>
#include <iostream>

struct AVLTreeNode {
    int data = 0;
    std::shared_ptr<AVLTreeNode> left = nullptr;
    std::shared_ptr<AVLTreeNode> right = nullptr;
    std::weak_ptr<AVLTreeNode> parent; // Weak pointer to prevent cycles
    int height = 1;
};

// Function to get height safely

int height(std::shared_ptr<AVLTreeNode> &root) {
    return (root) ? root->height : 0;
}

// **Single Left Rotation (RR Fix)**
std::shared_ptr<AVLTreeNode> singleRotateLeft(std::shared_ptr<AVLTreeNode> root) {
    if (!root || !root->right) return root; // Ensure root and right subtree exist

    auto rightSubTree = root->right;
    auto leftSubOfRightSubTree = rightSubTree->left;

    rightSubTree->left = root;
    root->right = leftSubOfRightSubTree;

    // Update parent pointers
    rightSubTree->parent = root->parent;
    root->parent = rightSubTree;
    if (leftSubOfRightSubTree) leftSubOfRightSubTree->parent = root;

    // Update heights
    root->height = std::max(height(root->left), height(root->right)) + 1;
    rightSubTree->height = std::max(height(rightSubTree->left), height(rightSubTree->right)) + 1;

    return rightSubTree; // New root
}

// **Single Right Rotation (LL Fix)**
std::shared_ptr<AVLTreeNode> singleRotateRight(std::shared_ptr<AVLTreeNode> root) {
    if (!root || !root->left) return root; // Ensure root and left subtree exist

    auto leftSubTree = root->left;
    auto rightOfLeftSubTree = leftSubTree->right;

    leftSubTree->right = root;
    root->left = rightOfLeftSubTree;

    // Update parent pointers
    leftSubTree->parent = root->parent;
    root->parent = leftSubTree;
    if (rightOfLeftSubTree) rightOfLeftSubTree->parent = root;

    // Update heights
    root->height = std::max(height(root->left), height(root->right)) + 1;
    leftSubTree->height = std::max(height(leftSubTree->left), height(leftSubTree->right)) + 1;

    return leftSubTree; // New root
}

// **Left-Right (LR) Rotation**
std::shared_ptr<AVLTreeNode> doubleRotateLeft(std::shared_ptr<AVLTreeNode> root) {
    root->left = singleRotateLeft(root->left);  
    return singleRotateRight(root);
}

// **Right-Left (RL) Rotation**
std::shared_ptr<AVLTreeNode> doubleRotateRight(std::shared_ptr<AVLTreeNode> root) {
    root->right = singleRotateRight(root->right);
    return singleRotateLeft(root);
}

// **✅ Corrected Insert Function**
std::shared_ptr<AVLTreeNode> insert(std::shared_ptr<AVLTreeNode> root, int data) {
    if (!root) {
        auto newNode = std::make_shared<AVLTreeNode>();
        newNode->data = data;
        return newNode;
    }

    // **Insert in the left subtree**
    if (data < root->data) {
        root->left = insert(root->left, data);
        root->left->parent = root; 

        // **Balance check after insertion**
        if (height(root->left) - height(root->right) == 2) {
            if (data < root->left->data)
                root = singleRotateRight(root); // LL Case (Right Rotation)
            else
                root = doubleRotateLeft(root);  // LR Case (Left-Right Rotation)
        }
    }
    // **Insert in the right subtree**
    else if (data > root->data) {
        root->right = insert(root->right, data);
        root->right->parent = root; 

        // **Balance check after insertion**
        if (height(root->right) - height(root->left) == 2) {
            if (data > root->right->data)
                root = singleRotateLeft(root); //  RR Case (Left Rotation)
            else
                root = doubleRotateRight(root); //  RL Case (Right-Left Rotation)
        }
    }

    // **Update height**
    root->height = std::max(height(root->left), height(root->right)) + 1;
    return root;
}

// **Function to print tree (in-order traversal)**
void inOrder(std::shared_ptr<AVLTreeNode> root) {
    if (!root) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

int checkHeight(std::shared_ptr<AVLTreeNode>root)
{
    int leftHeight = 0, rightHeight = 0;

    if (root == nullptr) {
        return 0;
    }
    leftHeight = checkHeight(root->left);
    rightHeight = checkHeight(root->right);

    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return 1 + std::max(leftHeight, rightHeight);
}

int isBalanced(std::shared_ptr<AVLTreeNode>root)
{
    if (root == nullptr)
        return 1;
    return checkHeight(root) != -1;
}
// **Single Recursive Function to Generate AVL Tree**
std::shared_ptr<AVLTreeNode> GenerateAVL(int h, unsigned int& count) {
    if (h == 0) return nullptr; // Base case

    // Create a new node
    auto root = std::make_shared<AVLTreeNode>();

    // Recursively build left and right subtrees
    root->left = GenerateAVL(h - 1, count);
    root->data = count++;  // Assign unique value
    root->right = GenerateAVL(h - 2, count);

    // Update height
    root->height = std::max(height(root->left), height(root->right)) + 1;

    return root;
}

// Wrapper function to start with count = 0
std::shared_ptr<AVLTreeNode> GenerateAVL(int h) {
    unsigned int count = 0;
    return GenerateAVL(h, count);
}
