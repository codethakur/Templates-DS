#include "Header/ThreadBinaryTree.h"
#include<iostream>

int main()
{
    ThreadedNode* root = new ThreadedNode(10);
    
    threadedTree Tree;  
    Tree.buildThreadTree(root, 5);
    Tree.buildThreadTree(root, 15);
    Tree.buildThreadTree(root, 7);
    Tree.buildThreadTree(root, 12);

    std::cout<<"\nPreorderTraversal"<<std::endl;
    Tree.PreorderTraversal(root);

    
   
   // system("pause>0");
    return 0;
}

