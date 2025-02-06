#include "../Header/Tree.h"
#include <queue>
#include <memory>
#include <iostream>

class NumberofNodes
{
    public:
    int NumberofFullNodesInBT(const std::shared_ptr<BinaryTreeNode>root)
    {
        if(!root){
            std::cerr<<"root not found!";
            return 0;
        }
        int count = 0;
        std::queue<std::shared_ptr<BinaryTreeNode>>q;
        q.push(root);

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(temp->left && temp->right){
                count++;
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return count;
    }

    int NumberoHalfNodesInBT(const std::shared_ptr<BinaryTreeNode>root)
    {
        if(!root){
            std::cerr<<"root not found!";
            return 0;
        }
        std::queue<std::shared_ptr<BinaryTreeNode>>q;
        q.push(root);
        int count=0;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            if(!temp->left && temp->right || temp->left && !temp->right){
                count++;
            }
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return count;
        
    }
};