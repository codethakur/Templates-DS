#include"../Header/Tree.h"
#include<queue>
#include<memory>

std::shared_ptr<BinaryTreeNode>deepstNodeinBinaryTree(const std::shared_ptr<BinaryTreeNode>root)
{
    if(root==nullptr){
        return nullptr;
    }
    std::queue<std::shared_ptr<BinaryTreeNode>>q;
    std::shared_ptr<BinaryTreeNode>temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }if(temp->right){
            q.push(temp->right);
        }
    }
    return temp;
}