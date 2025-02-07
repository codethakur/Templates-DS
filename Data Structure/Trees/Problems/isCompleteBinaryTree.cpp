#include "../Header/Tree.h"
#include <memory>
#include <queue>

bool isCompleteBinaryTree(std::shared_ptr<BinaryTreeNode> root) {
    if (!root) return true;

    std::queue<std::shared_ptr<BinaryTreeNode>> q;
    q.push(root);
    
    bool foundNull = false;  // Track if a NULL node has been encountered

    while (!q.empty()) {
        std::shared_ptr<BinaryTreeNode> p = q.front();
        q.pop();

        if (!p) {
            foundNull = true; // Once we find a NULL, all next nodes must also be NULL
        } else {
            if (foundNull) return false; // A valid node after a NULL → Not Complete
            q.push(p->left);
            q.push(p->right);
        }
    }
    return true;
}
