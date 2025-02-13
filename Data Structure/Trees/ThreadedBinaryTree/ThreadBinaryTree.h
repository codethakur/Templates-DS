#pragma once
#define THREADBINARYTREE_H
#include <iostream>
#include <vector>

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
    ThreadedNode *insert(ThreadedNode *root, int data)
    {
        if (!root)
            return new ThreadedNode(data);

        ThreadedNode *parent = nullptr;
        ThreadedNode *curr = root;
        bool clone = false;

        while (curr)
        {
            if (data == curr->data)
            {
                clone = true; 
                break;
            }
            parent = curr;
            if (data < curr->data)
            {
                if (!curr->isLeftThread)
                    curr = curr->left;
                else
                    break;
            }
            else
            {
                if (!curr->isRightThread)
                    curr = curr->right;
                else
                    break;
            }
        }

        if (clone)
        {
            std::cerr << "\nDuplicated data" << std::endl;
            return root; // Fix: Return without modifying the tree
        }

        ThreadedNode *newNode = new ThreadedNode(data);
        newNode->isLeftThread = true;
        newNode->isRightThread = true;

        if (parent == NULL)
        {
            root = newNode;
            newNode->left = nullptr;
            newNode->right = nullptr;
        }
        else if (data < parent->data)
        {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->isLeftThread = false;
            parent->left = newNode;
        }
        else
        {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->isRightThread = false;
            parent->right = newNode;
        }

        return root;
    }

    ThreadedNode *buildThreadTree(const std::vector<int> &data)
    {
        ThreadedNode *root = nullptr;
        for (int i = 0; i < data.size(); i++)
        {
            root = insert(root, data[i]);
        }
        return root;
    }

    struct ThreadedNode *inOrderPred(struct ThreadedNode *node)
    {
        if (node->isLeftThread == true)
        {
            return node;
        }
        else
        {
            node = node->left;
            while (node->isLeftThread == false)
            {
                node = node->left;
            }
            return node;
        }
    }

    // Inorder traversal of a threaded binary tree
    void preorder(struct ThreadedNode *root)
    {
        if (root == nullptr)
        {
            std::cerr << "root not found\n";
            return;
        }
        struct ThreadedNode *current = root;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            if (current->isLeftThread == false)
            {
                current = current->left;
            }
            else if (current->isRightThread == false)
                current = current->right;
            else
            {
                while (current != NULL && current->isRightThread == true)
                    current = current->right;
                if (current != NULL)
                    current = current->right;
            }
        }
    }

    struct ThreadedNode *inOrderSucc(struct ThreadedNode *node)
    {
        if (node->isRightThread == true)
        {
            return node->right;
        }
        else
        {
            node = node->right;
            while (node->isLeftThread == false)
            {
                node = node->left;
            }
            return node;
        }
    }

    void inorder(ThreadedNode *root)
    {
        if (!root)
        {
            std::cerr << "Root not found\n";
            return;
        }
        ThreadedNode *current = root;
        while (current && current->isLeftThread == false)
            current = current->left;

        while (current)
        {
            std::cout << current->data << " ";
            current = inOrderSucc(current);
        }
        std::cout << std::endl;
    }
    struct ThreadedNode *case_a(struct ThreadedNode *root, struct ThreadedNode *par, struct ThreadedNode *DeleteNode)
    {
        if (par == NULL)
            root = NULL;
        else if (DeleteNode == par->left)
        {
            par->isLeftThread = true;
            par->left = DeleteNode->left;
        }
        else
        {
            par->isRightThread = true;
            par->right = DeleteNode->right;
        }
        free(DeleteNode);
        return root;
    }
    struct ThreadedNode *case_b(struct ThreadedNode *root, struct ThreadedNode *par, struct ThreadedNode *DeleteNode)
    {
        struct ThreadedNode *child, *s, *p;
        if (DeleteNode->isLeftThread == false)
            child = DeleteNode->left;
        else
            child = DeleteNode->right;
        if (par == NULL)
            root = child;
        else if (DeleteNode == par->left)
            par->left = child;
        else
            par->right = child;
        s = inOrderSucc(DeleteNode);
        p = inOrderPred(DeleteNode);
        if (DeleteNode->isLeftThread == false)
            p->right = s;
        else
        {
            if (DeleteNode->isRightThread == false)
                s->left = p;
        }
        free(DeleteNode);
        return root;
    }
    struct ThreadedNode *case_c(struct ThreadedNode *root, struct ThreadedNode *par, struct ThreadedNode *DeleteNode)
    {
        struct ThreadedNode *succ, *parsucc;
        parsucc = DeleteNode;
        succ = DeleteNode->right;
        while (succ->left != NULL)
        {
            parsucc = succ;
            succ = succ->left;
        }
        DeleteNode->data = succ->data;
        if (succ->isLeftThread == true && succ->isRightThread == true)
            {
                std::cout<<"case a from case c\n";
                root = case_a(root, parsucc, succ);
            }
        else
            root = case_b(root, parsucc, succ);
        return root;
    }

    struct ThreadedNode *del(struct ThreadedNode *root, int data)
    {
        struct ThreadedNode *par, *ptr;
        int found = 0;
        ptr = root;
        par = NULL;
        while (ptr != NULL)
        {
            if (data == ptr->data)
            {
                found = 1;
                break;
            }
            par = ptr;
            if (data < ptr->data)
            {
                if (ptr->isLeftThread == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else
            {
                if (ptr->isRightThread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        if (found == 0)
            printf("\ndkey not present in tree");
        else if (ptr->isLeftThread == false && ptr->isRightThread == false)
            root = case_c(root, par, ptr);
        else if (ptr->isLeftThread == false)
             root = case_b(root, par, ptr);
        else if (ptr->isRightThread == false)
             root = case_b(root, par, ptr);
        else
            root = case_a(root, par, ptr);
        return root;
    }
};
