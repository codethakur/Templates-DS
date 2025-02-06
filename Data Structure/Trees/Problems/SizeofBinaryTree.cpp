#include"../Header/Tree.h"
#include<queue>
#include<memory>
class sizeofBinaryTree
{
    public:
        int SizeofBinaryTreeUsingRecursion(const std::shared_ptr<BinaryTreeNode>root)
        {
            if(root==nullptr)
                return 0;
            else
                return SizeofBinaryTreeUsingRecursion(root->left) + 1 + SizeofBinaryTreeUsingRecursion(root->right);  
        }

        int SizeofBinaryTreeNonRecursion(const std::shared_ptr<BinaryTreeNode>root)
        {
            
            if(root==nullptr){
                return 0;
            }
            std::queue<std::shared_ptr<BinaryTreeNode>>q;
            q.push(root);
            int count = 0;
            while (!q.empty())
            {
                auto temp = q.front();
                q.pop();
                count++;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);    
            }
            return count;
        }
};