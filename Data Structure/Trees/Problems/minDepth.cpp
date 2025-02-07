#include"../Header/Tree.h"
#include <memory>
#include<queue>

struct QueueElement
{
    std::shared_ptr<BinaryTreeNode>btNode;
    int depth;
};


class FindDepth{
    public:
      int minDepth(const std::shared_ptr<BinaryTreeNode> root, int &minNode) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) { // If it's a leaf node
            minNode = root->data;  // Store the leaf node's value
            return 1;
        }
        
        int leftDepth = (root->left) ? minDepth(root->left, minNode) : INT_MAX;
        int rightDepth = (root->right) ? minDepth(root->right, minNode) : INT_MAX;

        // Choose the minimum depth path and update the node value
        if (leftDepth < rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }

    int minDepthUsingBTqueue(std::shared_ptr<BinaryTreeNode>root)
    {
        if(root==NULL){
            return 0;
        }
        std::queue<QueueElement>q;
        //enqueue root and depth as 1
        QueueElement queueElement = {root, 1};
        q.push(queueElement);
        while (q.empty()==false)
        {
            queueElement = q.front();
            q.pop();
            std::shared_ptr<BinaryTreeNode>temp = queueElement.btNode;
            int depth = queueElement.depth;
            if(temp->left==NULL && temp->right==NULL){
                return depth;
            }
            if(temp->left){
                queueElement.btNode = temp->left;
                queueElement.depth = depth+1;
                q.push(queueElement);
            }
            if(temp->right){
                 queueElement.btNode = temp->right;
                queueElement.depth = depth+1;
                q.push(queueElement);
            }
        }
        return 0;
    }

    int maxDepthUsingBTqueue(std::shared_ptr<BinaryTreeNode> root) {
        if (!root) {
            return 0;
        }
        std::queue<QueueElement> q;
        q.push({root, 1}); // Start with root at depth 1

        int maxDepth = 0; // Store the maximum depth encountered

        while (!q.empty()) {
            QueueElement queueElement = q.front();
            q.pop();

            std::shared_ptr<BinaryTreeNode> temp = queueElement.btNode;
            int depth = queueElement.depth;

            // Update max depth at each level
            maxDepth = std::max(maxDepth, depth);

            if (temp->left) {
                q.push({temp->left, depth + 1});
            }
            if (temp->right) {
                q.push({temp->right, depth + 1});
            }
        }
        return maxDepth;
    }


};