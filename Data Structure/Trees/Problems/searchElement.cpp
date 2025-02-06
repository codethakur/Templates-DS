#include "Tree.h"  
#include <queue>
#include <iostream>

int findElementUsingRecursion(const std::shared_ptr<BinaryTreeNode>root, int data)
{
    int temp = 0;
    if(root ==nullptr) {
        return 0;
    }
    else{
        if(data == root->data){
            return 1;
        }else{
            temp = findElementUsingRecursion(root->left, data);
            if(temp!=0)
                return temp;
            else return(findElementUsingRecursion(root->right, data));
        }
    } 
    return 0;
}

int findElement(const std::shared_ptr<BinaryTreeNode>root, int data)
{
    std::shared_ptr<BinaryTreeNode>temp;
    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(root);
    while (!q.empty())
    {
       temp = q.front();
       q.pop();
       if(temp->data == data){
        return 1;
       }
       if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return 0 ;
}