#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;
    std::unique_ptr<BinarySearchTreeNode> root = nullptr;

    // Insert nodes into BST
    root = bst.insert(std::move(root), 50);
    root = bst.insert(std::move(root), 30);
    root = bst.insert(std::move(root), 70);
    root = bst.insert(std::move(root), 20);
    root = bst.insert(std::move(root), 40);
    root = bst.insert(std::move(root), 60);
    root = bst.insert(std::move(root), 80);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    bst.preOrderTraversal(root);
    std::cout << std::endl;

    // Find nodes
    BinarySearchTreeNode* nodeA = bst.findNode(root.get(), 20);
    BinarySearchTreeNode* nodeB = bst.findNode(root.get(), 40);

    if (nodeA && nodeB) {
        BinarySearchTreeNode* lca = bst.findLCA(root.get(), nodeA, nodeB);
        if (lca)
            std::cout << "LCA of " << nodeA->data << " and " << nodeB->data << " is: " << lca->data << std::endl;
        else
            std::cout << "No LCA found." << std::endl;
    }
    else {
        std::cout << "Error: One or both nodes not found in the tree!" << std::endl;
    }

    // Find Min and Max
    std::cout << "Minimum Value in BST: " << bst.findMin(root.get())->data << std::endl;
    std::cout << "Maximum Value in BST: " << bst.findMax(root.get())->data << std::endl;

    // Delete a node
    std::cout << "Deleting node 40..." << std::endl;
    bst.DeleteNode(root, 40);

    std::cout << "Inorder Traversal after deletion: ";
    bst.inorderTraversal(root);
    std::cout << std::endl;
    auto result = bst.isBST(root.get());  //  Using .get() to pass raw pointer
    std::cout << "Is Binary Search Tree: " <<  result << std::endl;
    auto resultUtill = bst.isBSTUtil(root.get(), INT_MIN, INT_MAX);  //  Using .get() to pass raw pointer
    std::cout << "Is Binary Search Tree: " << result << std::endl;


    return 0;
}
