#include "../Header/Tree.h"
#include <queue>
#include <memory>

class MirrorOfBinaryTree
{
public:
    std::shared_ptr<BinaryTreeNode> mirrorofBinaryTree(std::shared_ptr<BinaryTreeNode>& root)
    {
        if (!root) {
            return nullptr;
        }

        // Recursively mirror left and right subtrees
        mirrorofBinaryTree(root->left);
        mirrorofBinaryTree(root->right); // Fixed the duplicate call

        // Swap left and right children
        std::shared_ptr<BinaryTreeNode> temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }

   int isMirrorofBinaryTree(std::shared_ptr<BinaryTreeNode>& root1, std::shared_ptr<BinaryTreeNode>& root2)
    {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;

        // Compare the values of root1 and root2 as well!
        return (root1->data == root2->data) &&
            isMirrorofBinaryTree(root1->left, root2->right) &&
            isMirrorofBinaryTree(root1->right, root2->left);
    }
//Least Common Ancestror
    std::shared_ptr<BinaryTreeNode>LCA(const std::shared_ptr<BinaryTreeNode>&root, 
                                       const std::shared_ptr<BinaryTreeNode>&node1, 
                                       const std::shared_ptr<BinaryTreeNode>&node2)
    {
        if(root==nullptr) return nullptr;

        if(root == node1 || root ==node2){
            return root;
        }
        auto left = LCA(root->left, node1, node2);
        auto right = LCA(root->right, node1, node2);

        if(left && right)
            return root;
        else return(left? left:right); 
    }

};