    #pragma once

    #include <iostream>
    #include <stdexcept>
    #include <memory>

    struct BinarySearchTreeNode {
        int data;
        std::unique_ptr<BinarySearchTreeNode> left;
        std::unique_ptr<BinarySearchTreeNode> right;
    };

    class BinarySearchTree {
    public:
        std::unique_ptr<BinarySearchTreeNode> insert(std::unique_ptr<BinarySearchTreeNode> root, int data) {
            if (!root) {
                root = std::make_unique<BinarySearchTreeNode>();
                root->data = data;
            }
            else if (data < root->data) {
                root->left = insert(std::move(root->left), data);
            }
            else if (data > root->data) {
                root->right = insert(std::move(root->right), data);
            }
            return root;
        }

        void inorderTraversal(const std::unique_ptr<BinarySearchTreeNode>& root) const {
            if (root) {
                inorderTraversal(root->left);
                std::cout << root->data << " ";
                inorderTraversal(root->right);
            }

        }
        void preOrderTraversal(const std::unique_ptr<BinarySearchTreeNode>& root) const {
            if (root) {
                std::cout << root->data << " ";
                preOrderTraversal(root->left);
                preOrderTraversal(root->right);
            }
        }



        BinarySearchTreeNode* findNodeWithRec(const std::unique_ptr<BinarySearchTreeNode>& root, int data) const {
            if (!root) throw std::runtime_error("root is NULL.");
            if (data < root->data) return findNodeWithRec(root->left, data);
            else if (data > root->data) return findNodeWithRec(root->right, data);
            return root.get();
        }

        // Function to find a node in BST
        BinarySearchTreeNode* findNode(BinarySearchTreeNode* root, int value) {
            if (!root) return nullptr;
            if (root->data == value) return root;
            return (value < root->data) ? findNode(root->left.get(), value) : findNode(root->right.get(), value);
        }

        BinarySearchTreeNode* findMinWithRecur(const std::unique_ptr<BinarySearchTreeNode>& root) const {
            if (!root) throw std::runtime_error("root is NULL.");
            return root->left ? findMinWithRecur(root->left) : root.get();
        }

        BinarySearchTreeNode* findMin(BinarySearchTreeNode* root) const {
            if (!root) throw std::runtime_error("root is NULL.");
            while (root->left) root = root->left.get();
            return root;
        }

        BinarySearchTreeNode* findMaxWithRec(const std::unique_ptr<BinarySearchTreeNode>& root) const {
            if (!root) throw std::runtime_error("root is NULL.");
            return root->right ? findMaxWithRec(root->right) : root.get();
        }

        BinarySearchTreeNode* findMax(BinarySearchTreeNode* root) const {
            if (!root) throw std::runtime_error("root is NULL.");
            while (root->right) root = root->right.get();
            return root;
        }


        void DeleteNode(std::unique_ptr<BinarySearchTreeNode>& root, int data)
        {
            if (!root) throw std::runtime_error("root is NULL.");

            if (data < root->data) {
                DeleteNode(root->left, data);
            }
            else if (data > root->data) {
                DeleteNode(root->right, data);
            }
            else
            {
                if (root->left && root->right) {
                    auto temp = findMax(root->left.get());
                    root->data = temp->data;
                    DeleteNode(root->left, temp->data);
                }
                else {
                    std::unique_ptr<BinarySearchTreeNode> temp = std::move(root->left ? root->left : root->right);
                    root = std::move(temp);
                }
            }
        }

    

        // Function to find Lowest Common Ancestor (LCA)
        BinarySearchTreeNode* findLCA(BinarySearchTreeNode* root, BinarySearchTreeNode* rootA, BinarySearchTreeNode* rootB) {
            if (!root || !rootA || !rootB) return nullptr; // Avoid null pointer errors

            while (root) {
                if (rootA->data < root->data && rootB->data < root->data)
                    root = root->left.get();
                else if (rootA->data > root->data && rootB->data > root->data)
                    root = root->right.get();
                else
                    return root; // Found LCA
            }
            return nullptr;
        }
        #if 0
        int isBST(const BinarySearchTreeNode* root)
        {
            if (root == NULL)
                return 1;

            if (root->left && root->left->data > root->data)
                return 0;

            if (root->right && root->right->data < root->data)
                return 0;

            if (!isBST(root->left.get()) || !isBST(root->right.get()))
                return 0;

            return 1;
        }
        #endif

        int isBST(const BinarySearchTreeNode* root)
        {
            if (root == NULL) {
                return 1;
            }
            if (root->left && findMax(root->left.get())->data > root->data)  
                return 0;
            if (root->right && findMin(root->right.get())->data < root->data)
                return 0;
            if (!isBST(root->left.get()) || !isBST(root->right.get()))  
                return 0;
            return 1;

        }
        int isBSTUtil(const BinarySearchTreeNode* root, int min = INT_MIN, int max = INT_MAX) {
        if (root == NULL) {
            return 1;
        }
        return (root->data > min && root->data < max &&
                isBSTUtil(root->left ? root->left.get() : nullptr, min, root->data) &&
                isBSTUtil(root->right ? root->right.get() : nullptr, root->data, max));
    }

    

    };
