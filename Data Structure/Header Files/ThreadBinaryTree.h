#pragma once
#define THREADBINARYTREE_H
#include <iostream>
struct ThreadedNode
{
    int data;
    ThreadedNode *left;
    ThreadedNode *right;
    bool isLeftThread;  // true if left points to in-order predecessor
    bool isRightThread; // true if right points to in-order successor

    ThreadedNode(int val) : data(val), left(nullptr), right(nullptr),
                            isLeftThread(false), isRightThread(false) {}
};

class threadedTree
{
public:
    ThreadedNode *buildThreadTree(ThreadedNode *root, int data)
    {
        ThreadedNode *newNode = new ThreadedNode(data);
        if (!root)
        {
            return newNode; // First node becomes root
        }

        ThreadedNode *current = root;

        while (current)
        {
            if (data < current->data)
            {
                if (current->left == nullptr || current->isLeftThread)
                {
                    newNode->left = current->left;
                    newNode->right = current; // Threaded link to in-order successor
                    newNode->isRightThread = true;

                    current->left = newNode;
                    current->isLeftThread = false;
                    return root;
                }
                current = current->left;
            }
            else
            {
                if (current->right == nullptr || current->isRightThread)
                {
                    newNode->right = current->right;
                    newNode->left = current; // Threaded link to in-order predecessor
                    newNode->isLeftThread = true;

                    current->right = newNode;
                    current->isRightThread = false;
                    return root;
                }
                current = current->right;
            }
        }

        return root;
    }
    // leftmost node of the right subtree.
    ThreadedNode *findInOrderSuccessor(ThreadedNode *node)
    {
        if (!node)
            return nullptr;

        // Case 1: If there's a right thread, return the successor directly
        if (node->isRightThread)
        {
            return node->right;
        }

        // Case 2: Go to the leftmost node in the right subtree
        ThreadedNode *successor = node->right;
        while (successor && successor->isLeftThread)
        {
            successor = successor->left;
        }

        return successor;
    }

    void InorderTraversal(ThreadedNode *root)
    {
        if (!root)
            return;

        // Move to the leftmost node (starting point for inorder traversal)
        ThreadedNode *current = root;

        // Traverse using threads
        while (1)
        {
            current = findInOrderSuccessor(current);
            std::cout << current->data << " ";
        }
    }


    ThreadedNode* findPreorderSuccessor(ThreadedNode* root) {
        if (!root) return nullptr;
    
        // Case 1: If there is a left child, it is the next preorder node
        ThreadedNode* current;
        if (root->left) {
            return root->left;
        }else{
            current = root;
            while (current->right!=nullptr)
            {
                current=current->right;
            }
            return current->right;
            
        }
    }
    void PreorderTraversal(ThreadedNode *root) {
        if (!root) return;
    
        ThreadedNode *current = root;
    
        while (current) {
            std::cout << current->data << " ";
    
            current = findPreorderSuccessor(current);
        }
    }
        


};
