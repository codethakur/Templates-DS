#include"../Header/Tree.h"
#include<queue>
#include<stack>
#include<memory>
#include<iostream>
void levelOrderTraverseInReverse(const std::shared_ptr<BinaryTreeNode>root)
{
    if(root==NULL){
        return;
    }
    std::queue<std::shared_ptr<BinaryTreeNode>>nodeQue;
    std::stack<std::shared_ptr<BinaryTreeNode>>nodeStack;

    nodeQue.push(root);
    while (!nodeQue.empty())
    {
        auto temp = nodeQue.front();
        nodeQue.pop();

        if(temp->left)
            nodeQue.push(temp->left);
        if(temp->right)
            nodeQue.push(temp->right);
        nodeStack.push(temp);    
    }
    while (!nodeStack.empty())
    {
        auto node = nodeStack.top();
        nodeStack.pop();
        std::cout<<"data: "<<node->data<<" ";
    }
    
}