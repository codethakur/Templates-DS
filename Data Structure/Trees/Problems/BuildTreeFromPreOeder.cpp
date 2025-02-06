#include "../Header/Tree.h"
#include <memory>

class charTreeBuild{
    public:
    std::shared_ptr<BinaryTreeNode> buildTreeFromPreOrder(const char *A, int *ptr) {
        // Check for null pointer or out-of-bounds index
        if (A == nullptr || A[*ptr] == '\0') {
            return nullptr;
        }

        // Create new node and set its data
        //   std::shared_ptr<BinaryTreeNode> newNode = std::make_shared<BinaryTreeNode>(A[*ptr]);
        std::shared_ptr<BinaryTreeNode> newNode = std::make_shared<BinaryTreeNode>(A[*ptr] == 'I' ? 'I' : 'L');

        // Move the pointer to the next character in the array
        (*ptr)++;

        // If the node is a leaf, return the node directly
        if (A[*ptr - 1] == 'L') {
            return newNode;
        }

        // Otherwise, recursively build the left and right subtrees
        newNode->left = buildTreeFromPreOrder(A, ptr);
        newNode->right = buildTreeFromPreOrder(A, ptr);

        return newNode;
    }

    void printTreePreOrder(std::shared_ptr<BinaryTreeNode> root) {
        if (root == nullptr) {
            return;
        }
        char Data = (char)root->data;
        std::cout << Data << " ";
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
};

