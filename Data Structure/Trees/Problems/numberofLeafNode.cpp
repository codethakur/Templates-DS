#include"../Header/Tree.h"
#include<queue>
#include<memory>
#include<iostream>

class NomberofNodes{
public:
    int numberOfLeavesInBTusingLevelOrder(const std::shared_ptr<BinaryTreeNode>root)
    {
        if(!root){
            std::cerr<<"Root of  tree not found!";
            return 0;
        }
        std::queue<std::shared_ptr<BinaryTreeNode>>q;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(!temp->left && !temp->right){
                count++;
            }else{
                if(temp->left){
                    q.push(temp->left);
                }if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return count;
    }

    int numberofFullInBTusingLevelOrder(const std::shared_ptr<BinaryTreeNode>root)
    {
        if(root==nullptr){
            std::cerr<<"root of Binary Tree not found\n";
            return 0;
        }
        std::queue<std::shared_ptr<BinaryTreeNode>>q;
        q.push(root);
        int count = 0;
        while (!q.empty()) {
        auto temp = q.front();
        q.pop();

        if (temp->left && temp->right) {
            count++;
            //std::cout << "Full Node Found: " << temp->data << std::endl; // Debug print
        }
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

        return count;
    }
};