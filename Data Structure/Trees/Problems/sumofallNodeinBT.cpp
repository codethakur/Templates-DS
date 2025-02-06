#include "../Header/Tree.h"
#include <queue>
#include <memory>

class sumofNodeData
{
public:
    int add(const std::shared_ptr<BinaryTreeNode> root)
    {
        if (!root)
            return 0;
        else
            return (root->data + add(root->left) + add(root->right));
    }

    int sumofBTusingLevelOrder(const std::shared_ptr<BinaryTreeNode> root)
    {
        if (!root)
            return 0;
        std::queue<std::shared_ptr<BinaryTreeNode>> q;
        q.push(root);
        unsigned int sum = 0;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            sum += temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return sum;
    }
};