#include"../Header/Tree.h"
#include<queue>
#include<memory>

class HeightOfBinaryTree{
public:
    int HeightOfBinaryTreeUsingRecursion(const std::shared_ptr<BinaryTreeNode>root)
        {
            if(root==NULL){
                return 0;
            }
            int leftHeight = HeightOfBinaryTreeUsingRecursion(root->left);
            int rightHeight = HeightOfBinaryTreeUsingRecursion(root->right);

            return (leftHeight>rightHeight)? leftHeight+1 :rightHeight+1;
        }

        int HeightOfBinaryTreeNonRecursion(const std::shared_ptr<BinaryTreeNode> root)
        {
            if (root == nullptr) {
                return 0;
            }

            std::queue<std::shared_ptr<BinaryTreeNode>> q;
            q.push(root);
            int height = 0;

            // Traverse level by level
            while (!q.empty()) {
                int nodeCount = q.size();  // Number of nodes at the current level
                height++;  // Increment height as we process each level

                // Process each node in the current level
                while (nodeCount > 0) {
                    auto node = q.front();
                    q.pop();

                    // Add left and right children to the queue if they exist
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }

                    nodeCount--;
                }
            }

            return height;
        }
};