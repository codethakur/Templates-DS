#include "../Header/Tree.h"
#include <queue>
#include <memory>
#include <iostream>
class DeleteNode{
    public:
    void DeleteNodeinBTByData(std::shared_ptr<BinaryTreeNode> root, int data) {
        if(root==nullptr){
            std::cerr<<"root not found!";
            return;
        }
        std::shared_ptr<BinaryTreeNode>targetNode = nullptr;
        std::shared_ptr<BinaryTreeNode>lastNode = nullptr;
        std::shared_ptr<BinaryTreeNode>parentOflastNode = nullptr;
        std::queue<std::shared_ptr<BinaryTreeNode>>q;
        q.push(root);

        while (!q.empty())
        {
            lastNode = q.front();
            q.pop();
            if(lastNode->data == data && !targetNode){
                targetNode = lastNode;
            }
            if(lastNode->left){
                parentOflastNode=lastNode;
                q.push(lastNode->left);
            }if(lastNode->right){
                parentOflastNode=lastNode;
                q.push(lastNode->right);
            }
        }
        if(targetNode)
        {
            targetNode->data=lastNode->data;
            if(parentOflastNode){
                if(parentOflastNode->data == lastNode->data){
                    parentOflastNode->left.reset();
                }if(parentOflastNode->right){
                    parentOflastNode->right.reset();
                }
            }
        }
    }

    // Deletes the entire subtree of a node with the given value
    void DeleteSubTreeinBTByData(std::shared_ptr<BinaryTreeNode>& root, int data) {
        if (!root) {
            std::cerr << "Root not found!" << std::endl;
            return;
        }

        // If the root itself needs to be deleted
        if (root->data == data) {
            root.reset();  // Deletes the entire tree
            return;
        }

        std::queue<std::shared_ptr<BinaryTreeNode>> q;
        q.push(root);
        std::shared_ptr<BinaryTreeNode> parent = nullptr;
        bool isLeftChild = false;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            // Check left child
            if (temp->left && temp->left->data == data) {
                parent = temp;
                isLeftChild = true;
                break;
            }

            // Check right child
            if (temp->right && temp->right->data == data) {
                parent = temp;
                isLeftChild = false;
                break;
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        // If the node was found, delete the subtree
        if (parent) {
            if (isLeftChild) {
                parent->left.reset();  // Deletes entire left subtree
            } else {
                parent->right.reset();  // Deletes entire right subtree
            }
        }
    }
};
