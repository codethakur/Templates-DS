#include "./Header/Tree.h"
#include "PrintTree.cpp"
#include "./Problems/isCompleteBinaryTree.cpp"
#include <iostream>

int main()
{
    auto root1 = std::make_shared<BinaryTreeNode>(1);
    root1->left = std::make_shared<BinaryTreeNode>(2);
    root1->right = std::make_shared<BinaryTreeNode>(3);
    root1->left->left = std::make_shared<BinaryTreeNode>(4);
    root1->left->right = std::make_shared<BinaryTreeNode>(5);
    root1->right->left = std::make_shared<BinaryTreeNode>(6);
     root1->right->right = std::make_shared<BinaryTreeNode>(7);

    auto root2 = std::make_shared<BinaryTreeNode>(1);
    root2->left = std::make_shared<BinaryTreeNode>(2);
    root2->right = std::make_shared<BinaryTreeNode>(3);
    root2->left->left = std::make_shared<BinaryTreeNode>(4);
    root2->left->right = std::make_shared<BinaryTreeNode>(5);
    // Missing `root2->right->left`, but has `root2->right->right`
   // root2->right->right = std::make_shared<BinaryTreeNode>(7);

#if 0
    const char *preOrder = "ILILL";
    int ptr = 0;

    // Build tree from preorder traversal string
    charTreeBuild Tree;
    std::shared_ptr<BinaryTreeNode> Root = Tree.buildTreeFromPreOrder(preOrder, &ptr);

    Tree.printTreePreOrder(Root);

#endif

#if 0
        auto root = std::make_shared<BinaryTreeSibling>(1);
        root->setLeft(std::make_shared<BinaryTreeSibling>(2));
        root->setRight(std::make_shared<BinaryTreeSibling>(3));
        root->getLeft()->setLeft(std::make_shared<BinaryTreeSibling>(4));
        root->getLeft()->setRight(std::make_shared<BinaryTreeSibling>(5));
        root->getRight()->setLeft(std::make_shared<BinaryTreeSibling>(6));
        root->getRight()->setRight(std::make_shared<BinaryTreeSibling>(7));
        FillNextSibling sibling;
        sibling.withoutRecursion(root);

        sibling.printNextSiblings(root);

    FindDepth findDepth;
    int minNode = -1;
    int depth = findDepth.minDepth(root1, minNode);

    std::cout << "Minimum Depth: " << depth << std::endl;
    std::cout << "Node at Minimum Depth: " << minNode << std::endl;
    std::cout<<"-------------------------------\n";
    std::cout<<"Minimum depth of Binary Tree: "<<findDepth.minDepthUsingBTqueue(root1);

    std::cout<<"\nMaximum depth of a Binary tree: "<<findDepth.maxDepthUsingBTqueue(root1);
#endif
   std::cout << std::boolalpha << isCompleteBinaryTree(root1)<<std::endl; // true
   std::cout << std::boolalpha << isCompleteBinaryTree(root2); // false
    system("pause>0");
    return 0;
}
